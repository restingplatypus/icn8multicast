#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "../src/applications/model/icn-packet-header.h"
#include "../src/applications/helper/icn-request-response-helper.h"
#include "../src/applications/model/icn-echo-server.h"
#include "../src/applications/model/icn-echo-client.h"


using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("app1");


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
			<< data << "." << std::endl;

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
	std::cout<<"Server has successfully received a packet with GUID " << data<< "." << std::endl;
}

int
main (int argc, char *argv[])
{
	double simTimeSec = 300;
	CommandLine cmd;
	cmd.AddValue ("SimulationTime", "Length of simulation in seconds.", simTimeSec);
	cmd.Parse (argc, argv);

	//LogComponentEnable ("App1", LOG_INFO);

	NodeContainer nodes;
	nodes.Create (2);

	PointToPointHelper pointToPoint;
	pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
	pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));

	NetDeviceContainer devices;
	devices = pointToPoint.Install (nodes);

	InternetStackHelper stack;
	stack.Install (nodes);

	Ipv4AddressHelper address;
	address.SetBase ("10.1.1.0", "255.255.255.0");

	Ipv4InterfaceContainer interfaces = address.Assign (devices);

	IcnEchoServerHelper echoServer (9);
	ApplicationContainer serverApps = echoServer.Install (nodes.Get (1));
	serverApps.Start (Seconds (1.0));
	Ptr<IcnEchoServer> icnServer = serverApps.Get (0)->GetObject<IcnEchoServer> ();
	icnServer->TraceConnectWithoutContext ("Rx", MakeCallback (&ServerRx));
	serverApps.Stop (Seconds (10.0));

	IcnEchoClientHelper echoClient (interfaces.GetAddress (1), 9);
	echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
	echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
	echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

	ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
	clientApps.Start (Seconds (2.0));
	Ptr<IcnEchoClient> icnClient = clientApps.Get (0)->GetObject<IcnEchoClient> ();
	icnClient->TraceConnectWithoutContext ("Tx", MakeCallback (&ClientTx));
	clientApps.Stop (Seconds (10.0));

//
//	UdpEchoServerHelper echoServer (9);
//
//	ApplicationContainer serverApps = echoServer.Install (nodes.Get (1));
//	serverApps.Start (Seconds (1.0));
//
//	Ptr<UdpEchoServer> udpServer = serverApps.Get (0)->GetObject<UdpEchoServer> ();
//	udpServer->TraceConnectWithoutContext ("Rx", MakeCallback (&ServerRx));
//
//	serverApps.Stop (Seconds (10.0));
//
//	UdpEchoClientHelper echoClient (interfaces.GetAddress (1), 9);
//
//	echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
//	echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
//	echoClient.SetAttribute ("PacketSize", UintegerValue (1024));
//
//	ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
//	clientApps.Start (Seconds (2.0));
//	Ptr<UdpEchoClient> udpClient = clientApps.Get (0)->GetObject<UdpEchoClient> ();
//	udpClient->TraceConnectWithoutContext ("Tx", MakeCallback (&ClientTx));
//	clientApps.Stop (Seconds (10.0));

	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}


