/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright 2007 University of Washington
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ns3/log.h"
#include "ns3/ipv4-address.h"
#include "ns3/ipv6-address.h"
#include "ns3/address-utils.h"
#include "ns3/nstime.h"
#include "ns3/inet-socket-address.h"
#include "ns3/inet6-socket-address.h"
#include "ns3/socket.h"
#include "ns3/udp-socket.h"
#include "ns3/simulator.h"
#include "ns3/socket-factory.h"
#include "ns3/packet.h"
#include "ns3/uinteger.h"
#include "../model/icn-packet-header.h"
#include "icn-echo-bulk-server.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("IcnEchoBulkServerApplication");

NS_OBJECT_ENSURE_REGISTERED (IcnEchoBulkServer);

TypeId
IcnEchoBulkServer::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::IcnEchoBulkServer")
    .SetParent<Application> ()
    .SetGroupName("Applications")
    .AddConstructor<IcnEchoBulkServer> ()
    .AddAttribute ("Port", "Port on which we listen for incoming packets.",
                   UintegerValue (9),
                   MakeUintegerAccessor (&IcnEchoBulkServer::m_port),
                   MakeUintegerChecker<uint16_t> ())
    .AddTraceSource ("Rx", "A packet has been received",
                     MakeTraceSourceAccessor (&IcnEchoBulkServer::m_rxTrace),
                     "ns3::Packet::TracedCallback")
    .AddTraceSource ("RxWithAddresses", "A packet has been received",
                     MakeTraceSourceAccessor (&IcnEchoBulkServer::m_rxTraceWithAddresses),
                     "ns3::Packet::TwoAddressTracedCallback")
	.AddAttribute ("PacketSize", "Size of echo data in outbound packets",
					UintegerValue (2048),
					MakeUintegerAccessor (&IcnEchoBulkServer::m_size),
					MakeUintegerChecker<uint32_t> ())
	.AddAttribute ("DataRate", "The data rate in on state.",
					DataRateValue (DataRate ("200Mb/s")),
					MakeDataRateAccessor (&IcnEchoBulkServer::m_cbrRate),
					MakeDataRateChecker ())
	.AddAttribute ("MaxBytes",
					"The total number of bytes to send. Once these bytes are sent, "
					"no packet is sent again, even in on state. The value zero means "
					"that there is no limit.",
					UintegerValue (0),
				    MakeUintegerAccessor (&IcnEchoBulkServer::m_maxBytes),
					MakeUintegerChecker<uint64_t> ())
  ;
  return tid;
}

IcnEchoBulkServer::IcnEchoBulkServer ()
	:m_totBytes(0)
{
  NS_LOG_FUNCTION (this);
}

IcnEchoBulkServer::~IcnEchoBulkServer()
{
  NS_LOG_FUNCTION (this);
  m_socket = 0;
  m_socket6 = 0;
}

void
IcnEchoBulkServer::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
  Application::DoDispose ();
}

void
IcnEchoBulkServer::SetMaxBytes (uint64_t maxBytes)
{
  NS_LOG_FUNCTION (this << maxBytes);
  m_maxBytes = maxBytes;
}


void
IcnEchoBulkServer::StartApplication (void)
{
  NS_LOG_FUNCTION (this);

  if (m_socket == 0)
    {
      //TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");
	  TypeId tid = TypeId::LookupByName ("ns3::TcpSocketFactory");
      m_socket = Socket::CreateSocket (GetNode (), tid);
      InetSocketAddress local = InetSocketAddress (Ipv4Address::GetAny (), m_port);
      if (m_socket->Bind (local) == -1)
        {
          NS_FATAL_ERROR ("Failed to bind socket");
        }
      if (addressUtils::IsMulticast (m_local))
        {
          Ptr<UdpSocket> udpSocket = DynamicCast<UdpSocket> (m_socket);
          if (udpSocket)
            {
              // equivalent to setsockopt (MCAST_JOIN_GROUP)
              udpSocket->MulticastJoinGroup (0, m_local);
            }
          else
            {
              NS_FATAL_ERROR ("Error: Failed to join multicast group");
            }
        }
    }

  if (m_socket6 == 0)
    {
      //TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");
      TypeId tid = TypeId::LookupByName ("ns3::TcpSocketFactory");
      m_socket6 = Socket::CreateSocket (GetNode (), tid);
      Inet6SocketAddress local6 = Inet6SocketAddress (Ipv6Address::GetAny (), m_port);
      if (m_socket6->Bind (local6) == -1)
        {
          NS_FATAL_ERROR ("Failed to bind socket");
        }
      if (addressUtils::IsMulticast (local6))
        {
          Ptr<UdpSocket> udpSocket = DynamicCast<UdpSocket> (m_socket6);
          if (udpSocket)
            {
              // equivalent to setsockopt (MCAST_JOIN_GROUP)
              udpSocket->MulticastJoinGroup (0, local6);
            }
          else
            {
              NS_FATAL_ERROR ("Error: Failed to join multicast group");
            }
        }
    }

  m_socket->SetRecvCallback (MakeCallback (&IcnEchoBulkServer::HandleRead, this));
  m_socket6->SetRecvCallback (MakeCallback (&IcnEchoBulkServer::HandleRead, this));
}

void
IcnEchoBulkServer::StopApplication ()
{
  NS_LOG_FUNCTION (this);

  if (m_socket != 0)
    {
      m_socket->Close ();
      m_socket->SetRecvCallback (MakeNullCallback<void, Ptr<Socket> > ());
    }
  if (m_socket6 != 0)
    {
      m_socket6->Close ();
      m_socket6->SetRecvCallback (MakeNullCallback<void, Ptr<Socket> > ());
    }
}

void
IcnEchoBulkServer::HandleRead (Ptr<Socket> socket)
{
  NS_LOG_FUNCTION (this << socket);

  Ptr<Packet> packet;
  Address from;
  Address localAddress;
  while ((packet = socket->RecvFrom (from)))
    {
      socket->GetSockName (localAddress);
      m_rxTrace (packet);
      m_rxTraceWithAddresses (packet, from, localAddress);
      if (InetSocketAddress::IsMatchingType (from))
        {
          NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s server received " << packet->GetSize () << " bytes from " <<
                       InetSocketAddress::ConvertFrom (from).GetIpv4 () << " port " <<
                       InetSocketAddress::ConvertFrom (from).GetPort ());
        }
      else if (Inet6SocketAddress::IsMatchingType (from))
        {
          NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s server received " << packet->GetSize () << " bytes from " <<
                       Inet6SocketAddress::ConvertFrom (from).GetIpv6 () << " port " <<
                       Inet6SocketAddress::ConvertFrom (from).GetPort ());
        }

      IcnHeader icnHeader_rx;
      packet->RemoveHeader(icnHeader_rx);
      uint16_t guid_rx = icnHeader_rx.GetData();
      NS_LOG_INFO("GUID received at Echo Server = " << guid_rx);

      //uint16_t data = icnHeader.GetData();

      packet->RemoveAllPacketTags ();
      packet->RemoveAllByteTags ();

      //  packet->AddHeader(icnHeader);

      //NS_LOG_LOGIC ("Echoing packet");

      NS_LOG_LOGIC("Responding");
      Ptr<Packet> p = Create<Packet> (m_size);
      IcnHeader icnHeader_tx;
      icnHeader_tx.SetData(guid_rx);
      p->AddHeader(icnHeader_tx);

      Ptr<Packet> p1 = p->Copy();
      IcnHeader headerCheck;
      p1->RemoveHeader(headerCheck);
      uint16_t guid_tx = headerCheck.GetData();

      NS_LOG_INFO("GUID transmitted at Echo Server = " << guid_tx);

      while(m_maxBytes == 0 || m_totBytes < m_maxBytes)
      {
    	  socket->SendTo (p, 0, from);
    	  m_totBytes += p->GetSize();

    	  if (InetSocketAddress::IsMatchingType (from))
    	  {
    		  NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s server sent " << packet->GetSize () << " bytes to " <<
    				  InetSocketAddress::ConvertFrom (from).GetIpv4 () << " port " <<
					  InetSocketAddress::ConvertFrom (from).GetPort ());
    	  }
    	  else if (Inet6SocketAddress::IsMatchingType (from))
    	  {
    		  NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s server sent " << packet->GetSize () << " bytes to " <<
    				  Inet6SocketAddress::ConvertFrom (from).GetIpv6 () << " port " <<
					  Inet6SocketAddress::ConvertFrom (from).GetPort ());
    	  }
      }
      m_totBytes = 0; //clear the total number of bytes sent for another user

      //socket->SendTo (p, 0, from);

      //socket->SendTo (packet, 0, from);


    }
}


} // Namespace ns3
