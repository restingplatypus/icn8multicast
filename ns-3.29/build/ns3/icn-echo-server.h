#ifndef ICN_ECHO_SERVER_H
#define ICN_ECHO_SERVER_H

#include "ns3/application.h"
#include "ns3/event-id.h"
#include "ns3/ptr.h"
#include "ns3/address.h"
#include "ns3/traced-callback.h"

namespace ns3 {

class Socket;
class Packet;

/**
 * \ingroup applications
 * \defgroup udpecho UdpEcho
 */

/**
 * \ingroup udpecho
 * \brief A Udp Echo server
 *
 * Every packet received is sent back.
 */
class IcnEchoServer : public Application
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);
  IcnEchoServer ();
  virtual ~IcnEchoServer ();
//  void SetDataSize (uint32_t dataSize);
//  uint32_t GetDataSize (void) const;

protected:
  virtual void DoDispose (void);

private:

  virtual void StartApplication (void);
  virtual void StopApplication (void);

  /**
   * \brief Handle a packet reception.
   *
   * This function is called by lower layers.
   *
   * \param socket the socket the packet was received to.
   */
  void HandleRead (Ptr<Socket> socket);
  uint16_t m_port; //!< Port on which we listen for incoming packets.
  uint32_t m_size;
  uint32_t m_maxBytes;
  uint32_t m_totBytes;

  Ptr<Socket> m_socket; //!< IPv4 Socket
  Ptr<Socket> m_socket6; //!< IPv6 Socket
  Address m_local; //!< local multicast address

  /// Callbacks for tracing the packet Rx events
  TracedCallback<Ptr<const Packet> > m_rxTrace;

  /// Callbacks for tracing the packet Rx events, includes source and destination addresses
  TracedCallback<Ptr<const Packet>, const Address &, const Address &> m_rxTraceWithAddresses;

  //std::list<uint16_t, Address> m_guidAddressMap;
};

} // namespace ns3

#endif /* UDP_ECHO_SERVER_H */
