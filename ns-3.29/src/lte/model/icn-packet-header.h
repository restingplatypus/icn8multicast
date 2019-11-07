#ifndef ICN_PACKET_HEADER_H
#define ICN_PACKET_HEADER_H

#include <stdint.h>
#include <string>
#include "ns3/header.h"
#include "ns3/ipv4-address.h"
#include "ns3/ipv6-address.h"

namespace ns3 {

class IcnHeader : public Header
{
public:
	IcnHeader();
	virtual ~IcnHeader();

	/** Set the header data
	 *  \param data the data
	 */
	void SetData(uint16_t data);

	uint16_t GetData(void) const;

	static TypeId GetTypeId (void);
	virtual TypeId GetInstanceTypeId (void) const;
	virtual void Print (std::ostream &os) const;
	virtual void Serialize (Buffer::Iterator start) const;
	virtual uint32_t Deserialize (Buffer::Iterator start);
	virtual uint32_t GetSerializedSize (void) const;

private:
	uint16_t m_data;  //!< Header data
};
} //end of namespace ns3

#endif // ICN_PACKET_HEADER
