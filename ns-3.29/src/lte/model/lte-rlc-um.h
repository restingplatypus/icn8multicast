/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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
 *
 * Author: Manuel Requena <manuel.requena@cttc.es>
 */

#ifndef LTE_RLC_UM_H
#define LTE_RLC_UM_H

#include "ns3/lte-rlc-sequence-number.h"
#include "ns3/lte-rlc.h"

#include <ns3/event-id.h>
#include <map>

namespace ns3 {

/**
 * LTE RLC Unacknowledged Mode (UM), see 3GPP TS 36.322
 */
class LteRlcUm : public LteRlc
{
public:
  LteRlcUm ();
  virtual ~LteRlcUm ();
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);
  virtual void DoDispose ();

  /**
   * RLC SAP
   *
   * \param p packet
   */
  virtual void DoTransmitPdcpPdu (Ptr<Packet> p, uint64_t imsi);

  /**
   * MAC SAP
   *
   * \param bytes the number of bytes
   * \param layer the layer
   * \param harqId the HARQ ID
   * \param componentCarrierId component carrier ID
   * \param rnti the RNTI
   * \param lcid the LCID
   */
  virtual void DoNotifyTxOpportunity (uint32_t bytes, uint8_t layer, uint8_t harqId, uint8_t componentCarrierId, uint16_t rnti, uint8_t lcid);
  virtual void DoNotifyHarqDeliveryFailure ();
  virtual void DoReceivePdu (Ptr<Packet> p, uint16_t rnti, uint8_t lcid);

private:
  /// Expire reordering timer
  void ExpireReorderingTimer (void);
  /// Expire RBS timer
  void ExpireRbsTimer (void);

  /**
   * Is inside reordering window function
   *
   * \param seqNumber the sequence number
   * \returns true if inside the window
   */
  bool IsInsideReorderingWindow (SequenceNumber10 seqNumber);

  /// Reassemble outside window
  void ReassembleOutsideWindow (void);
  /**
   * Reassemble SN interval function
   *
   * \param lowSeqNumber the low sequence number
   * \param highSeqNumber the high sequence number
   */
  void ReassembleSnInterval (SequenceNumber10 lowSeqNumber, SequenceNumber10 highSeqNumber);

  /**
   * Reassemble and deliver function
   *
   * \param packet the packet
   */
  void ReassembleAndDeliver (Ptr<Packet> packet);

  /// Report buffer status
  void DoReportBufferStatus ();

private:
  uint32_t m_maxTxBufferSize; ///< maximum transmit buffer status
  uint32_t m_txBufferSize; ///< transmit buffer size
  std::vector < Ptr<Packet> > m_txBuffer;       ///< Transmission buffer
  std::map <uint16_t, Ptr<Packet> > m_rxBuffer; ///< Reception buffer
  std::vector < Ptr<Packet> > m_reasBuffer;     ///< Reassembling buffer

  std::list < Ptr<Packet> > m_sdusBuffer;       ///< List of SDUs in a packet

  /**
   * State variables. See section 7.1 in TS 36.322
   */
  SequenceNumber10 m_sequenceNumber; ///< VT(US)

  SequenceNumber10 m_vrUr;           ///< VR(UR)
  SequenceNumber10 m_vrUx;           ///< VR(UX)
  SequenceNumber10 m_vrUh;           ///< VR(UH)

  /**
   * Constants. See section 7.2 in TS 36.322
   */
  uint16_t m_windowSize; ///< windows size

  /**
   * Timers. See section 7.3 in TS 36.322
   */
  EventId m_reorderingTimer; ///< reordering timer
  EventId m_rbsTimer; ///< RBS timer

  /**
   * Reassembling state
   */
  typedef enum { NONE            = 0,
                 WAITING_S0_FULL = 1,
                 WAITING_SI_SF   = 2 } ReassemblingState_t;
  ReassemblingState_t m_reassemblingState; ///< reassembling state
  Ptr<Packet> m_keepS0; ///< keep S0

  /**
   * Expected Sequence Number
   */
  SequenceNumber10 m_expectedSeqNumber;

};


} // namespace ns3

#endif // LTE_RLC_UM_H
