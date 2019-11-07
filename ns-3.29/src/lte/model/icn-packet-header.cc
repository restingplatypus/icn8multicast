#include "icn-packet-header.h"
#include "ns3/address-utils.h"
#include "ns3/ptr.h"
#include "ns3/packet.h"
#include "ns3/header.h"
#include <iostream>

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (IcnHeader);

IcnHeader::IcnHeader()
{

}

IcnHeader::~IcnHeader()
{

}

TypeId
IcnHeader::GetTypeId()
{
	static TypeId tid = TypeId("ns3::IcnHeader")
				.SetParent<Header> ()
				.AddConstructor<IcnHeader> ()
				;
	return tid;
}

TypeId
IcnHeader::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

void
IcnHeader::Print (std::ostream &os) const
{
  // This method is invoked by the packet printing
  // routines to print the content of my header.
  //os << "data=" << m_data << std::endl;
  os << "data=" << m_data;
}

uint32_t
IcnHeader::GetSerializedSize (void) const
{
  // we reserve 2 bytes for our header.
  return 2;
}

void
IcnHeader::Serialize (Buffer::Iterator start) const
{
  // we can serialize two bytes at the start of the buffer.
  // we write them in network byte order.
  start.WriteHtonU16 (m_data);
}

uint32_t
IcnHeader::Deserialize (Buffer::Iterator start)
{
  // we can deserialize two bytes from the start of the buffer.
  // we read them in network byte order and store them
  // in host byte order.
  m_data = start.ReadNtohU16 ();

  // we return the number of bytes effectively read.
  return 2;
}

void
IcnHeader::SetData (uint16_t data)
{
  m_data = data;
}

uint16_t
IcnHeader::GetData (void) const
{
  return m_data;
}



} //end of namespace ns3
