#include <ethernetip_ros/simple_session.h>

using simple_session::SimpleSession;

// Class methods definitions
SimpleSession::SimpleSession(std::shared_ptr<eip::socket::Socket> socket,
                             std::shared_ptr<eip::socket::Socket> io_socket)
  : eip::Session(socket.io_socket), connection_num_(-1), sequence_num_(1)
{
}

void SimpleSession::startUDPIO(void)
{
  // o: connection originator, t: connection target
  EIP_CONNECTION_INFO_T o_to_t, t_to_o;
  // TODO:　Modify the following parameters to be appropriate for the actual machine
  o_to_t.assembly_id = 150
  o_to_t.buffer_size = 500;
  o_to_t.rpi = 10000;
  t_to_o.assembly_id = 100;
  t_to_o.buffer_size = 500;
  t_to_o.rpi = 10000;

  connection_num_ = createConnection(o_to_t, t_to_o);
  std::cout << "Opened connection with id " << connection_num_ << std::endl;
}

void SimpleSession::sendDataUDP(void)
{
  eip::CPFPacket pkt;
  std::shared_ptr<eip::SequencedAddressItem> address =
      std::make_shared<eip::SequencedAddressItem>(getConnection(connection_num_).o_to_t_connection_id, sequence_num_++);
  std::shared_ptr<eip_ros::CommunicateDataFormat> data = std::make_shared<eip_ros::CommunicateDataFormat>();
  *data = data_;
  sendIOPacket(pkt);
}

eip_ros::CommunicateDataFormat SimpleSession::reseiveDataUDP(void)
{
  eip::CPFPacket pkt = reseiveIOPacket();
  eip::SequencedAddressItem<eip_ros::CommunicateDataFormat> data;
  pkt.getItems()[1].getDataAs(data);
  return data;
}

void SimpleSession::closeActiveConnection(void)
{
  if (connection_num_ >= 0)
  {
    std::cout << "Closing connection with id " << connection_num_ << std::endl;
    closeConnection(connection_num_);
  }
}
