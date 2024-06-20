import sys

# add the path to current package
PACKAGE_PATH = './src/main/main'
SOURCE_PATH = './src/'

sys.path.append(PACKAGE_PATH)
sys.path.append(SOURCE_PATH)


import torch
import torch.backends.cudnn as cudnn

import numpy as np

from models.experimental import attempt_load
from utils.general import check_img_size, non_max_suppression, \
    scale_coords,  set_logging, letterbox, whereIAm, xyxy2xywh
from utils.plots import plot_one_box
from utils.torch_utils import select_device, load_classifier, time_synchronized, TracedModel


import sys
import numpy as np
import os
from glob import glob

if __name__ == '__main__':
    set_logging()
    device = select_device('')
    half = False # half precision only supported on CUDA
            
        # Load model
    model = attempt_load('yolov7.pt', map_location=device)  # load FP32 model
    model.half()
    torch.save(model, './fp16yolov7.pth')
    