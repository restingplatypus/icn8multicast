#include<ns3/lte-module.h>
#include<ns3/core-module.h>
#include<ns3/mobility-module.h>
#include<ns3/network-module.h>
#include<ns3/internet-module.h>
#include<ns3/applications-module.h>
#include<ns3/point-to-point-helper.h>
#include<ns3/buildings-helper.h>
#include<iomanip>
#include<stdio.h>
#include<ios>
#include "ns3/config-store.h"
#include "../src/applications/model/icn-packet-header.h"
#include "../src/applications/helper/icn-request-response-helper.h"
#include "../src/applications/model/icn-echo-server.h"
#include "../src/applications/model/icn-echo-client.h"

using namespace ns3;
NS_LOG_COMPONENT_DEFINE ("ICN8_2");

int main (int argc, char *argv[])
{
	Time rlcStatsEpoch = MilliSeconds(250);
	double totalTime = 3;
	double interPacketInterval = 100;
	uint16_t numberOfEnb = 1;
	uint16_t numberOfUe = 10;

	CommandLine cmd;
	cmd.AddValue("rlcStatsEpoch", "RLC stats epoch duration", rlcStatsEpoch);
	cmd.AddValue("totalTime", "Total simulation time", totalTime);
	cmd.AddValue("interPacketInterval", "Inter packet interval [ms])", interPacketInterval);
	cmd.AddValue("numberOfEnb", "Number of eNB", numberOfEnb);
	cmd.AddValue("numberOfUe", "Number of UEs", numberOfUe);
	cmd.Parse (argc, argv);

	ConfigStore inputConfig;
	inputConfig.ConfigureDefaults ();
	cmd.Parse (argc, argv);

	Ptr<LteHelper> lteHelper = CreateObject<LteHelper>();
	Ptr<PointToPointEpcHelper> epcHelper = CreateObject<PointToPointEpcHelper>();
	lteHelper->SetEpcHelper(epcHelper);
	//lteHelper->SetSpectrumChannelType ("ns3::MultiModelSpectrumChannel");
	lteHelper->SetAttribute ("PathlossModel", StringValue ("ns3::Cost231PropagationLossModel"));

	std::string tracefilePrefix = "icn8_2";
	Config::SetDefault ("ns3::LteEnbRrc::SrsPeriodicity", UintegerValue (160));
	Config::SetDefault("ns3::RadioBearerStatsCalculator::DlRlcOutputFilename", StringValue(tracefilePrefix + ".DlRlcStats.txt"));
	Config::SetDefault("ns3::RadioBearerStatsCalculator::UlRlcOutputFilename", StringValue(tracefilePrefix + ".UlRlcStats.txt"));
	Config::SetDefault("ns3::RadioBearerStatsCalculator::DlPdcpOutputFilename", StringValue(tracefilePrefix + ".DlPdcpStats.txt"));
	Config::SetDefault("ns3::RadioBearerStatsCalculator::UlPdcpOutputFilename", StringValue(tracefilePrefix + ".UlPdcpStats.txt"));
	Config::SetDefault("ns3::MacStatsCalculator::DlOutputFilename", StringValue(tracefilePrefix + ".DlMacStats.txt"));
	Config::SetDefault("ns3::MacStatsCalculator::UlOutputFilename", StringValue(tracefilePrefix + ".UlMacStats.txt"));
	Config::SetDefault("ns3::PhyTxStatsCalculator::DlTxOutputFilename", StringValue(tracefilePrefix + ".DlTxPhyStats.txt"));
	Config::SetDefault("ns3::PhyTxStatsCalculator::UlTxOutputFilename", StringValue(tracefilePrefix + ".UlTxPhyStats.txt"));
	Config::SetDefault("ns3::PhyRxStatsCalculator::DlRxOutputFilename", StringValue(tracefilePrefix + ".DlRxPhyStats.txt"));
	Config::SetDefault("ns3::PhyRxStatsCalculator::UlRxOutputFilename", StringValue(tracefilePrefix + ".UlRxPhyStats.txt"));
	Config::SetDefault("ns3::PhyStatsCalculator::DlRsrpSinrFilename", StringValue(tracefilePrefix + ".DlRsrpSinrStats.txt"));
	Config::SetDefault("ns3::PhyStatsCalculator::UlSinrFilename", StringValue(tracefilePrefix + ".UlSinrStats.txt"));
	Config::SetDefault("ns3::PhyStatsCalculator::UlInterferenceFilename", StringValue(tracefilePrefix + ".UlInterferenceStats.txt"));

	Ptr<Node> pgw = epcHelper->GetPgwNode();

	//Create a remote host
	NodeContainer remoteHostContainer;
	remoteHostContainer.Create(1);
	Ptr<Node> remoteHost = remoteHostContainer.Get(0);
	InternetStackHelper internet;
	internet.Install(remoteHostContainer);

	// create the internet
	PointToPointHelper p2ph;
	p2ph.SetDeviceAttribute("DataRate", DataRateValue(DataRate("100Gb/s")));
	p2ph.SetDeviceAttribute("Mtu", UintegerValue(1500));
	p2ph.SetChannelAttribute("Delay", TimeValue(Seconds(0.010)));
	NetDeviceContainer internetDevices = p2ph.Install(pgw,remoteHost);
	Ipv4AddressHelper ipv4h;
	ipv4h.SetBase("1.0.0.0", "255.0.0.0");
	Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign(internetDevices);
	//Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress(1);
	Ipv4StaticRoutingHelper ipv4RoutingHelper;
	Ptr<Ipv4StaticRouting> remoteHostStaticRouting;
	remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting(remoteHost->GetObject<Ipv4>());
	remoteHostStaticRouting->AddNetworkRouteTo(Ipv4Address("7.0.0.0"), Ipv4Mask("255.255.0.0"), 1);

	NodeContainer enbNodes;
	enbNodes.Create(1);
	NodeContainer ueNodes;
	ueNodes.Create(numberOfUe);


	MobilityHelper mobility;
	mobility.SetMobilityModel ("ns3::SteadyStateRandomWaypointMobilityModel");
	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MinX", DoubleValue (0));
	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MinY", DoubleValue (0));
	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MaxX", DoubleValue (500));
	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MaxY", DoubleValue (500));
	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::Z", DoubleValue (0));
	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MaxSpeed", DoubleValue (25));
	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MinSpeed", DoubleValue (20));
	Ptr<RandomBoxPositionAllocator> positionAlloc = CreateObject<RandomBoxPositionAllocator> ();
	mobility.SetPositionAllocator (positionAlloc);
	mobility.Install (ueNodes);
	for (NodeContainer::Iterator it = ueNodes.Begin ();
			it != ueNodes.End ();
			++it)
	{
		(*it)->Initialize ();
	}


	Ptr<ListPositionAllocator> positionAlloc1 = CreateObject<ListPositionAllocator>();
	positionAlloc1->Add(Vector(250,250,0));
	mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
	mobility.SetPositionAllocator(positionAlloc1);
	mobility.Install(enbNodes);
	BuildingsHelper::Install(enbNodes);

	NetDeviceContainer enbLteDevs = lteHelper->InstallEnbDevice(enbNodes);
	NetDeviceContainer ueLteDevs = lteHelper->InstallUeDevice(ueNodes);

	//install IP stack on the UEs
	internet.Install(ueNodes);
	Ipv4InterfaceContainer ueIpIface;
	ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (ueLteDevs));

	//assign IP addresses to UEs
	for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
	{
		Ptr<Node> ueNode = ueNodes.Get(u);
		//set the default gateway for the UE
		Ptr<Ipv4StaticRouting> ueStaticRouting;
		ueStaticRouting = ipv4RoutingHelper.GetStaticRouting(ueNode->GetObject<Ipv4>());
		ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);
	}
	lteHelper->Attach(ueLteDevs, enbLteDevs.Get(0));

	// Activate an EPS bearer on all UEs
	for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
	{
		Ptr<NetDevice> ueDevice = ueLteDevs.Get (u);
		GbrQosInformation qos;
		qos.gbrDl = 132;  // bit/s, considering IP, UDP, RLC, PDCP header size
		qos.gbrUl = 132;
		qos.mbrDl = qos.gbrDl;
		qos.mbrUl = qos.gbrUl;

		enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
		EpsBearer bearer (q, qos);
		bearer.arp.priorityLevel = 15 - (u + 1);
		bearer.arp.preemptionCapability = true;
		bearer.arp.preemptionVulnerability = true;
		lteHelper->ActivateDedicatedEpsBearer (ueDevice, bearer, EpcTft::Default ());
	}

	// Install and start applications on UEs and remote host
	uint16_t dlPort = 1234;
	uint16_t ulPort = 2000;
	ApplicationContainer clientApps;
	ApplicationContainer serverApps;
	for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
	{
		++ulPort;
		PacketSinkHelper dlPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), dlPort));
		//PacketSinkHelper ulPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
		serverApps.Add (dlPacketSinkHelper.Install (ueNodes.Get(u)));
		//serverApps.Add (ulPacketSinkHelper.Install (remoteHost));

		UdpClientHelper dlClient (ueIpIface.GetAddress (u), dlPort);
		dlClient.SetAttribute ("Interval", TimeValue (MilliSeconds(interPacketInterval)));
		dlClient.SetAttribute ("MaxPackets", UintegerValue(100));

//		UdpClientHelper ulClient (remoteHostAddr, ulPort);
//		ulClient.SetAttribute ("Interval", TimeValue (MilliSeconds(interPacketInterval)));
//		ulClient.SetAttribute ("MaxPackets", UintegerValue(1000000));

		clientApps.Add (dlClient.Install (remoteHost));
		//clientApps.Add (ulClient.Install (ueNodes.Get(u)));
	}

	lteHelper->EnableTraces ();
	Ptr<RadioBearerStatsCalculator> rlcStats = lteHelper->GetRlcStats();
	rlcStats->SetAttribute("EpochDuration", TimeValue(rlcStatsEpoch));
	p2ph.EnablePcapAll("icn8_2");

	Simulator::Stop(Seconds(totalTime));
	Simulator::Run();
	Simulator::Destroy();

	return 0;
}
