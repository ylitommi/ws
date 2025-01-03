// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from my_robot_interfaces:srv/StopTurtle.idl
// generated code does not contain a copyright notice

#include "my_robot_interfaces/srv/detail/stop_turtle__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
const rosidl_type_hash_t *
my_robot_interfaces__srv__StopTurtle__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1e, 0x48, 0x25, 0x7c, 0xcb, 0xf7, 0x6d, 0xd1,
      0xa7, 0x0b, 0x6e, 0x8e, 0xcb, 0xd8, 0x4a, 0x05,
      0x31, 0x00, 0x42, 0x33, 0x3f, 0xb0, 0xa5, 0x6e,
      0xf1, 0x7b, 0xa6, 0xa6, 0x98, 0xf7, 0xcf, 0x63,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
const rosidl_type_hash_t *
my_robot_interfaces__srv__StopTurtle_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x34, 0x48, 0xe1, 0x78, 0xde, 0x23, 0x59, 0x97,
      0xc4, 0xcf, 0xc4, 0x9a, 0xa1, 0x45, 0xb8, 0xb8,
      0xab, 0xb4, 0xbd, 0xe6, 0xce, 0xa4, 0xc6, 0xe6,
      0xc5, 0x4f, 0x2a, 0x4f, 0xfc, 0xf3, 0x14, 0x0d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
const rosidl_type_hash_t *
my_robot_interfaces__srv__StopTurtle_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfb, 0xa0, 0x27, 0xc9, 0x3c, 0x04, 0xa5, 0xc7,
      0x88, 0xb0, 0xd8, 0x81, 0x80, 0x26, 0x86, 0x66,
      0x80, 0x83, 0xf4, 0x80, 0xf8, 0x60, 0x9d, 0x79,
      0xa9, 0x31, 0x28, 0x33, 0x5a, 0x63, 0x93, 0x7e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
const rosidl_type_hash_t *
my_robot_interfaces__srv__StopTurtle_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2f, 0x3b, 0x6e, 0xcc, 0x32, 0x17, 0x81, 0xda,
      0x33, 0x93, 0x00, 0x4e, 0xfa, 0x75, 0x32, 0xe8,
      0x88, 0x7a, 0x1a, 0x95, 0x4e, 0x28, 0xd6, 0xf7,
      0xb2, 0x36, 0x48, 0x44, 0x09, 0xd1, 0x80, 0x7f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char my_robot_interfaces__srv__StopTurtle__TYPE_NAME[] = "my_robot_interfaces/srv/StopTurtle";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char my_robot_interfaces__srv__StopTurtle_Event__TYPE_NAME[] = "my_robot_interfaces/srv/StopTurtle_Event";
static char my_robot_interfaces__srv__StopTurtle_Request__TYPE_NAME[] = "my_robot_interfaces/srv/StopTurtle_Request";
static char my_robot_interfaces__srv__StopTurtle_Response__TYPE_NAME[] = "my_robot_interfaces/srv/StopTurtle_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char my_robot_interfaces__srv__StopTurtle__FIELD_NAME__request_message[] = "request_message";
static char my_robot_interfaces__srv__StopTurtle__FIELD_NAME__response_message[] = "response_message";
static char my_robot_interfaces__srv__StopTurtle__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field my_robot_interfaces__srv__StopTurtle__FIELDS[] = {
  {
    {my_robot_interfaces__srv__StopTurtle__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {my_robot_interfaces__srv__StopTurtle_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {my_robot_interfaces__srv__StopTurtle__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {my_robot_interfaces__srv__StopTurtle_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {my_robot_interfaces__srv__StopTurtle__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {my_robot_interfaces__srv__StopTurtle_Event__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription my_robot_interfaces__srv__StopTurtle__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {my_robot_interfaces__srv__StopTurtle_Event__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {my_robot_interfaces__srv__StopTurtle_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {my_robot_interfaces__srv__StopTurtle_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_robot_interfaces__srv__StopTurtle__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_robot_interfaces__srv__StopTurtle__TYPE_NAME, 34, 34},
      {my_robot_interfaces__srv__StopTurtle__FIELDS, 3, 3},
    },
    {my_robot_interfaces__srv__StopTurtle__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = my_robot_interfaces__srv__StopTurtle_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = my_robot_interfaces__srv__StopTurtle_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = my_robot_interfaces__srv__StopTurtle_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char my_robot_interfaces__srv__StopTurtle_Request__FIELD_NAME__activate[] = "activate";

static rosidl_runtime_c__type_description__Field my_robot_interfaces__srv__StopTurtle_Request__FIELDS[] = {
  {
    {my_robot_interfaces__srv__StopTurtle_Request__FIELD_NAME__activate, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_robot_interfaces__srv__StopTurtle_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_robot_interfaces__srv__StopTurtle_Request__TYPE_NAME, 42, 42},
      {my_robot_interfaces__srv__StopTurtle_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char my_robot_interfaces__srv__StopTurtle_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field my_robot_interfaces__srv__StopTurtle_Response__FIELDS[] = {
  {
    {my_robot_interfaces__srv__StopTurtle_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_robot_interfaces__srv__StopTurtle_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_robot_interfaces__srv__StopTurtle_Response__TYPE_NAME, 43, 43},
      {my_robot_interfaces__srv__StopTurtle_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char my_robot_interfaces__srv__StopTurtle_Event__FIELD_NAME__info[] = "info";
static char my_robot_interfaces__srv__StopTurtle_Event__FIELD_NAME__request[] = "request";
static char my_robot_interfaces__srv__StopTurtle_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field my_robot_interfaces__srv__StopTurtle_Event__FIELDS[] = {
  {
    {my_robot_interfaces__srv__StopTurtle_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {my_robot_interfaces__srv__StopTurtle_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {my_robot_interfaces__srv__StopTurtle_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {my_robot_interfaces__srv__StopTurtle_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {my_robot_interfaces__srv__StopTurtle_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription my_robot_interfaces__srv__StopTurtle_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {my_robot_interfaces__srv__StopTurtle_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {my_robot_interfaces__srv__StopTurtle_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_robot_interfaces__srv__StopTurtle_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_robot_interfaces__srv__StopTurtle_Event__TYPE_NAME, 40, 40},
      {my_robot_interfaces__srv__StopTurtle_Event__FIELDS, 3, 3},
    },
    {my_robot_interfaces__srv__StopTurtle_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = my_robot_interfaces__srv__StopTurtle_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = my_robot_interfaces__srv__StopTurtle_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool activate\n"
  "---\n"
  "string success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
my_robot_interfaces__srv__StopTurtle__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_robot_interfaces__srv__StopTurtle__TYPE_NAME, 34, 34},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 32, 32},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
my_robot_interfaces__srv__StopTurtle_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_robot_interfaces__srv__StopTurtle_Request__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
my_robot_interfaces__srv__StopTurtle_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_robot_interfaces__srv__StopTurtle_Response__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
my_robot_interfaces__srv__StopTurtle_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_robot_interfaces__srv__StopTurtle_Event__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_robot_interfaces__srv__StopTurtle__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_robot_interfaces__srv__StopTurtle__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *my_robot_interfaces__srv__StopTurtle_Event__get_individual_type_description_source(NULL);
    sources[3] = *my_robot_interfaces__srv__StopTurtle_Request__get_individual_type_description_source(NULL);
    sources[4] = *my_robot_interfaces__srv__StopTurtle_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_robot_interfaces__srv__StopTurtle_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_robot_interfaces__srv__StopTurtle_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_robot_interfaces__srv__StopTurtle_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_robot_interfaces__srv__StopTurtle_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_robot_interfaces__srv__StopTurtle_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_robot_interfaces__srv__StopTurtle_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *my_robot_interfaces__srv__StopTurtle_Request__get_individual_type_description_source(NULL);
    sources[3] = *my_robot_interfaces__srv__StopTurtle_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}