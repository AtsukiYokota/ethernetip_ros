#include <ethernetip_ros/communicate_data_format>

using eip_ros::CommunicateDataStructure;

// Class methods definitions

virtual size_t CommunicateDataStructure::getLength(void) const
{
  return sizeof(sequence_num);
}

virtual eip::serialization::Writer& CommunicateDataStructure::serialize(eip::serialization::Writer& writer) const
{
  writer::write(sequence_num);
  return writer;
}

virtual eip::serialization::Reader& CommunicateDataStructure::deserialize(eip::serialization::Reader& reader) const
{
  reader::read(sequence_num);
  return reader;
}
