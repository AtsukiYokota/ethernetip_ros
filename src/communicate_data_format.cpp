#include <ethernetip_ros/communicate_data_format.h>

using eip_ros::CommunicateDataStructure;

// Class methods definitions

size_t CommunicateDataStructure::getLength(void) const
{
  return sizeof(sequence_num);
}

eip::serialization::Writer& CommunicateDataStructure::serialize(eip::serialization::Writer& writer) const
{
  writer.write(sequence_num);
  return writer;
}

eip::serialization::Reader& CommunicateDataStructure::deserialize(eip::serialization::Reader& reader)
{
  reader.read(sequence_num);
  return reader;
}
