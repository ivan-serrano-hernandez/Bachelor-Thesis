from custom_interface.srv import FrameInfo

import rclpy
from rclpy.node import Node
import queue
import time

class ServiceNode(Node):

    def __init__(self):
        super().__init__('main_service_node')

        """
        Status variables to keep in synch the frame comparison
            - currentFrame: states the frame number that is actually being processed (or pending)
            - currentProcessingNode: states which type of node has been processed first.
                - None: yet to process both
                - 0: Main node has been already processed
                - 1: Trail node has been already processed
            - pendindMain: queue of requests for the main node
            - pendindTrail: queue of requests for the trail node
        """
        self.mainFrame = 0
        self.trailFrame = 0
        self.pendingMain = queue.Queue()
        self.pendingTrail = queue.Queue()
        self.currentFrame = 0
        # service creation
        self.srv = self.create_service(FrameInfo, 'comm', self.service_callback)

        #logfile
            # first erase contents
        with open('./traces/reviewer', "w") as file:
            pass  # Do nothing, file is truncated
        self.logfile = open('./traces/reviewer', "w")

    def service_callback(self, request, response):
        
        if request.nframe != self.currentFrame:
            # stack to corresponding queuei
            if request.node_id == 0:
                self.mainFrame +=1
                self.pendingMain.put(request)
            else:
                self.trailFrame +=1
                self.pendingTrail.put(request)

            response.success = True
            return response
        
        # current frame and requested one are the same
        if request.node_id == 0:
            # check if trail has been received
            if self.trailFrame > self.currentFrame:
                # both frames available
                otherRequest = self.pendingTrail.get()
                self.currentFrame +=1
                self.performReview(request, otherRequest)
            else:
                # only the requested frame available
                self.pendingMain.put(request)
            self.mainFrame += 1
            response.success= True
            return response
        else:
             # check if main has been received
            if self.mainFrame > self.currentFrame:
                # both frames available
                otherRequest = self.pendingMain.get() 
                self.currentFrame +=1
                self.performReview(otherRequest, request)
            else:
                # only the requested frame available
                self.pendingTrail.put(request)
            self.trailFrame += 1
            response.success= True
            return response
        
    def performReview(self, instance1, instance2):
            self.logfile.write(f'{time.time()} : frames {self.currentFrame} just processed\n')

    def __del__(self):
        self.logfile.close()



def main(args=None):
    rclpy.init(args=args)

    node_service = ServiceNode()

    rclpy.spin(node_service)
    rclpy.shutdown()


if __name__ == '__main__':
    main()