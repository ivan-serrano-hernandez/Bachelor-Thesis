import sys
import cv2
import numpy as np
import os
from glob import glob
from models import Yolov4

import tensorflow as tf
from tensorflow.python.platform import build_info as tf_build_info

import matplotlib.pyplot as plt

from predictions import predictSingleImage, export_prediction_v2, predictBatch, headOutputs
import argparse

# create argument object
parser = argparse.ArgumentParser(description='Yolo_v4 based object detection system')
parser.add_argument('arg1', type=int, choices=[0, 1, 2], help='Prediction mode. 0 for predict single image from path, 1 for raw image prediction, 2 for video prediction.')
parser.add_argument('--gpu', '-g', action='store_true', help='GPU execution')
parser.add_argument('--server', '-s', action='store_true', help='Server execution')

args = parser.parse_args()

mode = args.arg1
gpuOption = args.gpu 
serverOption = args.server

def printVersionsInfo(gpu=False):
    print("TensorFlow version: {}".format(tf.__version__))
    print("Keras version: {}".format(tf.keras.__version__))

    if (gpu):
        print("Cuda version", tf_build_info.build_info['cuda_version'])
        print("Cudnn version", tf_build_info.build_info['cudnn_version'])
        print("Num Physical GPUs Available: ", len(
            tf.config.experimental.list_physical_devices('GPU')))
        print("Num Logical GPUs Available: ", len(
            tf.config.experimental.list_logical_devices('GPU')))

printVersionsInfo(gpuOption)

# paths
FOLDER_PATH = '/home/iserran1/tfg/' if serverOption else '/home/iserran1/Documents/tfg/'
pred_result = FOLDER_PATH + 'pred_result'
pred_images = '/home/iserran1/Documents/tfg/COCO_images/'

test_annos = FOLDER_PATH + 'test_annos.txt'
pred_result_nms = FOLDER_PATH + 'pred_result_nms'

pred_groundtruths = FOLDER_PATH + 'groundtruths_LABELLED'
pred_json_nms = FOLDER_PATH + 'pred_json_nms'
pred_result_test_nms = FOLDER_PATH + 'pred_result_test_nms'
pred_videos = FOLDER_PATH + 'unlabelled_videos/'

sys.path.append(FOLDER_PATH)

# model and prediction
model = Yolov4(
    class_name_path=FOLDER_PATH + 'class_names/coco_classes.txt',
    weight_path= FOLDER_PATH + 'yolov4.weights')

import time

"""
Mode = 0:   Predict a single image (from path)
Mode = 1:   Compute prediction of a certain image
Mode = 2:   Compute prediction of a batch
"""


if mode == 0:
    # read img to predict from test_annos.txt
    with open('test_annos.txt', 'r') as file:
        img_paths = [os.path.join(pred_images, line.rstrip('\n\r')) for line in file]
        img_path = img_paths[0]
        img = cv2.imread(img_path)[:,:,::-1]

        output_img = predictSingleImage(model=model, img=img)

        plt.figure(figsize=(10,10))
        plt.imshow(output_img)
        plt.show()
elif mode == 1:
    with open('test_annos.txt', 'r') as file:
        img_paths = [os.path.join(pred_images, line.rstrip('\n\r')) for line in file]
        img_path = img_paths[0]
        img = cv2.imread(img_path)[:,:,::-1]

        batch = [img]*3

        output_img = predictBatch(model, batch)

        plt.figure(figsize=(10,10))
        plt.imshow(output_img)
        plt.show()
elif mode == 2:
    t0 = time.time()
    total_T = 0
    cap = cv2.VideoCapture('./unlabelled_videos/road_traffic.mp4') 
    
    if (cap.isOpened()== False): 
        print("Error opening video file") 
    
    # fill the batch/queue with first three frames
    batch = []
    frame_counter = 0
    while frame_counter < 3:
        ret, frame = cap.read()
        if ret:
            batch.append(headOutputs(model, frame))
            frame_counter += 1
        else:
            break
    
    # batch filled at this point
    while(cap.isOpened()): 
        

        # pop oldest and add next frame
        batch.pop(0)
        ret, frame = cap.read() 
        if ret == True:
            batch.append(headOutputs(model, frame))
            output_img = predictBatch(model, batch, frame, showImg = False)
            # cv2.imshow("frame", output_img)
            # Press Q on keyboard to exit 
            frame_counter +=1
            if cv2.waitKey(25) & 0xFF == ord('q'): 
                break

        else: 
            break

        

    t1 = time.time()
    total_T += (t1 - t0)
    
    cap.release() 
    cv2.destroyAllWindows() 

    average_fps = float(total_T)/float(frame_counter)
    print(f'Average framerate: {average_fps}\n')
