#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "../src/applications/model/icn-packet-header.h"
#include "../src/applications/helper/icn-request-response-helper.h"
#include "../src/applications/model/icn-echo-server.h"
#include "../src/applications/model/icn-echo-client.h"


// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1   n2   n3   n4
//    point-to-point  |    |    |    |
//                    ================
//                      LAN 10.1.2.0


using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("app2");


void
ClientTx (Ptr<const Packet> packet)
{
	Ptr<Packet> p = packet->Copy ();
	IcnHeader icnHeader;
	p->RemoveHeader(icnHeader);
	uint16_t data = icnHeader.GetData();
	//	NS_LOG_INFO ("Client has successfully transmitted a packet with GUID "
	//			<< data << ".");

	std::cout<<"Client has successfully transmitted a packet with GUID "
			<< data << " at "<< Simulator::Now().GetSeconds()<< "." << std::endl;

	//NS_LOG_INFO (" sent a packet of " << packet->GetSize () << " bytes.");
}

void
ClientRx(Ptr<const Packet> packet)
{
	Ptr<Packet> p = packet-> Copy();
	IcnHeader icnHeader;
	p->RemoveHeader(icnHeader);
	uint16_t data = icnHeader.GetData();
	//	NS_LOG_INFO ("Client has successfully transmitted a packet with GUID "
	//			<< data << ".");

	std::cout<<"Client has successfully received a packet with GUID "
			<< data << " at "<< Simulator::Now().GetSeconds()<< "." << std::endl;

	//NS_LOG_INFO (" sent a packet of " << packet->GetSize () << " bytes.");
}


void
ServerRx (Ptr<const Packet> packet)
{
	Ptr<Packet> p = packet->Copy ();
	IcnHeader icnHeader;
	p->RemoveHeader(icnHeader);
	uint16_t data = icnHeader.GetData();
	//	NS_LOG_INFO ("Server has successfully received a packet with GUID " << data<< ".");
	std::cout<<"Server has successfully received a packet with GUID " << data<< " at " << Simulator::Now().GetSeconds() << "." << std::endl;
}

int
main (int argc, char *argv[])
{
	bool verbose = true;
	uint32_t nCsma = 3;

	CommandLine cmd;
	cmd.AddValue ("nCsma", "Number of \"extra\" CSMA nodes/devices", nCsma);
	cmd.AddValue ("verbose", "Tell echo applications to log if true", verbose);

	cmd.Parse (argc,argv);
//	LogComponentEnable ("IcnEchoClientApplication", LOG_LEVEL_INFO);
//	LogComponentEnable ("IcnEchoServerApplication", LOG_LEVEL_INFO);

//	  if (verbose)
//	    {
//	      LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
//	      LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);
//	    }

	nCsma = nCsma == 0 ? 1 : nCsma;

	NodeContainer p2pNodes;
	p2pNodes.Create (2);

	NodeContainer csmaNodes;
	csmaNodes.Add (p2pNodes.Get (1));
	csmaNodes.Create (nCsma);

	PointToPointHelper pointToPoint;
	pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
	pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));

	NetDeviceContainer p2pDevices;
	p2pDevices = pointToPoint.Install (p2pNodes);

	CsmaHelper csma;
	csma.SetChannelAttribute ("DataRate", StringValue ("100Mbps"));
	csma.SetChannelAttribute ("Delay", TimeValue (NanoSeconds (6560)));

	NetDeviceContainer csmaDevices;
	csmaDevices = csma.Install (csmaNodes);

	InternetStackHelper stack;
	stack.Install (p2pNodes.Get (0));
	stack.Install (csmaNodes);

	Ipv4AddressHelper address;
	address.SetBase ("10.1.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces;
	p2pInterfaces = address.Assign (p2pDevices);

	address.SetBase ("10.1.2.0", "255.255.255.0");
	Ipv4InterfaceContainer csmaInterfaces;
	csmaInterfaces = address.Assign (csmaDevices);



	// Server is the p2p[0]
	IcnEchoServerHelper echoServer (9);
	ApplicationContainer serverApps = echoServer.Install(p2pNodes.Get(0));
	serverApps.Start(Seconds(0.0));
	Ptr<IcnEchoServer> icnServer = serverApps.Get (0)->GetObject<IcnEchoServer> ();
	icnServer->TraceConnectWithoutContext ("Rx", MakeCallback (&ServerRx));
	serverApps.Stop(Seconds(10.0));

	IcnEchoClientHelper echoClient(p2pInterfaces.GetAddress(0), 9);
	echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
	echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
	echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

	for(uint32_t i = 0; i < csmaNodes.GetN(); i++)
	{
		Ptr<ExponentialRandomVariable> var = CreateObject<ExponentialRandomVariable>();
		var->SetAttribute("Mean", DoubleValue(1));
		double startTime = var->GetValue();

		ApplicationContainer clientApps = echoClient.Install(csmaNodes.Get(i));
		clientApps.Start(Seconds(startTime));
		Ptr<IcnEchoClient> icnClient = clientApps.Get (0)->GetObject<IcnEchoClient> ();
		icnClient->TraceConnectWithoutContext ("Tx", MakeCallback (&ClientTx));
		icnClient->TraceConnectWithoutContext("Rx", MakeCallback(&ClientRx));
		clientApps.Stop(Seconds(10.0));
	}

	//  ApplicationContainer serverApps = echoServer.Install (csmaNodes.Get (nCsma));
	//  serverApps.Start (Seconds (1.0));
	//  serverApps.Stop (Seconds (10.0));

	//  UdpEchoClientHelper echoClient (csmaInterfaces.GetAddress (nCsma), 9);
	//  echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
	//  echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
	//  echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

	//  ApplicationContainer clientApps = echoClient.Install (p2pNodes.Get (0));
	//  clientApps.Start (Seconds (2.0));
	//  clientApps.Stop (Seconds (10.0));

	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

	pointToPoint.EnablePcapAll ("app2");
	csma.EnablePcapAll("app2");
	//csma.EnablePcap ("second", csmaDevices.Get (1), true);

	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}
