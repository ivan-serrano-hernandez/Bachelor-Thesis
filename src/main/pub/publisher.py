#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image # Image is the message type

import sys
import os
# msg type
from std_msgs.msg import Bool
import time


SOURCE_PATH = './src'

class Publisher(Node):
    def __init__(self):
        
        # node name
        super().__init__('publisher')

        #logfile
            # first erase contents
        with open('./traces/publisher', "w") as self.logfile:
            pass  # Do nothing, file is truncated

        self.logfile = open('./traces/publisher', "w")

        # Image publisher with ten images
        self.publisher_ = self.create_publisher(Bool, 'framerate', 1)
        self.nframe = 0
        
        # warmup
        self.timer_firstLoad = self.create_timer(0.1, self.timer_callback_firstLoad)
        

    def timer_callback_firstLoad(self):
        # erase timer
        msg = Bool()
        msg.data = True
        self.publisher_.publish(msg)


        self.timer_firstLoad.cancel()
        time.sleep(10)
        self.warmup_timer = self.create_timer(0.8, self.timer_callback_warmup)


    def timer_callback_warmup(self):
        msg = Bool()
        msg.data = True
        self.publisher_.publish(msg)
        
        self.logfile.write(f'{time.time()} : frame {self.nframe} paced\n')
        self.nframe+=1

        if self.nframe >= 9:
            self.warmup_timer.cancel()
            self.runtimer_timer = self.create_timer((1.0/30.0), self.timer_callback)


    def timer_callback(self):

        if self.nframe >= 299:
            # get frame if ok and conver to imgms
            msg = Bool()
            msg.data = False
            self.publisher_.publish(msg)
            time.sleep(1) # give enough time to shutdown all running nodes
            sys.exit()
        else:
            # get frame if ok and conver to imgms
            msg = Bool()
            msg.data = True
            self.publisher_.publish(msg)
            
            self.logfile.write(f'{time.time()} : frame {self.nframe} paced\n')
            self.nframe+=1


def main(args=None):
    rclpy.init(args=args)
    
    publisher = Publisher()

    rclpy.spin(publisher)

    # Destroy the node explicitly
    publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
