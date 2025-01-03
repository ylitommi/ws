// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/Int64.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_robot_interfaces/msg/int64.h"


#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__INT64__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__INT64__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Int64 in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__Int64
{
  int64_t data;
} my_robot_interfaces__msg__Int64;

// Struct for a sequence of my_robot_interfaces__msg__Int64.
typedef struct my_robot_interfaces__msg__Int64__Sequence
{
  my_robot_interfaces__msg__Int64 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__Int64__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__INT64__STRUCT_H_
