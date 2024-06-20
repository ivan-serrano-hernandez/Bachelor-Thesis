import sys

# add the path to current package
PACKAGE_PATH = './src/main/main'
SOURCE_PATH = './src/'

sys.path.append(PACKAGE_PATH)
sys.path.append(SOURCE_PATH)

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image 
from cv_bridge import CvBridge
from std_msgs.msg import String


import cv2
import torch
import torch.backends.cudnn as cudnn
from numpy import random
import numpy as np

from models.experimental import attempt_load
from utils.general import check_img_size, non_max_suppression, \
    scale_coords,  set_logging, letterbox, whereIAm
from utils.plots import plot_one_box
from utils.torch_utils import select_device, load_classifier, time_synchronized, TracedModel



import numpy as np
import os
from glob import glob


import matplotlib.pyplot as plt
import argparse

import multiprocessing
import utils
import time

import rclpy
from rclpy.node import Node
from custom_interface.srv import FrameInfo

class ClientNode(Node):

    def __init__(self):
        super().__init__('main_client')
        self.cli = self.create_client(FrameInfo, 'comm')

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = FrameInfo.Request()


class Receiver(Node):
    def __init__(self):
        # create image subscriber
        super().__init__('main_instance')
        

        # intialize the model ***********************************************
        self.silent, self.imgsz = True, 640

        whereIAm(os.getpid())

            # Initialize
        set_logging()
        self.device = select_device('')
        self.half = False  # half precision only supported on CUDA

            # Load model
        self.model = attempt_load('yolov7.pt', map_location=self.device)  # load FP32 model
        self.stride = int(self.model.stride.max())  # model stride
        self.imgsz = check_img_size(self.imgsz, s=self.stride)  # check img_size

        self.model = TracedModel(self.model, self.device, self.imgsz)

        if self.half:
            self.model.half()  # to FP16

            # Get names and colors
        self.names = self.model.module.names if hasattr(self.model, 'module') else self.model.names
        self.colors = [[random.randint(0, 255) for _ in range(3)] for _ in self.names]

            # Run inference
        if self.device.type != 'cpu':
            self.model(torch.zeros(1, 3, self.imgsz, self.imgsz).to(self.device).type_as(next(self.model.parameters())))  # run once
        self.old_img_w = self.old_img_h = self.imgsz
        self.old_img_b = 1


        # create subscription to the publisher ******************************
        self.subscription = self.create_subscription(
        Image, 
        'video_frames', 
        self.listener_callback, 
        1)

        self.subscription # prevent unused variable warning
        
        # Used to convert between ROS and OpenCV images
        self.br = CvBridge()
        self.frame_counter = 0
        self.main_client = ClientNode()

        # logfile
            # first erase contents
        with open('./traces/main_subscriber', "w") as file:
            pass  # Do nothing, file is truncated
        self.logfile = open('./traces/main_subscriber', "w")



    def listener_callback(self, msg):
        self.logfile.write(f'{time.time()} : frames {self.frame_counter} just received\n')

        # Convert ROS Image message to OpenCV image
        frame = self.br.imgmsg_to_cv2(msg)
        
        img = letterbox(frame, self.imgsz, self.stride)[0]
        img = img[:, :, ::-1].transpose(2, 0, 1)  # BGR to RGB, to 3x416x416
        img = np.ascontiguousarray(img)

        # Frame formatting 
        img = torch.from_numpy(img).to(self.device)
        img = img.half() if self.half else img.float()  # uint8 to fp16/32
        img /= 255.0  # 0 - 255 to 0.0 - 1.0
        if img.ndimension() == 3:
            img = img.unsqueeze(0)

        # Warmup
        if self.device.type != 'cpu' and (self.old_img_b != img.shape[0] or self.old_img_h != img.shape[2] or self.old_img_w != img.shape[3]):
            self.old_img_b = img.shape[0]
            self.old_img_h = img.shape[2]
            self.old_img_w = img.shape[3]
            for i in range(3):
                self.model(img, augment=True)[0]

        # Inference
        with torch.no_grad():   # Calculating gradients would cause a GPU memory leak
            pred = self.model(img, augment=True)[0]

        # Non Max suppression 
        pred = non_max_suppression(pred, 0.5, 0.5, classes=None, agnostic=True)

        # Process detections and add them to current frame
        for i, det in enumerate(pred):
            im0 = frame

            gn = torch.tensor(im0.shape)[[1, 0, 1, 0]]  # normalization gain whwh
            if len(det):
                # Rescale boxes from img_size to im0 size
                det[:, :4] = scale_coords(img.shape[2:], det[:, :4], im0.shape).round()

                # Write results
                for *xyxy, conf, cls in reversed(det):
                    label = f'{self.names[int(cls)]} {conf:.2f}'
                    plot_one_box(xyxy, im0, label=label, color=self.colors[int(cls)], line_thickness=1)
            

        

        if not self.silent:
            cv2.imshow('frame', im0)
            # Press Q on keyboard to exit 
            if cv2.waitKey(25) & 0xFF == ord('q'): 
                return

        # send data to reviewer node
        self.main_client.req.nframe = self.frame_counter
        self.main_client.req.node_id = 0
        self.main_client.req.x_coord = [0.0]
        self.main_client.req.y_coord = [0.0]
        self.main_client.req.classes = ['car']
        self.main_client.req.classes_confidence = [0.9]

        main_future = self.main_client.cli.call_async(self.main_client.req)
        rclpy.spin_until_future_complete(self.main_client, main_future)

        self.logfile.write(f'{time.time()} : frame {self.frame_counter} just processed\n')
        self.frame_counter +=1
    
    def __del__(self):
        self.logfile.close()
    
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
