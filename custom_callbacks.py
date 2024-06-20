from tensorflow.python.platform import tf_logging as logging
from timeit import default_timer as timer
from tensorflow import keras
from keras.utils import io_utils
import numpy as np
from tensorflow.keras import callbacks
import math


class CosineAnnealingScheduler(callbacks.LearningRateScheduler):
    def __init__(self, epochs_per_cycle, lr_min, lr_max, verbose=0):
        super(callbacks.LearningRateScheduler, self).__init__()
        self.verbose = verbose
        self.lr_min = lr_min
        self.lr_max = lr_max
        self.epochs_per_cycle = epochs_per_cycle

    def schedule(self, epoch, lr):
        return self.lr_min + (self.lr_max - self.lr_min) *\
            (1 + math.cos(math.pi * (epoch %
             self.epochs_per_cycle) / self.epochs_per_cycle)) / 2


class custom_EarlyStopping(keras.callbacks.Callback):
    def __init__(
        self,
        monitor="val_loss",
        min_delta=0,
        patience=0,
        verbose=0,
        mode="auto",
        baseline=None,
        restore_best_weights=False,
        start_from_epoch=0,
        val_data=0,
        save_name="",
        freeze_layers="",
    ):
        super().__init__()

        self.monitor = monitor
        self.patience = patience
        self.verbose = verbose
        self.baseline = baseline
        self.min_delta = abs(min_delta)
        self.wait = 0
        self.stopped_epoch = 0
        self.restore_best_weights = restore_best_weights
        self.best_weights = None
        self.start_from_epoch = start_from_epoch

        self.starting_time = 0

        self.best_val_loss = np.Inf
        self.val_data = val_data

        self.checkpoint_number = 0

        self.batch_number_idx = 1

        self.save_name = save_name

        self.freeze_layers = freeze_layers

        if mode not in ["auto", "min", "max"]:
            logging.warning(
                "EarlyStopping mode %s is unknown, fallback to auto mode.",
                mode,
            )
            mode = "auto"

        if mode == "min":
            self.monitor_op = np.less
        elif mode == "max":
            self.monitor_op = np.greater
        else:
            if (
                self.monitor.endswith("acc")
                or self.monitor.endswith("accuracy")
                or self.monitor.endswith("auc")
            ):
                self.monitor_op = np.greater
            else:
                self.monitor_op = np.less

        if self.monitor_op == np.greater:
            self.min_delta *= 1
        else:
            self.min_delta *= -1

    def on_train_begin(self, logs=None):
        # Allow instances to be re-used
        self.wait = 0
        self.stopped_epoch = 0
        self.best = np.Inf if self.monitor_op == np.less else -np.Inf
        self.best_weights = None
        self.best_epoch = 0

        self.starting_time = timer()
        print('Starting time:', self.starting_time)

        self.prev_best = np.Inf
        self.wait_time = 0

        self.batch_number_idx = 1

        print('freeze_layers: ', self.freeze_layers)
        print('save_name: ', self.save_name)

    def on_train_batch_end_2(self, epoch, logs=None):
        print(' on_train_batch_end:')

        if (self.batch_number_idx == 10):
            self.checkpoint_number += 1

            val_output = self.model.predict_generator(self.val_data)
            # print('val_output:', val_output)

            avg_loss = 0
            current_batch_idx = 1
            for i_loss in val_output:
                if (current_batch_idx != 185):
                    avg_loss += (i_loss*16)
                else:
                    avg_loss += (i_loss*7)
                current_batch_idx += 1
            print('avg_loss:', avg_loss/2951)

            self.model.save('/gpfs/projects/bsc37/bsc37376/YOLOv4_Tensorflow_v2/models/yolo_conv_' + str(
                self.freeze_layers[0]) + '_checkpoint_' + str(self.checkpoint_number) + self.save_name)
            print('Checkpoint Saved:', self.checkpoint_number)

            self.batch_number_idx = 1

        self.batch_number_idx += 1

    def on_train_batch_end(self, epoch, logs=None):
        print(' on_train_batch_end')

        current_time = timer()

        # Check if 30mins have elapsed
        if ((current_time - self.starting_time) >= 1800):
            print('Time elapsed:', current_time - self.starting_time)

            self.starting_time = current_time

            self.checkpoint_number += 1

            # self.model.save('/gpfs/projects/bsc37/bsc37376/YOLOv4_Tensorflow_v2/models/yolo_conv_109_checkpoint_' + str(self.checkpoint_number) + '_v4')
            # print('Checkpoint Saved:', self.checkpoint_number)

            val_output = self.model.predict_generator(self.val_data)
            # print('val_output:', val_output)

            avg_loss = 0
            current_batch_idx = 1
            for i_loss in val_output:
                # if (current_batch_idx != 313):
                if (current_batch_idx != 185):
                    avg_loss += (i_loss*16)
                else:
                    # avg_loss += (i_loss*8)
                    avg_loss += (i_loss*7)
                current_batch_idx += 1
            # print('avg_loss:', avg_loss/5000)
            avg_loss = avg_loss/2951
            # avg_loss = avg_loss/5000
            print('avg_loss:', avg_loss)
            # print('avg_loss:', avg_loss/2951)

            self.model.save('/gpfs/projects/bsc37/bsc37376/YOLOv4_Tensorflow_v2/models/yolo_conv_' +
                            self.freeze_layers + '_checkpoint_' + str(self.checkpoint_number) + self.save_name)
            print('Checkpoint Saved:', self.checkpoint_number)

            # val_loss = self.model.evaluate(self.val_data)

            if (avg_loss < self.best_val_loss):
                self.best_val_loss = avg_loss
                self.wait_time = 0
                print('best_val_loss:', self.best_val_loss)
            else:
                self.wait_time += 1
                print('did not improve val_loss')

        if (self.wait_time >= self.patience):
            print('Early Stopping!!')
            self.model.stop_training = True
            # if self.restore_best_weights and self.best_weights is not None:
            # self.model.set_weights(self.best_weights)

    def on_train_end(self, logs=None):
        print('Training Done')
        # if self.stopped_epoch > 0 and self.verbose > 0:
        # io_utils.print_msg(
        #    f"Epoch {self.stopped_epoch + 1}: early stopping"
        # )

    def get_monitor_value(self, logs):
        logs = logs or {}
        monitor_value = logs.get(self.monitor)
        if monitor_value is None:
            logging.warning(
                "Early stopping conditioned on metric `%s` "
                "which is not available. Available metrics are: %s",
                self.monitor,
                ",".join(list(logs.keys())),
            )
        return monitor_value

    def _is_improvement(self, monitor_value, reference_value):
        return self.monitor_op(monitor_value - self.min_delta, reference_value)
