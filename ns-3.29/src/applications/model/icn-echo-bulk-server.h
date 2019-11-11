#ifndef ICN_ECHO_BULK_SERVER_H
#define ICN_ECHO_BULK_SERVER_H

#include "ns3/application.h"
#include "ns3/event-id.h"
#include "ns3/ptr.h"
#include "ns3/address.h"
#include "ns3/traced-callback.h"
#include "ns3/data-rate.h"

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
class IcnEchoBulkServer : public Application
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);
  IcnEchoBulkServer ();
  virtual ~IcnEchoBulkServer ();

  void SetMaxBytes (uint64_t maxBytes);

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

  Ptr<Socket> m_socket; //!< IPv4 Socket
  Ptr<Socket> m_socket6; //!< IPv6 Socket
  Address m_local; //!< local multicast address

  /// Callbacks for tracing the packet Rx events
  TracedCallback<Ptr<const Packet> > m_rxTrace;

  /// Callbacks for tracing the packet Rx events, includes source and destination addresses
  TracedCallback<Ptr<const Packet>, const Address &, const Address &> m_rxTraceWithAddresses;

  uint64_t        m_maxBytes;     //!< Limit total number of bytes sent
  uint64_t        m_totBytes;     //!< Total bytes sent so far
  DataRate        m_cbrRate;      //!< Rate that data is generated
  EventId         m_sendEvent;    //!< Event id of pending "send packet" event

  //std::list<uint16_t, Address> m_guidAddressMap;
};

} // namespace ns3

#endif /* UDP_ECHO_SERVER_H */

