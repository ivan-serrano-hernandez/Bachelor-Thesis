# add the path to current package
PACKAGE_PATH = './src/main/main'
SOURCE_PATH = './src/'

import sys
sys.path.append(PACKAGE_PATH)
sys.path.append(SOURCE_PATH)



from collections import OrderedDict, namedtuple
from sensor_msgs.msg import Image
from pathlib import Path
from PIL import Image
from custom_interface.srv import FrameInfo
import time
from std_msgs.msg import Bool
from glob import glob
import os
from utils.torch_utils import select_device, load_classifier, time_synchronized, TracedModel
from utils.plots import plot_one_box
from utils.general import check_img_size, non_max_suppression, \
    scale_coords,  set_logging, letterbox, whereIAm, xyxy2xywh
from models.experimental import attempt_load
import numpy as np
from numpy import random
import torch.backends.cudnn as cudnn
import torch
import cv2
from std_msgs.msg import String
from rclpy.node import Node
import rclpy
import tensorrt as trt


class TrailClientNode(Node):
    def __init__(self):
        super().__init__('trail_client')
        self.cli = self.create_client(FrameInfo, 'comm')

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = FrameInfo.Request()


class Receiver(Node):
    def __init__(self):
        # create image subscriber
        super().__init__('trail_instance')

        # intialize the model ***********************************************
        self.declare_parameters(
            namespace='',
            parameters=[
                # Establece el valor predeterminado como False si no se proporciona
                ('half', False),
                ('silent', False),
                ('image_size', 640)
            ]
        )

        self.silent, self.imgsz = self.get_parameter(
            'silent').value, self.get_parameter('image_size').value

        whereIAm(os.getpid())

        # load the model ************************************************************************************

        w = 'yolov7-tiny-320-16.trt'
        self.device = torch.device('cuda:0')

        # Infer the engine

        Binding = namedtuple(
            'Binding', ('name', 'dtype', 'shape', 'data', 'ptr'))
        logger = trt.Logger(trt.Logger.INFO)
        trt.init_libnvinfer_plugins(logger, namespace="")
        with open(w, 'rb') as f, trt.Runtime(logger) as runtime:
            self.mymodel = runtime.deserialize_cuda_engine(f.read())

        self.bindings = OrderedDict()
        for index in range(self.mymodel.num_bindings):
            name = self.mymodel.get_binding_name(index)
            dtype = trt.nptype(self.mymodel.get_binding_dtype(index))
            shape = tuple(self.mymodel.get_binding_shape(index))
            data = torch.from_numpy(
                np.empty(shape, dtype=np.dtype(dtype))).to(self.device)
            self.bindings[name] = Binding(
                name, dtype, shape, data, int(data.data_ptr()))

        self.binding_addrs = OrderedDict((n, d.ptr)
                                         for n, d in self.bindings.items())
        self.mycontext = self.mymodel.create_execution_context()

        self.names = ['person', 'bicycle', 'car', 'motorcycle', 'airplane', 'bus', 'train', 'truck', 'boat', 'traffic light',
                      'fire hydrant', 'stop sign', 'parking meter', 'bench', 'bird', 'cat', 'dog', 'horse', 'sheep', 'cow',
                      'elephant', 'bear', 'zebra', 'giraffe', 'backpack', 'umbrella', 'handbag', 'tie', 'suitcase', 'frisbee',
                      'skis', 'snowboard', 'sports ball', 'kite', 'baseball bat', 'baseball glove', 'skateboard', 'surfboard',
                      'tennis racket', 'bottle', 'wine glass', 'cup', 'fork', 'knife', 'spoon', 'bowl', 'banana', 'apple',
                      'sandwich', 'orange', 'broccoli', 'carrot', 'hot dog', 'pizza', 'donut', 'cake', 'chair', 'couch',
                      'potted plant', 'bed', 'dining table', 'toilet', 'tv', 'laptop', 'mouse', 'remote', 'keyboard', 'cell phone',
                      'microwave', 'oven', 'toaster', 'sink', 'refrigerator', 'book', 'clock', 'vase', 'scissors', 'teddy bear',
                      'hair drier', 'toothbrush']
        self.colors = {name: [random.randint(0, 255) for _ in range(
            3)] for i, name in enumerate(self.names)}
        # warmup for 10 times
        for _ in range(10):
            tmp = torch.randn(1,3,640,640).to(self.device)
            self.binding_addrs['images'] = int(tmp.data_ptr())
            self.mycontext.execute_v2(list(self.binding_addrs.values()))

        # create subscription to the publisher ******************************
        self.subscription = self.create_subscription(
            Bool,
            'framerate',
            self.listener_callback,
            1)

        self.subscription  # prevent unused variable warning

        self.frame_counter = 0
        self.trail_client = TrailClientNode()

        # Create a VideoCapture object
        self.cap = cv2.VideoCapture(
            os.path.join(SOURCE_PATH, 'road_traffic.mp4'))

        # logfile
        # first erase contents
        with open('./traces/trail_subscriber', "w") as file:
            pass  # Do nothing, file is truncated
        self.logfile = open('./traces/trail_subscriber', "w")
        self.batch = []
        self.batchFull = False

    def letterbox(self, im, new_shape=(640, 640), color=(114, 114, 114), auto=True, scaleup=True, stride=32):
        # Resize and pad image while meeting stride-multiple constraints
        shape = im.shape[:2]  # current shape [height, width]
        if isinstance(new_shape, int):
            new_shape = (new_shape, new_shape)

        # Scale ratio (new / old)
        r = min(new_shape[0] / shape[0], new_shape[1] / shape[1])
        # only scale down, do not scale up (for better val mAP)
        if not scaleup:
            r = min(r, 1.0)

        # Compute padding
        new_unpad = int(round(shape[1] * r)), int(round(shape[0] * r))
        dw, dh = new_shape[1] - new_unpad[0], new_shape[0] - \
            new_unpad[1]  # wh padding

        if auto:  # minimum rectangle
            dw, dh = np.mod(dw, stride), np.mod(dh, stride)  # wh padding

        dw /= 2  # divide padding into 2 sides
        dh /= 2

        if shape[::-1] != new_unpad:  # resize
            im = cv2.resize(im, new_unpad, interpolation=cv2.INTER_LINEAR)
        top, bottom = int(round(dh - 0.1)), int(round(dh + 0.1))
        left, right = int(round(dw - 0.1)), int(round(dw + 0.1))
        im = cv2.copyMakeBorder(
            im, top, bottom, left, right, cv2.BORDER_CONSTANT, value=color)  # add border
        return im, r, (dw, dh)

    def postprocess(self, boxes, r, dwdh):
        dwdh = torch.tensor(dwdh*2).to(boxes.device)
        boxes -= dwdh
        boxes /= r
        return boxes

    def listener_callback(self, msg):
        if not msg.data:
            self.trail_client.req.nframe = -1

            trail_future = self.trail_client.cli.call_async(
                self.trail_client.req)
            rclpy.spin_until_future_complete(self.trail_client, trail_future)
            time.sleep(1)
            sys.exit()

        ret, frame = self.cap.read()

        if ret:
            self.logfile.write(
                f'{time.time()} : frame {self.frame_counter} pace received\n')

            # empty message request
            self.trail_client.req.x_coord = []
            self.trail_client.req.y_coord = []
            self.trail_client.req.classes = []
            self.trail_client.req.classes_confidence = []

            # Format the frame
            img = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            image = img.copy()
            image, ratio, dwdh = self.letterbox(image, auto=False)
            image = image.transpose((2, 0, 1))
            image = np.expand_dims(image, 0)
            image = np.ascontiguousarray(image)

            im = image.astype(np.float32)

            im = torch.from_numpy(im).to(self.device)
            im /= 255

            # Compute the prediction
            self.binding_addrs['images'] = int(im.data_ptr())
            self.mycontext.execute_v2(list(self.binding_addrs.values()))

            nums = self.bindings['num_dets'].data
            boxes = self.bindings['det_boxes'].data
            scores = self.bindings['det_scores'].data
            classes = self.bindings['det_classes'].data

            boxes = boxes[0, :nums[0][0]]
            scores = scores[0, :nums[0][0]]
            classes = classes[0, :nums[0][0]]

            for box, score, cl in zip(boxes, scores, classes):
                box = self.postprocess(box, ratio, dwdh).round().int()
                name = self.names[cl]
                color = self.colors[name]
                nameNconf = ' ' + str(round(float(score), 3))

                x_min, y_min, x_max, y_max = map(int, box)

                cv2.rectangle(img, (x_min, y_min),
                              (x_max, y_max), color, int(2))
                cv2.putText(img, nameNconf, (int(box[0]), int(
                    box[1]) - 2), cv2.FONT_HERSHEY_SIMPLEX, 0.75, color, thickness=2)

                self.trail_client.req.x_coord.append((x_min + x_max)/2.0)
                self.trail_client.req.y_coord.append((y_min + y_max)/2.0)
                self.trail_client.req.classes.append(name)
                self.trail_client.req.classes_confidence.append(
                    float(round(float(score), 3)))

            # send data to reviewer node only after warmup
            self.trail_client.req.node_id = 1
            self.trail_client.req.nframe = self.frame_counter

            trail_future = self.trail_client.cli.call_async(
                self.trail_client.req)
            rclpy.spin_until_future_complete(self.trail_client, trail_future)

            self.logfile.write(
                f'{time.time()} : frame {self.frame_counter} just processed\n')
        else:
            sys.exit()

        self.frame_counter += 1

    def __del__(self):
        self.logfile.close()
        sys.exit()


def main():

    rclpy.init()

    subscriber = Receiver()

    rclpy.spin(subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
