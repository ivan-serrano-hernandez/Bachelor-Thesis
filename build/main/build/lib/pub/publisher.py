#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image # Image is the message type
from cv_bridge import CvBridge
import cv2
import os
# msg type
from std_msgs.msg import String
import time


SOURCE_PATH = './src'

class Publisher(Node):
    def __init__(self):
        
        # node name
        super().__init__('publisher')

        current_directory = os.getcwd()
        print("Current directory:", current_directory)

        # Image publisher with ten images
        self.publisher_ = self.create_publisher(Image, 'video_frames', 1)
        self.nframe = 0
        # message every 0.1 seconds
        timer_period = 1.0
        self.timer = self.create_timer(timer_period, self.timer_callback)
            
        # Create a VideoCapture object
        self.cap = cv2.VideoCapture(os.path.join(SOURCE_PATH,'road_traffic.mp4'))
            
        # Used to convert between ROS and OpenCV images
        self.br = CvBridge()

        #logfile
            # first erase contents
        with open('./traces/publisher', "w") as file:
            pass  # Do nothing, file is truncated
        self.logfile = open('./traces/publisher', "w")

    def timer_callback(self):
        self.logfile.write(f'{time.time()} : frame {self.nframe} just published\n')

        ret, frame = self.cap.read()
          
        if ret == True:
            # get frame if ok and conver to imgms
            self.publisher_.publish(self.br.cv2_to_imgmsg(frame))
            self.nframe+=1
        else:
            exit()  
    
    def __del__(self):
        self.logfile.close()
        

def main(args=None):

    rclpy.init(args=args)
    time.sleep(5)
    publisher = Publisher()

    rclpy.spin(publisher)

    # Destroy the node explicitly
    publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
