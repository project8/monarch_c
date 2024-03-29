/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C_NO_DEPRECATED
#define PROTOBUF_C_NO_DEPRECATED
#endif

#include "MonarchHeader.pb-c.h"
void   monarch_pb__monarch_header__init
                     (MonarchPB__MonarchHeader         *message)
{
  static MonarchPB__MonarchHeader init_value = MONARCH_PB__MONARCH_HEADER__INIT;
  *message = init_value;
}
size_t monarch_pb__monarch_header__get_packed_size
                     (const MonarchPB__MonarchHeader *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &monarch_pb__monarch_header__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t monarch_pb__monarch_header__pack
                     (const MonarchPB__MonarchHeader *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &monarch_pb__monarch_header__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t monarch_pb__monarch_header__pack_to_buffer
                     (const MonarchPB__MonarchHeader *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &monarch_pb__monarch_header__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
MonarchPB__MonarchHeader *
       monarch_pb__monarch_header__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (MonarchPB__MonarchHeader *)
     protobuf_c_message_unpack (&monarch_pb__monarch_header__descriptor,
                                allocator, len, data);
}
void   monarch_pb__monarch_header__free_unpacked
                     (MonarchPB__MonarchHeader *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &monarch_pb__monarch_header__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
const ProtobufCEnumValue monarch_pb__monarch_header__run_source__enum_values_by_number[2] =
{
  { "Mantis", "MONARCH_PB__MONARCH_HEADER__RUN_SOURCE__MANTIS", 0 },
  { "Simulation", "MONARCH_PB__MONARCH_HEADER__RUN_SOURCE__SIMULATION", 1 },
};
static const ProtobufCIntRange monarch_pb__monarch_header__run_source__value_ranges[] = {
{0, 0},{0, 2}
};
const ProtobufCEnumValueIndex monarch_pb__monarch_header__run_source__enum_values_by_name[2] =
{
  { "Mantis", 0 },
  { "Simulation", 1 },
};
const ProtobufCEnumDescriptor monarch_pb__monarch_header__run_source__descriptor =
{
  PROTOBUF_C_ENUM_DESCRIPTOR_MAGIC,
  "MonarchPB.MonarchHeader.RunSource",
  "RunSource",
  "MonarchPB__MonarchHeader__RunSource",
  "MonarchPB",
  2,
  monarch_pb__monarch_header__run_source__enum_values_by_number,
  2,
  monarch_pb__monarch_header__run_source__enum_values_by_name,
  1,
  monarch_pb__monarch_header__run_source__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
const ProtobufCEnumValue monarch_pb__monarch_header__run_type__enum_values_by_number[2] =
{
  { "Background", "MONARCH_PB__MONARCH_HEADER__RUN_TYPE__BACKGROUND", 0 },
  { "Signal", "MONARCH_PB__MONARCH_HEADER__RUN_TYPE__SIGNAL", 1 },
};
static const ProtobufCIntRange monarch_pb__monarch_header__run_type__value_ranges[] = {
{0, 0},{0, 2}
};
const ProtobufCEnumValueIndex monarch_pb__monarch_header__run_type__enum_values_by_name[2] =
{
  { "Background", 0 },
  { "Signal", 1 },
};
const ProtobufCEnumDescriptor monarch_pb__monarch_header__run_type__descriptor =
{
  PROTOBUF_C_ENUM_DESCRIPTOR_MAGIC,
  "MonarchPB.MonarchHeader.RunType",
  "RunType",
  "MonarchPB__MonarchHeader__RunType",
  "MonarchPB",
  2,
  monarch_pb__monarch_header__run_type__enum_values_by_number,
  2,
  monarch_pb__monarch_header__run_type__enum_values_by_name,
  1,
  monarch_pb__monarch_header__run_type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
char monarch_pb__monarch_header__run_date__default_value[] = "";
char monarch_pb__monarch_header__run_info__default_value[] = "";
static const ProtobufCFieldDescriptor monarch_pb__monarch_header__field_descriptors[9] =
{
  {
    "filename",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, filename),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "acqRate",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_DOUBLE,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, acqrate),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "acqMode",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, acqmode),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "acqTime",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, acqtime),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "recSize",
    5,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, recsize),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "runDate",
    6,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, rundate),
    NULL,
    &monarch_pb__monarch_header__run_date__default_value,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "runInfo",
    7,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, runinfo),
    NULL,
    &monarch_pb__monarch_header__run_info__default_value,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "runSource",
    8,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_ENUM,
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, has_runsource),
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, runsource),
    &monarch_pb__monarch_header__run_source__descriptor,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "runType",
    9,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_ENUM,
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, has_runtype),
    PROTOBUF_C_OFFSETOF(MonarchPB__MonarchHeader, runtype),
    &monarch_pb__monarch_header__run_type__descriptor,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned monarch_pb__monarch_header__field_indices_by_name[] = {
  2,   /* field[2] = acqMode */
  1,   /* field[1] = acqRate */
  3,   /* field[3] = acqTime */
  0,   /* field[0] = filename */
  4,   /* field[4] = recSize */
  5,   /* field[5] = runDate */
  6,   /* field[6] = runInfo */
  7,   /* field[7] = runSource */
  8,   /* field[8] = runType */
};
static const ProtobufCIntRange monarch_pb__monarch_header__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 9 }
};
const ProtobufCMessageDescriptor monarch_pb__monarch_header__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "MonarchPB.MonarchHeader",
  "MonarchHeader",
  "MonarchPB__MonarchHeader",
  "MonarchPB",
  sizeof(MonarchPB__MonarchHeader),
  9,
  monarch_pb__monarch_header__field_descriptors,
  monarch_pb__monarch_header__field_indices_by_name,
  1,  monarch_pb__monarch_header__number_ranges,
  (ProtobufCMessageInit) monarch_pb__monarch_header__init,
  NULL,NULL,NULL    /* reserved[123] */
};
