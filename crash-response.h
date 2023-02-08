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

#ifndef CRASH_RESPONSE_H
#define CRASH_RESPONSE_H

#include <limits.h>
#include "ns3/application.h"
#include "ns3/nstime.h"
#include "ns3/lorawan-mac.h"
#include "ns3/attribute.h"
#include "util/headers.h"

namespace ns3 {
namespace lorawan {

class CrashResponse : public Application
{
public:
  CrashResponse ();
  CrashResponse (Time sendTime);
  ~CrashResponse ();

  static TypeId GetTypeId (void);
  void CallEmergencyServices (void);
  void SetSendTime (Time sendTime);
  void StartApplication (void);
  void StopApplication (void);

private:
  void HandleRead(Ptr<Packet> packet);
  void Route(CrashResponseHeader crh);
  void PrintCrashResponse(CrashResponseHeader crh);
  void Broadcast(CrashResponseHeader crh);

  Time m_sendTime;
  EventId m_sendEvent;
  Ptr<LorawanMac> m_mac;
  uint8_t eventAttempts[INT_MAX];
};

} //namespace ns3

}
#endif /* CRASH_RESPONSE_H */
