/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2017 University of Padova
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
 * Author: Bruno Carneiro <brunocarneirodacunha@usp.br>
 * Author: Davide Magrin <magrinda@dei.unipd.it>
 */

#include <time.h> 
#include "ns3/class-a-end-device-lorawan-mac.h"
#include "ns3/pointer.h"
#include "ns3/log.h"
#include "ns3/double.h"
#include "ns3/string.h"
#include "ns3/lora-net-device.h"
#include "ns3/lora-phy.h"
#include "crash-response.h"
#include "util/params.h"

namespace ns3 {
namespace lorawan {

NS_LOG_COMPONENT_DEFINE ("CrashResponse");

NS_OBJECT_ENSURE_REGISTERED (CrashResponse);

TypeId
CrashResponse::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::CrashResponse")
    .SetParent<Application> ()
    .AddConstructor<CrashResponse> ()
    .SetGroupName ("lorawan");
  return tid;
}

CrashResponse::CrashResponse ()
{
  NS_LOG_FUNCTION_NOARGS ();
}

CrashResponse::CrashResponse (Time sendTime)
  : m_sendTime (sendTime)
{
  NS_LOG_FUNCTION_NOARGS ();
}

CrashResponse::~CrashResponse ()
{
  NS_LOG_FUNCTION_NOARGS ();
}

void
CrashResponse::SetSendTime (Time sendTime)
{
  NS_LOG_FUNCTION (this << sendTime);

  m_sendTime = sendTime;
}

void
CrashResponse::CallEmergencyServices (void)
{
  NS_LOG_FUNCTION (this);
  srand (time(NULL));

  // Originate a new call
  CrashResponseHeader crh;
  crh.eventID = rand() % INT_MAX;
  crh.attempts = 1;
  crh.hopCount = INITIAL_HOP_COUNT;
  // Add this call to this node's own table to avoid a loop
  eventAttempts[crh.eventID] = crh.attempts;

  Broadcast(crh);
}

void
CrashResponse::HandleRead (Ptr<Packet> packet)
{
  NS_LOG_FUNCTION (this);
  CrashResponseHeader crh;
  uint32_t len = sizeof(CrashResponseHeader);
  uint8_t *buffer = (uint8_t *) malloc(len);
  packet->CopyData (buffer, len);
  memcpy(&crh, (void *) buffer, len);
  free((void *) buffer);

  PrintCrashResponse(crh);
  crh.hopCount--;
  Route(crh);
}

void
CrashResponse::PrintCrashResponse (CrashResponseHeader crh)
{
  NS_LOG_FUNCTION (this);
  NS_LOG_INFO (crh.eventID);
  NS_LOG_INFO (crh.attempts);
  NS_LOG_INFO ((uint16_t) crh.hopCount);
}

void
CrashResponse::Route (CrashResponseHeader crh)
{
  NS_LOG_FUNCTION (this);
  // We have not received this broadcast before
  if (eventAttempts[crh.eventID] == 0) {
    NS_LOG_INFO ("New broadcast");
    eventAttempts[crh.eventID] = crh.attempts;
    Broadcast(crh);
  }
  // This is a new attempt by the caller
  else if (crh.attempts > eventAttempts[crh.eventID]) {
    NS_LOG_INFO ("New attempt");
    eventAttempts[crh.eventID] = crh.attempts;
    Broadcast(crh);
  }
  // We have already retransmitted this broadcast, do nothing
  else if (crh.attempts <= eventAttempts[crh.eventID]) {
    NS_LOG_INFO ("Already broadcast");
    return;
  }
  // Message has travelled too far, do nothing
  else if (crh.hopCount == 0) {
    NS_LOG_INFO ("Hop Count equal to zero");
    return;
  }
  else NS_LOG_ERROR ("Logic Error. Unknown case!");
}

void
CrashResponse::Broadcast (CrashResponseHeader crh)
{
  NS_LOG_FUNCTION (this);
  NS_LOG_DEBUG("Broadcasting eventID: " << crh.eventID);

  uint32_t len = sizeof(CrashResponseHeader);
  const uint8_t *buffer = (const uint8_t *) malloc(len);
  memcpy((void *) buffer, &crh, len);
  Ptr<Packet> packet = Create<Packet> (buffer, len);

  m_mac->Send (packet);
  free((void *) buffer);
}

void
CrashResponse::StartApplication (void)
{
  NS_LOG_FUNCTION (this);

  // Make sure we have a MAC layer
  if (m_mac == 0)
    {
      // Assumes there's only one device
      Ptr<LoraNetDevice> loraNetDevice = m_node->GetDevice (0)->GetObject<LoraNetDevice> ();

      Ptr<LoraPhy> loraPhy = loraNetDevice->GetPhy ();
      loraPhy->SetReceiveOkCallback (MakeCallback (&CrashResponse::HandleRead, this));

      m_mac = loraNetDevice->GetMac ();
      NS_ASSERT (m_mac != 0);
    }

  // Schedule the next CallEmergencyServices event
  Simulator::Cancel (m_sendEvent);
  m_sendEvent = Simulator::Schedule (m_sendTime, &CrashResponse::CallEmergencyServices,
                                     this);
}

void
CrashResponse::StopApplication (void)
{
  NS_LOG_FUNCTION_NOARGS ();
  Simulator::Cancel (m_sendEvent);
}

}
}