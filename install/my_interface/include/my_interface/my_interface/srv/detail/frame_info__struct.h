// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interface:srv/FrameInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACE__SRV__DETAIL__FRAME_INFO__STRUCT_H_
#define MY_INTERFACE__SRV__DETAIL__FRAME_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x_coord'
// Member 'y_coord'
// Member 'classes_confidence'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'classes'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/FrameInfo in the package my_interface.
typedef struct my_interface__srv__FrameInfo_Request
{
  int16_t nframe;
  /// 0 for main, 1 for trail
  int16_t node_id;
  rosidl_runtime_c__float__Sequence x_coord;
  rosidl_runtime_c__float__Sequence y_coord;
  rosidl_runtime_c__String__Sequence classes;
  rosidl_runtime_c__float__Sequence classes_confidence;
} my_interface__srv__FrameInfo_Request;

// Struct for a sequence of my_interface__srv__FrameInfo_Request.
typedef struct my_interface__srv__FrameInfo_Request__Sequence
{
  my_interface__srv__FrameInfo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interface__srv__FrameInfo_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/FrameInfo in the package my_interface.
typedef struct my_interface__srv__FrameInfo_Response
{
  bool success;
} my_interface__srv__FrameInfo_Response;

// Struct for a sequence of my_interface__srv__FrameInfo_Response.
typedef struct my_interface__srv__FrameInfo_Response__Sequence
{
  my_interface__srv__FrameInfo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interface__srv__FrameInfo_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACE__SRV__DETAIL__FRAME_INFO__STRUCT_H_
