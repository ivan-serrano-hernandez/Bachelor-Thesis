# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interface:srv/FrameInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'x_coord'
# Member 'y_coord'
# Member 'classes_confidence'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FrameInfo_Request(type):
    """Metaclass of message 'FrameInfo_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interface.srv.FrameInfo_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__frame_info__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__frame_info__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__frame_info__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__frame_info__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__frame_info__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FrameInfo_Request(metaclass=Metaclass_FrameInfo_Request):
    """Message class 'FrameInfo_Request'."""

    __slots__ = [
        '_nframe',
        '_node_id',
        '_x_coord',
        '_y_coord',
        '_classes',
        '_classes_confidence',
    ]

    _fields_and_field_types = {
        'nframe': 'int16',
        'node_id': 'int16',
        'x_coord': 'sequence<float>',
        'y_coord': 'sequence<float>',
        'classes': 'sequence<string>',
        'classes_confidence': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.nframe = kwargs.get('nframe', int())
        self.node_id = kwargs.get('node_id', int())
        self.x_coord = array.array('f', kwargs.get('x_coord', []))
        self.y_coord = array.array('f', kwargs.get('y_coord', []))
        self.classes = kwargs.get('classes', [])
        self.classes_confidence = array.array('f', kwargs.get('classes_confidence', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.nframe != other.nframe:
            return False
        if self.node_id != other.node_id:
            return False
        if self.x_coord != other.x_coord:
            return False
        if self.y_coord != other.y_coord:
            return False
        if self.classes != other.classes:
            return False
        if self.classes_confidence != other.classes_confidence:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def nframe(self):
        """Message field 'nframe'."""
        return self._nframe

    @nframe.setter
    def nframe(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'nframe' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'nframe' field must be an integer in [-32768, 32767]"
        self._nframe = value

    @builtins.property
    def node_id(self):
        """Message field 'node_id'."""
        return self._node_id

    @node_id.setter
    def node_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'node_id' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'node_id' field must be an integer in [-32768, 32767]"
        self._node_id = value

    @builtins.property
    def x_coord(self):
        """Message field 'x_coord'."""
        return self._x_coord

    @x_coord.setter
    def x_coord(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'x_coord' array.array() must have the type code of 'f'"
            self._x_coord = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'x_coord' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._x_coord = array.array('f', value)

    @builtins.property
    def y_coord(self):
        """Message field 'y_coord'."""
        return self._y_coord

    @y_coord.setter
    def y_coord(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'y_coord' array.array() must have the type code of 'f'"
            self._y_coord = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'y_coord' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._y_coord = array.array('f', value)

    @builtins.property
    def classes(self):
        """Message field 'classes'."""
        return self._classes

    @classes.setter
    def classes(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'classes' field must be a set or sequence and each value of type 'str'"
        self._classes = value

    @builtins.property
    def classes_confidence(self):
        """Message field 'classes_confidence'."""
        return self._classes_confidence

    @classes_confidence.setter
    def classes_confidence(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'classes_confidence' array.array() must have the type code of 'f'"
            self._classes_confidence = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'classes_confidence' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._classes_confidence = array.array('f', value)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FrameInfo_Response(type):
    """Metaclass of message 'FrameInfo_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interface.srv.FrameInfo_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__frame_info__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__frame_info__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__frame_info__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__frame_info__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__frame_info__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FrameInfo_Response(metaclass=Metaclass_FrameInfo_Response):
    """Message class 'FrameInfo_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_FrameInfo(type):
    """Metaclass of service 'FrameInfo'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interface.srv.FrameInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__frame_info

            from custom_interface.srv import _frame_info
            if _frame_info.Metaclass_FrameInfo_Request._TYPE_SUPPORT is None:
                _frame_info.Metaclass_FrameInfo_Request.__import_type_support__()
            if _frame_info.Metaclass_FrameInfo_Response._TYPE_SUPPORT is None:
                _frame_info.Metaclass_FrameInfo_Response.__import_type_support__()


class FrameInfo(metaclass=Metaclass_FrameInfo):
    from custom_interface.srv._frame_info import FrameInfo_Request as Request
    from custom_interface.srv._frame_info import FrameInfo_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
