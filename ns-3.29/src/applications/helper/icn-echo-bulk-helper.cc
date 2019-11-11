/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2008 INRIA
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
 * Author: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */
#include "icn-echo-bulk-helper.h"
#include "../model/icn-echo-bulk-server.h"
#include "../model/icn-echo-bulk-client.h"
#include "ns3/uinteger.h"
#include "ns3/names.h"

namespace ns3 {

IcnEchoBulkServerHelper::IcnEchoBulkServerHelper (uint16_t port)
{
  m_factory.SetTypeId (IcnEchoBulkServer::GetTypeId ());
  SetAttribute ("Port", UintegerValue (port));
}

void
IcnEchoBulkServerHelper::SetAttribute (
  std::string name,
  const AttributeValue &value)
{
  m_factory.Set (name, value);
}

ApplicationContainer
IcnEchoBulkServerHelper::Install (Ptr<Node> node) const
{
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
IcnEchoBulkServerHelper::Install (std::string nodeName) const
{
  Ptr<Node> node = Names::Find<Node> (nodeName);
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
IcnEchoBulkServerHelper::Install (NodeContainer c) const
{
  ApplicationContainer apps;
  for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
    {
      apps.Add (InstallPriv (*i));
    }

  return apps;
}

Ptr<Application>
IcnEchoBulkServerHelper::InstallPriv (Ptr<Node> node) const
{
  Ptr<Application> app = m_factory.Create<IcnEchoBulkServer> ();
  node->AddApplication (app);

  return app;
}

IcnEchoBulkClientHelper::IcnEchoBulkClientHelper (Address address, uint16_t port)
{
  m_factory.SetTypeId (IcnEchoBulkClient::GetTypeId ());
  SetAttribute ("RemoteAddress", AddressValue (address));
  SetAttribute ("RemotePort", UintegerValue (port));
}

IcnEchoBulkClientHelper::IcnEchoBulkClientHelper (Address address)
{
  m_factory.SetTypeId (IcnEchoBulkClient::GetTypeId ());
  SetAttribute ("RemoteAddress", AddressValue (address));
}

void
IcnEchoBulkClientHelper::SetAttribute (
  std::string name,
  const AttributeValue &value)
{
  m_factory.Set (name, value);
}

void
IcnEchoBulkClientHelper::SetFill (Ptr<Application> app, std::string fill)
{
  app->GetObject<IcnEchoBulkClient>()->SetFill (fill);
}

void
IcnEchoBulkClientHelper::SetFill (Ptr<Application> app, uint8_t fill, uint32_t dataLength)
{
  app->GetObject<IcnEchoBulkClient>()->SetFill (fill, dataLength);
}

void
IcnEchoBulkClientHelper::SetFill (Ptr<Application> app, uint8_t *fill, uint32_t fillLength, uint32_t dataLength)
{
  app->GetObject<IcnEchoBulkClient>()->SetFill (fill, fillLength, dataLength);
}

ApplicationContainer
IcnEchoBulkClientHelper::Install (Ptr<Node> node) const
{
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
IcnEchoBulkClientHelper::Install (std::string nodeName) const
{
  Ptr<Node> node = Names::Find<Node> (nodeName);
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
IcnEchoBulkClientHelper::Install (NodeContainer c) const
{
  ApplicationContainer apps;
  for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
    {
      apps.Add (InstallPriv (*i));
    }

  return apps;
}

Ptr<Application>
IcnEchoBulkClientHelper::InstallPriv (Ptr<Node> node) const
{
  Ptr<Application> app = m_factory.Create<IcnEchoBulkClient> ();
  node->AddApplication (app);

  return app;
}

} // namespace ns3
