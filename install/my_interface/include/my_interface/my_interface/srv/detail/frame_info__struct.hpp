// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interface:srv/FrameInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACE__SRV__DETAIL__FRAME_INFO__STRUCT_HPP_
#define MY_INTERFACE__SRV__DETAIL__FRAME_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interface__srv__FrameInfo_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_interface__srv__FrameInfo_Request __declspec(deprecated)
#endif

namespace my_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FrameInfo_Request_
{
  using Type = FrameInfo_Request_<ContainerAllocator>;

  explicit FrameInfo_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nframe = 0;
      this->node_id = 0;
    }
  }

  explicit FrameInfo_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nframe = 0;
      this->node_id = 0;
    }
  }

  // field types and members
  using _nframe_type =
    int16_t;
  _nframe_type nframe;
  using _node_id_type =
    int16_t;
  _node_id_type node_id;
  using _x_coord_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _x_coord_type x_coord;
  using _y_coord_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _y_coord_type y_coord;
  using _classes_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _classes_type classes;
  using _classes_confidence_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _classes_confidence_type classes_confidence;

  // setters for named parameter idiom
  Type & set__nframe(
    const int16_t & _arg)
  {
    this->nframe = _arg;
    return *this;
  }
  Type & set__node_id(
    const int16_t & _arg)
  {
    this->node_id = _arg;
    return *this;
  }
  Type & set__x_coord(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->x_coord = _arg;
    return *this;
  }
  Type & set__y_coord(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->y_coord = _arg;
    return *this;
  }
  Type & set__classes(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->classes = _arg;
    return *this;
  }
  Type & set__classes_confidence(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->classes_confidence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interface::srv::FrameInfo_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interface::srv::FrameInfo_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interface::srv::FrameInfo_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interface::srv::FrameInfo_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interface::srv::FrameInfo_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interface::srv::FrameInfo_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interface::srv::FrameInfo_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interface::srv::FrameInfo_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interface::srv::FrameInfo_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interface::srv::FrameInfo_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interface__srv__FrameInfo_Request
    std::shared_ptr<my_interface::srv::FrameInfo_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interface__srv__FrameInfo_Request
    std::shared_ptr<my_interface::srv::FrameInfo_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameInfo_Request_ & other) const
  {
    if (this->nframe != other.nframe) {
      return false;
    }
    if (this->node_id != other.node_id) {
      return false;
    }
    if (this->x_coord != other.x_coord) {
      return false;
    }
    if (this->y_coord != other.y_coord) {
      return false;
    }
    if (this->classes != other.classes) {
      return false;
    }
    if (this->classes_confidence != other.classes_confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrameInfo_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameInfo_Request_

// alias to use template instance with default allocator
using FrameInfo_Request =
  my_interface::srv::FrameInfo_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_interface


#ifndef _WIN32
# define DEPRECATED__my_interface__srv__FrameInfo_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_interface__srv__FrameInfo_Response __declspec(deprecated)
#endif

namespace my_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FrameInfo_Response_
{
  using Type = FrameInfo_Response_<ContainerAllocator>;

  explicit FrameInfo_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit FrameInfo_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interface::srv::FrameInfo_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interface::srv::FrameInfo_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interface::srv::FrameInfo_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interface::srv::FrameInfo_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interface::srv::FrameInfo_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interface::srv::FrameInfo_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interface::srv::FrameInfo_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interface::srv::FrameInfo_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interface::srv::FrameInfo_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interface::srv::FrameInfo_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interface__srv__FrameInfo_Response
    std::shared_ptr<my_interface::srv::FrameInfo_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interface__srv__FrameInfo_Response
    std::shared_ptr<my_interface::srv::FrameInfo_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameInfo_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrameInfo_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameInfo_Response_

// alias to use template instance with default allocator
using FrameInfo_Response =
  my_interface::srv::FrameInfo_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_interface

namespace my_interface
{

namespace srv
{

struct FrameInfo
{
  using Request = my_interface::srv::FrameInfo_Request;
  using Response = my_interface::srv::FrameInfo_Response;
};

}  // namespace srv

}  // namespace my_interface

#endif  // MY_INTERFACE__SRV__DETAIL__FRAME_INFO__STRUCT_HPP_
