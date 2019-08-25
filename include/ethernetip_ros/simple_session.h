#ifndef EIP_SIMPLE_SESSION_H
#define EIP_SIMPLE_SESSION_H

#include <memory>
#include <odva_ethernetip/session.h>
#include <odva_ethernetip/socket/socket.h>
#include <odva_ethernetip/serialization/serializable_buffer.h>
#include <odva_ethernetip/cpf_packet.h>
#include <odva_ethernetip/cpf_item.h>
#include <odva_ethernetip/sequenced_address_item.h>
#include <odva_ethernetip/sequenced_data_item.h>
#include <ethernetip_ros/communicate_data_format.h>

namespace simple_session
{
class SimpleSession : public eip::Session
{
public:
  SimpleSession(std::shared_ptr<eip::socket::Socket> socket, std::shared_ptr<eip::socket::Socket> io_socket);
  void startUDPIO(void);
  void sendDataUDP(void);
  eip_ros::CommunicateDataFormat receiveDataUDP(void);
  void closeActiveConnection(void);

private:
  // data for send to keep UDP session alive
  int connection_num_;
  eip_ros::CommunicateDataFormat data_;
  EIP_UINT sequence_num_;
};
}  // namespace simple_session

#endif  // EIP_SIMPLE_SESSION_H
