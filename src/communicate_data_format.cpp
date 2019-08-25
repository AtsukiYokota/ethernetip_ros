#include <ethernetip_ros/communicate_data_format.h>

using eip_ros::CommunicateDataFormat;

// Class methods definitions

size_t CommunicateDataFormat::getLength(void) const
{
  return sizeof(sequence_num);
}

eip::serialization::Writer& CommunicateDataFormat::serialize(eip::serialization::Writer& writer) const
{
  writer.write(sequence_num);
  return writer;
}

eip::serialization::Reader& CommunicateDataFormat::deserialize(eip::serialization::Reader& reader)
{
  reader.read(sequence_num);
  return reader;
}
