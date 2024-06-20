// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interface:srv/FrameInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__FRAME_INFO__TRAITS_HPP_
#define CUSTOM_INTERFACE__SRV__DETAIL__FRAME_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interface/srv/detail/frame_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const FrameInfo_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: nframe
  {
    out << "nframe: ";
    rosidl_generator_traits::value_to_yaml(msg.nframe, out);
    out << ", ";
  }

  // member: node_id
  {
    out << "node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.node_id, out);
    out << ", ";
  }

  // member: x_coord
  {
    if (msg.x_coord.size() == 0) {
      out << "x_coord: []";
    } else {
      out << "x_coord: [";
      size_t pending_items = msg.x_coord.size();
      for (auto item : msg.x_coord) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: y_coord
  {
    if (msg.y_coord.size() == 0) {
      out << "y_coord: []";
    } else {
      out << "y_coord: [";
      size_t pending_items = msg.y_coord.size();
      for (auto item : msg.y_coord) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: classes
  {
    if (msg.classes.size() == 0) {
      out << "classes: []";
    } else {
      out << "classes: [";
      size_t pending_items = msg.classes.size();
      for (auto item : msg.classes) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: classes_confidence
  {
    if (msg.classes_confidence.size() == 0) {
      out << "classes_confidence: []";
    } else {
      out << "classes_confidence: [";
      size_t pending_items = msg.classes_confidence.size();
      for (auto item : msg.classes_confidence) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FrameInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: nframe
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nframe: ";
    rosidl_generator_traits::value_to_yaml(msg.nframe, out);
    out << "\n";
  }

  // member: node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.node_id, out);
    out << "\n";
  }

  // member: x_coord
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x_coord.size() == 0) {
      out << "x_coord: []\n";
    } else {
      out << "x_coord:\n";
      for (auto item : msg.x_coord) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: y_coord
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.y_coord.size() == 0) {
      out << "y_coord: []\n";
    } else {
      out << "y_coord:\n";
      for (auto item : msg.y_coord) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: classes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.classes.size() == 0) {
      out << "classes: []\n";
    } else {
      out << "classes:\n";
      for (auto item : msg.classes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: classes_confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.classes_confidence.size() == 0) {
      out << "classes_confidence: []\n";
    } else {
      out << "classes_confidence:\n";
      for (auto item : msg.classes_confidence) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FrameInfo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interface

namespace rosidl_generator_traits
{

[[deprecated("use custom_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interface::srv::FrameInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interface::srv::FrameInfo_Request & msg)
{
  return custom_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interface::srv::FrameInfo_Request>()
{
  return "custom_interface::srv::FrameInfo_Request";
}

template<>
inline const char * name<custom_interface::srv::FrameInfo_Request>()
{
  return "custom_interface/srv/FrameInfo_Request";
}

template<>
struct has_fixed_size<custom_interface::srv::FrameInfo_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interface::srv::FrameInfo_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interface::srv::FrameInfo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const FrameInfo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FrameInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FrameInfo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interface

namespace rosidl_generator_traits
{

[[deprecated("use custom_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interface::srv::FrameInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interface::srv::FrameInfo_Response & msg)
{
  return custom_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interface::srv::FrameInfo_Response>()
{
  return "custom_interface::srv::FrameInfo_Response";
}

template<>
inline const char * name<custom_interface::srv::FrameInfo_Response>()
{
  return "custom_interface/srv/FrameInfo_Response";
}

template<>
struct has_fixed_size<custom_interface::srv::FrameInfo_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interface::srv::FrameInfo_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interface::srv::FrameInfo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interface::srv::FrameInfo>()
{
  return "custom_interface::srv::FrameInfo";
}

template<>
inline const char * name<custom_interface::srv::FrameInfo>()
{
  return "custom_interface/srv/FrameInfo";
}

template<>
struct has_fixed_size<custom_interface::srv::FrameInfo>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interface::srv::FrameInfo_Request>::value &&
    has_fixed_size<custom_interface::srv::FrameInfo_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interface::srv::FrameInfo>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interface::srv::FrameInfo_Request>::value &&
    has_bounded_size<custom_interface::srv::FrameInfo_Response>::value
  >
{
};

template<>
struct is_service<custom_interface::srv::FrameInfo>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interface::srv::FrameInfo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interface::srv::FrameInfo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__FRAME_INFO__TRAITS_HPP_
