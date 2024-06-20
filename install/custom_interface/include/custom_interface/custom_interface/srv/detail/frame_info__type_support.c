// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interface:srv/FrameInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interface/srv/detail/frame_info__rosidl_typesupport_introspection_c.h"
#include "custom_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interface/srv/detail/frame_info__functions.h"
#include "custom_interface/srv/detail/frame_info__struct.h"


// Include directives for member types
// Member `x_coord`
// Member `y_coord`
// Member `classes_confidence`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `classes`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interface__srv__FrameInfo_Request__init(message_memory);
}

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_fini_function(void * message_memory)
{
  custom_interface__srv__FrameInfo_Request__fini(message_memory);
}

size_t custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__size_function__FrameInfo_Request__x_coord(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__x_coord(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__x_coord(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__fetch_function__FrameInfo_Request__x_coord(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__x_coord(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__assign_function__FrameInfo_Request__x_coord(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__x_coord(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__resize_function__FrameInfo_Request__x_coord(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__size_function__FrameInfo_Request__y_coord(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__y_coord(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__y_coord(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__fetch_function__FrameInfo_Request__y_coord(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__y_coord(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__assign_function__FrameInfo_Request__y_coord(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__y_coord(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__resize_function__FrameInfo_Request__y_coord(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__size_function__FrameInfo_Request__classes(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__classes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__classes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__fetch_function__FrameInfo_Request__classes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__classes(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__assign_function__FrameInfo_Request__classes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__classes(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__resize_function__FrameInfo_Request__classes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__size_function__FrameInfo_Request__classes_confidence(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__classes_confidence(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__classes_confidence(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__fetch_function__FrameInfo_Request__classes_confidence(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__classes_confidence(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__assign_function__FrameInfo_Request__classes_confidence(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__classes_confidence(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__resize_function__FrameInfo_Request__classes_confidence(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_message_member_array[6] = {
  {
    "nframe",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__srv__FrameInfo_Request, nframe),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__srv__FrameInfo_Request, node_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x_coord",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__srv__FrameInfo_Request, x_coord),  // bytes offset in struct
    NULL,  // default value
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__size_function__FrameInfo_Request__x_coord,  // size() function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__x_coord,  // get_const(index) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__x_coord,  // get(index) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__fetch_function__FrameInfo_Request__x_coord,  // fetch(index, &value) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__assign_function__FrameInfo_Request__x_coord,  // assign(index, value) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__resize_function__FrameInfo_Request__x_coord  // resize(index) function pointer
  },
  {
    "y_coord",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__srv__FrameInfo_Request, y_coord),  // bytes offset in struct
    NULL,  // default value
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__size_function__FrameInfo_Request__y_coord,  // size() function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__y_coord,  // get_const(index) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__y_coord,  // get(index) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__fetch_function__FrameInfo_Request__y_coord,  // fetch(index, &value) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__assign_function__FrameInfo_Request__y_coord,  // assign(index, value) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__resize_function__FrameInfo_Request__y_coord  // resize(index) function pointer
  },
  {
    "classes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__srv__FrameInfo_Request, classes),  // bytes offset in struct
    NULL,  // default value
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__size_function__FrameInfo_Request__classes,  // size() function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__classes,  // get_const(index) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__classes,  // get(index) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__fetch_function__FrameInfo_Request__classes,  // fetch(index, &value) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__assign_function__FrameInfo_Request__classes,  // assign(index, value) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__resize_function__FrameInfo_Request__classes  // resize(index) function pointer
  },
  {
    "classes_confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__srv__FrameInfo_Request, classes_confidence),  // bytes offset in struct
    NULL,  // default value
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__size_function__FrameInfo_Request__classes_confidence,  // size() function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_const_function__FrameInfo_Request__classes_confidence,  // get_const(index) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__get_function__FrameInfo_Request__classes_confidence,  // get(index) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__fetch_function__FrameInfo_Request__classes_confidence,  // fetch(index, &value) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__assign_function__FrameInfo_Request__classes_confidence,  // assign(index, value) function pointer
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__resize_function__FrameInfo_Request__classes_confidence  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_message_members = {
  "custom_interface__srv",  // message namespace
  "FrameInfo_Request",  // message name
  6,  // number of fields
  sizeof(custom_interface__srv__FrameInfo_Request),
  custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_message_member_array,  // message members
  custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_message_type_support_handle = {
  0,
  &custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interface, srv, FrameInfo_Request)() {
  if (!custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_message_type_support_handle.typesupport_identifier) {
    custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interface__srv__FrameInfo_Request__rosidl_typesupport_introspection_c__FrameInfo_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_interface/srv/detail/frame_info__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_interface/srv/detail/frame_info__functions.h"
// already included above
// #include "custom_interface/srv/detail/frame_info__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interface__srv__FrameInfo_Response__init(message_memory);
}

void custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_fini_function(void * message_memory)
{
  custom_interface__srv__FrameInfo_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__srv__FrameInfo_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_message_members = {
  "custom_interface__srv",  // message namespace
  "FrameInfo_Response",  // message name
  1,  // number of fields
  sizeof(custom_interface__srv__FrameInfo_Response),
  custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_message_member_array,  // message members
  custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_message_type_support_handle = {
  0,
  &custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interface, srv, FrameInfo_Response)() {
  if (!custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_message_type_support_handle.typesupport_identifier) {
    custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interface__srv__FrameInfo_Response__rosidl_typesupport_introspection_c__FrameInfo_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "custom_interface/srv/detail/frame_info__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers custom_interface__srv__detail__frame_info__rosidl_typesupport_introspection_c__FrameInfo_service_members = {
  "custom_interface__srv",  // service namespace
  "FrameInfo",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // custom_interface__srv__detail__frame_info__rosidl_typesupport_introspection_c__FrameInfo_Request_message_type_support_handle,
  NULL  // response message
  // custom_interface__srv__detail__frame_info__rosidl_typesupport_introspection_c__FrameInfo_Response_message_type_support_handle
};

static rosidl_service_type_support_t custom_interface__srv__detail__frame_info__rosidl_typesupport_introspection_c__FrameInfo_service_type_support_handle = {
  0,
  &custom_interface__srv__detail__frame_info__rosidl_typesupport_introspection_c__FrameInfo_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interface, srv, FrameInfo_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interface, srv, FrameInfo_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interface, srv, FrameInfo)() {
  if (!custom_interface__srv__detail__frame_info__rosidl_typesupport_introspection_c__FrameInfo_service_type_support_handle.typesupport_identifier) {
    custom_interface__srv__detail__frame_info__rosidl_typesupport_introspection_c__FrameInfo_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)custom_interface__srv__detail__frame_info__rosidl_typesupport_introspection_c__FrameInfo_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interface, srv, FrameInfo_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interface, srv, FrameInfo_Response)()->data;
  }

  return &custom_interface__srv__detail__frame_info__rosidl_typesupport_introspection_c__FrameInfo_service_type_support_handle;
}
