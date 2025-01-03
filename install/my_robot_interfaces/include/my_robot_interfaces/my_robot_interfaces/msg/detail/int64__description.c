// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from my_robot_interfaces:msg/Int64.idl
// generated code does not contain a copyright notice

#include "my_robot_interfaces/msg/detail/int64__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
const rosidl_type_hash_t *
my_robot_interfaces__msg__Int64__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb6, 0x60, 0x15, 0x6e, 0x83, 0x13, 0x58, 0xc7,
      0x00, 0x11, 0xf7, 0xac, 0x42, 0x89, 0xe2, 0xdf,
      0x01, 0x34, 0x33, 0x93, 0x6c, 0x14, 0xea, 0x75,
      0x77, 0xa6, 0x5d, 0x81, 0x7a, 0x6a, 0x52, 0x0e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char my_robot_interfaces__msg__Int64__TYPE_NAME[] = "my_robot_interfaces/msg/Int64";

// Define type names, field names, and default values
static char my_robot_interfaces__msg__Int64__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field my_robot_interfaces__msg__Int64__FIELDS[] = {
  {
    {my_robot_interfaces__msg__Int64__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_robot_interfaces__msg__Int64__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_robot_interfaces__msg__Int64__TYPE_NAME, 29, 29},
      {my_robot_interfaces__msg__Int64__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
my_robot_interfaces__msg__Int64__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_robot_interfaces__msg__Int64__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 10, 10},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_robot_interfaces__msg__Int64__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_robot_interfaces__msg__Int64__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
