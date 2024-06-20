from custom_interface.srv import FrameInfo

import rclpy
from rclpy.node import Node
import queue
import time

import sys
import numpy as np
from scipy.spatial import cKDTree

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
        self.mainFrame = -1
        self.trailFrame = -1
        self.tiebreakerFrame = -1
        self.pendingMain = queue.Queue()
        self.pendingTrail = queue.Queue()
        self.pendingTiebreaker = queue.Queue()
        self.currentFrame = 0

        # service creation
        self.srv = self.create_service(FrameInfo, 'comm', self.service_callback)

        #logfile
            # first erase contents
        with open('./traces/reviewer', "w") as file:
            pass  # Do nothing, file is truncated
        self.logfile = open('./traces/reviewer', "w")

        with open('./traces/detections', "w") as file:
            pass  # Do nothing, file is truncated
        self.resfile = open('./traces/detections', "w")
        
    def processNextBatch(self, option):
        """
        option to check for other two instances:
            - 1: for main and trail
            - 2: for main and tiebreaker
            - 3: for trail and tiebreaker
        """
        if option == 1:
            return True if (self.tiebreakerFrame <= self.mainFrame and self.tiebreakerFrame <= self.trailFrame) else False
        elif option == 2:
            return True if (self.trailFrame <= self.tiebreakerFrame and self.trailFrame <= self.mainFrame) else False
        else:
            return True if (self.mainFrame <= self.tiebreakerFrame and self.mainFrame <= self.trailFrame) else False 
        


    def service_callback(self, request, response):
        # End of Processing
        if request.nframe == -1:
            self.oneToGo = True
            response.success = True
            return response

        # On current frame
        if self.currentFrame == request.nframe:
            # sync
            if request.node_id == 0:
                self.mainFrame+=1
                if self.processNextBatch(3):
                    self.performReview(request, self.pendingTrail.get(), self.pendingTiebreaker.get())
                    self.currentFrame +=1
                else:
                    # add current to queue
                    self.pendingMain.put(request)
                
            elif request.node_id == 1:
                self.trailFrame+=1
                if self.processNextBatch(2):
                    self.performReview(self.pendingMain.get(), request, self.pendingTiebreaker.get())
                    self.currentFrame +=1
                else:
                    # add current to queue
                    self.pendingTrail.put(request)
                
            else:
                self.tiebreakerFrame+=1
                if self.processNextBatch(1):
                    self.performReview(self.pendingMain.get(), self.pendingTrail.get(), request)
                    self.currentFrame +=1
                else:
                    # add current to queue
                    self.pendingTiebreaker.put(request)
                
        
        # Instance is advanced
        else:
            if request.node_id == 0:
                self.pendingMain.put(request)
                self.mainFrame+=1
            elif request.node_id == 1:
                self.pendingTrail.put(request)
                self.trailFrame+=1
            else:
                self.pendingTiebreaker.put(request)
                self.tiebreakerFrame+=1


        response.success = True
        return response
    
        
    def performReview(self, instance1, instance2, instance3):
        self.logfile.write(f'{time.time()} : frames {self.currentFrame} ready to process\n')

        numObj1 = len(instance1.classes)
        numObj2 = len(instance2.classes)
        numObj3 = len(instance3.classes)

        if (numObj1 == 0 or numObj2 == 0):
            self.logfile.write(f'{time.time()} : frames {self.currentFrame} just processed\n')
            return

        # same number of detections
        if numObj1 == numObj2:
            results = []
            pos1 = np.array([(x,y) for x,y in zip(instance1.x_coord, instance1.y_coord)])
            pos2 = np.array([(x,y) for x,y in zip(instance2.x_coord, instance2.y_coord)])
        

            tree = cKDTree(pos2)

            _, indices = tree.query(pos1)
            
            for i, (pos_i, index_i) in enumerate(zip(pos1, indices)):
                # check if same class
                if instance1.classes[i] == instance2.classes[index_i]:
                    conf_i = (instance1.classes_confidence[i] + instance2.classes_confidence[index_i])/2.0
                    results.append([instance1.classes[i], conf_i, pos_i])
                else:
                    if instance1.classes_confidence[i] > instance2.classes_confidence[index_i]:
                        results.append([instance2.classes[index_i], instance2.classes_confidence[index_i] , pos2[index_i]])
                    else:
                        results.append([instance1.classes[i], instance1.classes_confidence[i], pos_i])

            self.resfile.write(f'Detected {results} \n')

        else:
            # all instances detect different number of objects
            if len(instance1.classes)!= len(instance3.classes) and len(instance2.classes)!= len(instance3.classes):
                self.resfile.write(f'Fail safe triggered\n')
            else:
                self.resfile.write(f'Detected {numObj3} objects thanks to tiebreaker\n')

        self.logfile.write(f'{time.time()} : frames {self.currentFrame} just processed\n')

        

        self.resfile.write('\n\n')

            



    def __del__(self):
        self.logfile.close()
        self.resfile.close()


def main(args=None):
    rclpy.init(args=args)

    node_service = ServiceNode()

    rclpy.spin(node_service)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
