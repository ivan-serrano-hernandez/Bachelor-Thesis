// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interface:srv/FrameInfo.idl
// generated code does not contain a copyright notice
#include "custom_interface/srv/detail/frame_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `x_coord`
// Member `y_coord`
// Member `classes_confidence`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `classes`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_interface__srv__FrameInfo_Request__init(custom_interface__srv__FrameInfo_Request * msg)
{
  if (!msg) {
    return false;
  }
  // nframe
  // node_id
  // x_coord
  if (!rosidl_runtime_c__float__Sequence__init(&msg->x_coord, 0)) {
    custom_interface__srv__FrameInfo_Request__fini(msg);
    return false;
  }
  // y_coord
  if (!rosidl_runtime_c__float__Sequence__init(&msg->y_coord, 0)) {
    custom_interface__srv__FrameInfo_Request__fini(msg);
    return false;
  }
  // classes
  if (!rosidl_runtime_c__String__Sequence__init(&msg->classes, 0)) {
    custom_interface__srv__FrameInfo_Request__fini(msg);
    return false;
  }
  // classes_confidence
  if (!rosidl_runtime_c__float__Sequence__init(&msg->classes_confidence, 0)) {
    custom_interface__srv__FrameInfo_Request__fini(msg);
    return false;
  }
  return true;
}

void
custom_interface__srv__FrameInfo_Request__fini(custom_interface__srv__FrameInfo_Request * msg)
{
  if (!msg) {
    return;
  }
  // nframe
  // node_id
  // x_coord
  rosidl_runtime_c__float__Sequence__fini(&msg->x_coord);
  // y_coord
  rosidl_runtime_c__float__Sequence__fini(&msg->y_coord);
  // classes
  rosidl_runtime_c__String__Sequence__fini(&msg->classes);
  // classes_confidence
  rosidl_runtime_c__float__Sequence__fini(&msg->classes_confidence);
}

bool
custom_interface__srv__FrameInfo_Request__are_equal(const custom_interface__srv__FrameInfo_Request * lhs, const custom_interface__srv__FrameInfo_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // nframe
  if (lhs->nframe != rhs->nframe) {
    return false;
  }
  // node_id
  if (lhs->node_id != rhs->node_id) {
    return false;
  }
  // x_coord
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->x_coord), &(rhs->x_coord)))
  {
    return false;
  }
  // y_coord
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->y_coord), &(rhs->y_coord)))
  {
    return false;
  }
  // classes
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->classes), &(rhs->classes)))
  {
    return false;
  }
  // classes_confidence
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->classes_confidence), &(rhs->classes_confidence)))
  {
    return false;
  }
  return true;
}

bool
custom_interface__srv__FrameInfo_Request__copy(
  const custom_interface__srv__FrameInfo_Request * input,
  custom_interface__srv__FrameInfo_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // nframe
  output->nframe = input->nframe;
  // node_id
  output->node_id = input->node_id;
  // x_coord
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->x_coord), &(output->x_coord)))
  {
    return false;
  }
  // y_coord
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->y_coord), &(output->y_coord)))
  {
    return false;
  }
  // classes
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->classes), &(output->classes)))
  {
    return false;
  }
  // classes_confidence
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->classes_confidence), &(output->classes_confidence)))
  {
    return false;
  }
  return true;
}

custom_interface__srv__FrameInfo_Request *
custom_interface__srv__FrameInfo_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__srv__FrameInfo_Request * msg = (custom_interface__srv__FrameInfo_Request *)allocator.allocate(sizeof(custom_interface__srv__FrameInfo_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interface__srv__FrameInfo_Request));
  bool success = custom_interface__srv__FrameInfo_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interface__srv__FrameInfo_Request__destroy(custom_interface__srv__FrameInfo_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interface__srv__FrameInfo_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interface__srv__FrameInfo_Request__Sequence__init(custom_interface__srv__FrameInfo_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__srv__FrameInfo_Request * data = NULL;

  if (size) {
    data = (custom_interface__srv__FrameInfo_Request *)allocator.zero_allocate(size, sizeof(custom_interface__srv__FrameInfo_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interface__srv__FrameInfo_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interface__srv__FrameInfo_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interface__srv__FrameInfo_Request__Sequence__fini(custom_interface__srv__FrameInfo_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interface__srv__FrameInfo_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interface__srv__FrameInfo_Request__Sequence *
custom_interface__srv__FrameInfo_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__srv__FrameInfo_Request__Sequence * array = (custom_interface__srv__FrameInfo_Request__Sequence *)allocator.allocate(sizeof(custom_interface__srv__FrameInfo_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interface__srv__FrameInfo_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interface__srv__FrameInfo_Request__Sequence__destroy(custom_interface__srv__FrameInfo_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interface__srv__FrameInfo_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interface__srv__FrameInfo_Request__Sequence__are_equal(const custom_interface__srv__FrameInfo_Request__Sequence * lhs, const custom_interface__srv__FrameInfo_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interface__srv__FrameInfo_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interface__srv__FrameInfo_Request__Sequence__copy(
  const custom_interface__srv__FrameInfo_Request__Sequence * input,
  custom_interface__srv__FrameInfo_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interface__srv__FrameInfo_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interface__srv__FrameInfo_Request * data =
      (custom_interface__srv__FrameInfo_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interface__srv__FrameInfo_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interface__srv__FrameInfo_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interface__srv__FrameInfo_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
custom_interface__srv__FrameInfo_Response__init(custom_interface__srv__FrameInfo_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
custom_interface__srv__FrameInfo_Response__fini(custom_interface__srv__FrameInfo_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
custom_interface__srv__FrameInfo_Response__are_equal(const custom_interface__srv__FrameInfo_Response * lhs, const custom_interface__srv__FrameInfo_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
custom_interface__srv__FrameInfo_Response__copy(
  const custom_interface__srv__FrameInfo_Response * input,
  custom_interface__srv__FrameInfo_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

custom_interface__srv__FrameInfo_Response *
custom_interface__srv__FrameInfo_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__srv__FrameInfo_Response * msg = (custom_interface__srv__FrameInfo_Response *)allocator.allocate(sizeof(custom_interface__srv__FrameInfo_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interface__srv__FrameInfo_Response));
  bool success = custom_interface__srv__FrameInfo_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interface__srv__FrameInfo_Response__destroy(custom_interface__srv__FrameInfo_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interface__srv__FrameInfo_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interface__srv__FrameInfo_Response__Sequence__init(custom_interface__srv__FrameInfo_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__srv__FrameInfo_Response * data = NULL;

  if (size) {
    data = (custom_interface__srv__FrameInfo_Response *)allocator.zero_allocate(size, sizeof(custom_interface__srv__FrameInfo_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interface__srv__FrameInfo_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interface__srv__FrameInfo_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interface__srv__FrameInfo_Response__Sequence__fini(custom_interface__srv__FrameInfo_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interface__srv__FrameInfo_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interface__srv__FrameInfo_Response__Sequence *
custom_interface__srv__FrameInfo_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__srv__FrameInfo_Response__Sequence * array = (custom_interface__srv__FrameInfo_Response__Sequence *)allocator.allocate(sizeof(custom_interface__srv__FrameInfo_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interface__srv__FrameInfo_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interface__srv__FrameInfo_Response__Sequence__destroy(custom_interface__srv__FrameInfo_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interface__srv__FrameInfo_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interface__srv__FrameInfo_Response__Sequence__are_equal(const custom_interface__srv__FrameInfo_Response__Sequence * lhs, const custom_interface__srv__FrameInfo_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interface__srv__FrameInfo_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interface__srv__FrameInfo_Response__Sequence__copy(
  const custom_interface__srv__FrameInfo_Response__Sequence * input,
  custom_interface__srv__FrameInfo_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interface__srv__FrameInfo_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interface__srv__FrameInfo_Response * data =
      (custom_interface__srv__FrameInfo_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interface__srv__FrameInfo_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interface__srv__FrameInfo_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interface__srv__FrameInfo_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
