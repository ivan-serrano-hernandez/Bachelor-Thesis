import os
import sys

import cv2
import numpy as np
import tensorflow as tf
import pandas as pd
from glob import glob
from models import Yolov4

import json
from tqdm import tqdm
import matplotlib.pyplot as plt
from tensorflow.keras import layers, models, optimizers

from custom_layers import yolov4_neck, yolov4_head, nms
from utils import load_weights, get_detection_data, draw_bbox, voc_ap, draw_plot_func, read_txt_to_list
from loss import yolo_loss
from config import yolo_config

import random

# OG prediction
def export_prediction_v2(model, annotation_path, pred_folder_path, img_folder_path, bs=3):
	with open(annotation_path) as file:
		img_paths = [os.path.join(img_folder_path, line.rstrip('\n\r')) for line in file]

		for batch_idx in tqdm(range(0, len(img_paths), bs)):
			paths = img_paths[batch_idx:batch_idx+bs]
			# read and process img
			imgs = np.zeros((len(paths), *model.img_size))
			raw_img_shapes = []
			for j, path in enumerate(paths):
				print(path)
				img = cv2.imread(path)[:, :, ::-1]

				raw_img = img.copy()

				raw_img_shapes.append(img.shape)
				img = model.preprocess_img(img)

				imgs[j] = img

			# process batch output

			yolov4_output = model.yolo_model.predict(imgs)
			output = yolov4_head(yolov4_output, model.num_classes, model.anchors, model.xyscale)

			# Here you can average the output of different images
			# ...

			b_boxes, b_scores, b_classes, b_valid_detections = nms(output, model.img_size, model.num_classes, iou_threshold=0.5, score_threshold=0.5)

			b_boxes = b_boxes.numpy()
			b_scores = b_scores.numpy()
			b_classes = b_classes.numpy()
			b_valid_detections = b_valid_detections.numpy()

			for k in range(len(paths)):
				num_boxes = b_valid_detections[k]
				raw_img_shape = raw_img_shapes[k]
				boxes = b_boxes[k, :num_boxes]
				classes = b_classes[k, :num_boxes]
				scores = b_scores[k, :num_boxes]

				boxes[:, [0, 2]] = (boxes[:, [0, 2]] * raw_img_shape[1])  # w
				boxes[:, [1, 3]] = (boxes[:, [1, 3]] * raw_img_shape[0])  # h

				cls_names = [model.class_names[int(c)] for c in classes]

				img_path = paths[k]
				filename = img_path.split(os.sep)[-1].split('.')[0]
				output_path = os.path.join(pred_folder_path, filename+'.txt')
				with open(output_path, 'w') as pred_file:
					for box_idx in range(num_boxes):
						b = boxes[box_idx]
						class_id = model.class_names.index(cls_names[box_idx])
						if (class_id == 3 or class_id == 5 or class_id == 7):
							class_id = 2
						if (class_id == 0 or class_id == 2):
							if (b[2] <= 0 or b[0] >= raw_img_shape[1] or b[1] >= raw_img_shape[0] or b[3] <= 0):
								print("Coord out of range:", b[0], b[1], b[2], b[3])
							else:
								pred_file.write(f'{class_id} {scores[box_idx]} {b[0]} {b[1]} {b[2]} {b[3]}\n')


#-------------------------------------------------------------------------------------------------------------------


def headOutputs(model, frame):
	# preprocess and head output combined
	img_preprocessed = model.preprocess_img(frame)
	img_exp = np.expand_dims(img_preprocessed, axis=0)

	# yolo head output
	yolov4_output = model.yolo_model.predict(img_exp)
	return yolov4_head(yolov4_output, model.num_classes, model.anchors, model.xyscale)

"""
Batch prediction.
	pre: model, batch with raw images (f1 f2 f3)
	post: returns average prediction for the last frame (f3)
"""	
def predictBatch(model, batch, frame, showImg = False, figsize=(10,10)):
	raw_img = frame
	raw_img_shape = raw_img.shape
	
	outputs = batch[:]

	# average of the batch
	output = [None]*12

	for i in range(12):
		output[i] = (outputs[0][i] + outputs[1][i] + outputs[2][i])/3.0

	
	# Non max supression
	boxes, scores, classes, b_valid_detections = nms(output, model.img_size, model.num_classes, iou_threshold=0.5, score_threshold=0.5)

	boxes = boxes.numpy()[0]
	scores = scores.numpy()[0]
	classes = classes.numpy()[0]
	b_valid_detections = b_valid_detections.numpy()

	num_boxes = b_valid_detections[0]

	boxes[:, [0, 2]] = (boxes[:, [0, 2]] * raw_img_shape[1])  # w
	boxes[:, [1, 3]] = (boxes[:, [1, 3]] * raw_img_shape[0])  # h

	cls_names = [model.class_names[int(c)] for c in classes]
	
	# create dataframe for detections
	detections = pd.DataFrame(columns=['x1', 'y1', 'x2', 'y2', 'class_name', 'score', 'w', 'h'])

	# filter valid boxes
	valid_cnt = 0
	for box_idx in range(num_boxes):
		b = boxes[box_idx]
		class_id = model.class_names.index(cls_names[box_idx])
		if (class_id == 3 or class_id == 5 or class_id == 7):
			class_id = 2
		if (class_id == 0 or class_id == 2):
			if (b[2] <= 0 or b[0] >= raw_img_shape[1] or b[1] >= raw_img_shape[0] or b[3] <= 0):
				print("Coord out of range:", b[0], b[1], b[2], b[3])
			else:
				new_entry = {
					'x1': b[0],
					'y1': b[1],
					'x2': b[2],
					'y2': b[3],
					'class_name': model.class_names[class_id],
					'score': scores[box_idx],
					'w': b[2] - b[0],
					'h': b[3] - b[1]
				}

				# Append the new entry to the DataFrame
				detections.loc[valid_cnt, :] = new_entry
				valid_cnt +=1

	# graphical output using detections
		# int for coordinates, width and height
	detections[['x1', 'y1', 'x2', 'y2','w', 'h']] = detections[['x1', 'y1', 'x2', 'y2','w', 'h']].astype(np.int64)
	detections[['class_name']] = detections[['class_name']].astype(str)
	detections[['score']] = detections[['score']].astype(np.float64)
		
	output_img = draw_bbox(raw_img, detections, cmap=model.class_color, random_color=True, figsize=figsize,
					show_text=True, show_img=showImg)

	return output_img
	


"""
Computes prediction for a given image.
	- input: model and image
	- returns: image with predictions drawn on it
"""
def predictSingleImage(model, img, figsize=(10,10)):
	
	# preprocess image
	img_exp = np.zeros((1, *model.img_size))
	raw_img = img.copy()
	raw_img_shape = raw_img.shape
	img = model.preprocess_img(img)
	img_exp[0] = img

	# yolo head output
	yolov4_output = model.yolo_model.predict(img_exp)
	output = yolov4_head(yolov4_output, model.num_classes, model.anchors, model.xyscale)

	# Non max supression
	boxes, scores, classes, b_valid_detections = nms(output, model.img_size, model.num_classes, iou_threshold=0.5, score_threshold=0.5)

	boxes = boxes.numpy()[0]
	scores = scores.numpy()[0]
	classes = classes.numpy()[0]
	b_valid_detections = b_valid_detections.numpy()

	num_boxes = b_valid_detections[0]

	boxes[:, [0, 2]] = (boxes[:, [0, 2]] * raw_img_shape[1])  # w
	boxes[:, [1, 3]] = (boxes[:, [1, 3]] * raw_img_shape[0])  # h

	cls_names = [model.class_names[int(c)] for c in classes]
	
	# create dataframe for detections
	detections = pd.DataFrame(columns=['x1', 'y1', 'x2', 'y2', 'class_name', 'score', 'w', 'h'])

	# filter valid boxes
	valid_cnt = 0
	for box_idx in range(num_boxes):
		b = boxes[box_idx]
		class_id = model.class_names.index(cls_names[box_idx])
		if (class_id == 3 or class_id == 5 or class_id == 7):
			class_id = 2
		if (class_id == 0 or class_id == 2):
			if (b[2] <= 0 or b[0] >= raw_img_shape[1] or b[1] >= raw_img_shape[0] or b[3] <= 0):
				print("Coord out of range:", b[0], b[1], b[2], b[3])
			else:
				new_entry = {
					'x1': b[0],
					'y1': b[1],
					'x2': b[2],
					'y2': b[3],
					'class_name': model.class_names[class_id],
					'score': scores[box_idx],
					'w': b[2] - b[0],
					'h': b[3] - b[1]
				}

				# Append the new entry to the DataFrame
				detections.loc[valid_cnt, :] = new_entry
				valid_cnt +=1

	# graphical output using detections
		# int for coordinates, width and height
	detections[['x1', 'y1', 'x2', 'y2','w', 'h']] = detections[['x1', 'y1', 'x2', 'y2','w', 'h']].astype(np.int64)
	detections[['class_name']] = detections[['class_name']].astype(str)
	detections[['score']] = detections[['score']].astype(np.float64)
	print(detections)
	print(detections.info())
		
	output_img = draw_bbox(raw_img, detections, cmap=model.class_color, random_color=True, figsize=figsize,
					show_text=True, show_img=False)
	
	return output_img
			
"""
Complete prediction for single image, with no average for batch
	input: path to image, annotation path, path to file to write output
	pre:
	post: writes result in output path, returns image and optionally shows it
"""
def predictSingleImageFromPath(model, annotation_path, pred_folder_path, img_folder_path, bs=1,figsize=(10,10)):
	with open(annotation_path) as file:
		img_paths = [os.path.join(img_folder_path, line.rstrip('\n\r')) for line in file]

		for batch_idx in tqdm(range(0, len(img_paths), bs)):
			paths = img_paths[batch_idx:batch_idx+bs]
			# read and process img
			imgs = np.zeros((len(paths), *model.img_size))
			raw_img_shapes = []
			for j, path in enumerate(paths):
				print(path)
				img = cv2.imread(path)[:, :, ::-1]

				raw_img = img.copy()

				raw_img_shapes.append(img.shape)
				img = model.preprocess_img(img)

				imgs[j] = img

			# process batch output

			yolov4_output = model.yolo_model.predict(imgs)
			output = yolov4_head(yolov4_output, model.num_classes, model.anchors, model.xyscale)

			# No need for average

			b_boxes, b_scores, b_classes, b_valid_detections = nms(output, model.img_size, model.num_classes, iou_threshold=0.5, score_threshold=0.5)

			b_boxes = b_boxes.numpy()
			b_scores = b_scores.numpy()
			b_classes = b_classes.numpy()
			b_valid_detections = b_valid_detections.numpy()

			for k in range(len(paths)):
				num_boxes = b_valid_detections[k]
				raw_img_shape = raw_img_shapes[k]
				boxes = b_boxes[k, :num_boxes]
				classes = b_classes[k, :num_boxes]
				scores = b_scores[k, :num_boxes]

				boxes[:, [0, 2]] = (boxes[:, [0, 2]] * raw_img_shape[1])  # w
				boxes[:, [1, 3]] = (boxes[:, [1, 3]] * raw_img_shape[0])  # h

				cls_names = [model.class_names[int(c)] for c in classes]
				
				# create dataframe for detections
				detections = pd.DataFrame(columns=['x1', 'y1', 'x2', 'y2', 'class_name', 'score', 'w', 'h'])

				# write result to file
				valid_cnt = 0
				img_path = paths[k]
				filename = img_path.split(os.sep)[-1].split('.')[0]
				output_path = os.path.join(pred_folder_path, filename+'.txt')
				with open(output_path, 'w') as pred_file:
					for box_idx in range(num_boxes):
						b = boxes[box_idx]
						class_id = model.class_names.index(cls_names[box_idx])
						if (class_id == 3 or class_id == 5 or class_id == 7):
							class_id = 2
						if (class_id == 0 or class_id == 2):
							if (b[2] <= 0 or b[0] >= raw_img_shape[1] or b[1] >= raw_img_shape[0] or b[3] <= 0):
								print("Coord out of range:", b[0], b[1], b[2], b[3])
							else:
								new_entry = {
									'x1': b[0],
									'y1': b[1],
									'x2': b[2],
									'y2': b[3],
									'class_name': model.class_names[class_id],
									'score': scores[box_idx],
									'w': b[2] - b[0],
									'h': b[3] - b[1]
								}

								# Append the new entry to the DataFrame
								detections.loc[valid_cnt, :] = new_entry
								valid_cnt +=1
								pred_file.write(f'{class_id} {scores[box_idx]} {b[0]} {b[1]} {b[2]} {b[3]}\n')

				# graphical output using detections
					# int for coordinates, width and height
				detections[['x1', 'y1', 'x2', 'y2','w', 'h']] = detections[['x1', 'y1', 'x2', 'y2','w', 'h']].astype(np.int64)
				detections[['class_name']] = detections[['class_name']].astype(str)
				detections[['score']] = detections[['score']].astype(np.float64)
				print(detections)
				print(detections.info())
					
				output_img = draw_bbox(raw_img, detections, cmap=model.class_color, random_color=True, figsize=figsize,
                               show_text=True, show_img=True)
				
				return output_img
			
	
