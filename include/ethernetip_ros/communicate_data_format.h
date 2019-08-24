#ifndef EIP_COMMUNICATE_DATA_FORMAT_H
#define EIP_COMMUNICATE_DATA_FORMAT_H

#include <odva_ethernetip/eip_types.h>
#include <odva_ethernetip/serialization/reader.h>
#include <odva_ethernetip/serialization/writer.h>
#include <odva_ethernetip/serialization/serializable.h>

namespace eip_ros
{
class CommunicateDataStructure : public eip::serialization::Serializable
{
public:
  EIP_UINT sequence_num;

  virtual size_t getLength(void) const;
  virtual eip::serialization::Writer& serialize(eip::serialization::Writer& writer) const;
  virtual eip::serialization::Reader& deserialize(eip::serialization::Reader& reader) const;
};
}  // namespace eip_ros

#endif  // EIP_COMMUNICATE_DATA_FORMAT_H
