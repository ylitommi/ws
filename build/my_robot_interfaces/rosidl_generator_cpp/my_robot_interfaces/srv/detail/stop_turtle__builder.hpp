// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:srv/StopTurtle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/srv/stop_turtle.hpp"


#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__STOP_TURTLE__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__STOP_TURTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/srv/detail/stop_turtle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_StopTurtle_Request_activate
{
public:
  Init_StopTurtle_Request_activate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::srv::StopTurtle_Request activate(::my_robot_interfaces::srv::StopTurtle_Request::_activate_type arg)
  {
    msg_.activate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::StopTurtle_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::StopTurtle_Request>()
{
  return my_robot_interfaces::srv::builder::Init_StopTurtle_Request_activate();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_StopTurtle_Response_success
{
public:
  Init_StopTurtle_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::srv::StopTurtle_Response success(::my_robot_interfaces::srv::StopTurtle_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::StopTurtle_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::StopTurtle_Response>()
{
  return my_robot_interfaces::srv::builder::Init_StopTurtle_Response_success();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_StopTurtle_Event_response
{
public:
  explicit Init_StopTurtle_Event_response(::my_robot_interfaces::srv::StopTurtle_Event & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::StopTurtle_Event response(::my_robot_interfaces::srv::StopTurtle_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::StopTurtle_Event msg_;
};

class Init_StopTurtle_Event_request
{
public:
  explicit Init_StopTurtle_Event_request(::my_robot_interfaces::srv::StopTurtle_Event & msg)
  : msg_(msg)
  {}
  Init_StopTurtle_Event_response request(::my_robot_interfaces::srv::StopTurtle_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_StopTurtle_Event_response(msg_);
  }

private:
  ::my_robot_interfaces::srv::StopTurtle_Event msg_;
};

class Init_StopTurtle_Event_info
{
public:
  Init_StopTurtle_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StopTurtle_Event_request info(::my_robot_interfaces::srv::StopTurtle_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_StopTurtle_Event_request(msg_);
  }

private:
  ::my_robot_interfaces::srv::StopTurtle_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::StopTurtle_Event>()
{
  return my_robot_interfaces::srv::builder::Init_StopTurtle_Event_info();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__STOP_TURTLE__BUILDER_HPP_
