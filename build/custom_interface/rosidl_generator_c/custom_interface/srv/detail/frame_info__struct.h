// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interface:srv/FrameInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__FRAME_INFO__STRUCT_H_
#define CUSTOM_INTERFACE__SRV__DETAIL__FRAME_INFO__STRUCT_H_

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

/// Struct defined in srv/FrameInfo in the package custom_interface.
typedef struct custom_interface__srv__FrameInfo_Request
{
  int16_t nframe;
  /// 0 for main, 1 for trail
  int16_t node_id;
  rosidl_runtime_c__float__Sequence x_coord;
  rosidl_runtime_c__float__Sequence y_coord;
  rosidl_runtime_c__String__Sequence classes;
  rosidl_runtime_c__float__Sequence classes_confidence;
} custom_interface__srv__FrameInfo_Request;

// Struct for a sequence of custom_interface__srv__FrameInfo_Request.
typedef struct custom_interface__srv__FrameInfo_Request__Sequence
{
  custom_interface__srv__FrameInfo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__FrameInfo_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/FrameInfo in the package custom_interface.
typedef struct custom_interface__srv__FrameInfo_Response
{
  bool success;
} custom_interface__srv__FrameInfo_Response;

// Struct for a sequence of custom_interface__srv__FrameInfo_Response.
typedef struct custom_interface__srv__FrameInfo_Response__Sequence
{
  custom_interface__srv__FrameInfo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__FrameInfo_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__FRAME_INFO__STRUCT_H_
