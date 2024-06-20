// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interface:srv/FrameInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACE__SRV__DETAIL__FRAME_INFO__BUILDER_HPP_
#define MY_INTERFACE__SRV__DETAIL__FRAME_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interface/srv/detail/frame_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interface
{

namespace srv
{

namespace builder
{

class Init_FrameInfo_Request_classes_confidence
{
public:
  explicit Init_FrameInfo_Request_classes_confidence(::my_interface::srv::FrameInfo_Request & msg)
  : msg_(msg)
  {}
  ::my_interface::srv::FrameInfo_Request classes_confidence(::my_interface::srv::FrameInfo_Request::_classes_confidence_type arg)
  {
    msg_.classes_confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interface::srv::FrameInfo_Request msg_;
};

class Init_FrameInfo_Request_classes
{
public:
  explicit Init_FrameInfo_Request_classes(::my_interface::srv::FrameInfo_Request & msg)
  : msg_(msg)
  {}
  Init_FrameInfo_Request_classes_confidence classes(::my_interface::srv::FrameInfo_Request::_classes_type arg)
  {
    msg_.classes = std::move(arg);
    return Init_FrameInfo_Request_classes_confidence(msg_);
  }

private:
  ::my_interface::srv::FrameInfo_Request msg_;
};

class Init_FrameInfo_Request_y_coord
{
public:
  explicit Init_FrameInfo_Request_y_coord(::my_interface::srv::FrameInfo_Request & msg)
  : msg_(msg)
  {}
  Init_FrameInfo_Request_classes y_coord(::my_interface::srv::FrameInfo_Request::_y_coord_type arg)
  {
    msg_.y_coord = std::move(arg);
    return Init_FrameInfo_Request_classes(msg_);
  }

private:
  ::my_interface::srv::FrameInfo_Request msg_;
};

class Init_FrameInfo_Request_x_coord
{
public:
  explicit Init_FrameInfo_Request_x_coord(::my_interface::srv::FrameInfo_Request & msg)
  : msg_(msg)
  {}
  Init_FrameInfo_Request_y_coord x_coord(::my_interface::srv::FrameInfo_Request::_x_coord_type arg)
  {
    msg_.x_coord = std::move(arg);
    return Init_FrameInfo_Request_y_coord(msg_);
  }

private:
  ::my_interface::srv::FrameInfo_Request msg_;
};

class Init_FrameInfo_Request_node_id
{
public:
  explicit Init_FrameInfo_Request_node_id(::my_interface::srv::FrameInfo_Request & msg)
  : msg_(msg)
  {}
  Init_FrameInfo_Request_x_coord node_id(::my_interface::srv::FrameInfo_Request::_node_id_type arg)
  {
    msg_.node_id = std::move(arg);
    return Init_FrameInfo_Request_x_coord(msg_);
  }

private:
  ::my_interface::srv::FrameInfo_Request msg_;
};

class Init_FrameInfo_Request_nframe
{
public:
  Init_FrameInfo_Request_nframe()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FrameInfo_Request_node_id nframe(::my_interface::srv::FrameInfo_Request::_nframe_type arg)
  {
    msg_.nframe = std::move(arg);
    return Init_FrameInfo_Request_node_id(msg_);
  }

private:
  ::my_interface::srv::FrameInfo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interface::srv::FrameInfo_Request>()
{
  return my_interface::srv::builder::Init_FrameInfo_Request_nframe();
}

}  // namespace my_interface


namespace my_interface
{

namespace srv
{

namespace builder
{

class Init_FrameInfo_Response_success
{
public:
  Init_FrameInfo_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interface::srv::FrameInfo_Response success(::my_interface::srv::FrameInfo_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interface::srv::FrameInfo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interface::srv::FrameInfo_Response>()
{
  return my_interface::srv::builder::Init_FrameInfo_Response_success();
}

}  // namespace my_interface

#endif  // MY_INTERFACE__SRV__DETAIL__FRAME_INFO__BUILDER_HPP_
