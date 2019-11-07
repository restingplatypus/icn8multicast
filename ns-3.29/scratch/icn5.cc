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

using namespace ns3;
NS_LOG_COMPONENT_DEFINE ("ICN4");

int main (int argc, char *argv[])
{
	Time rlcStatsEpoch = MilliSeconds(250);

	CommandLine cmd;
	cmd.AddValue("rlcStatsEpoch", "RLC stats epoch duration", rlcStatsEpoch);

	cmd.Parse (argc, argv);

	LogComponentEnable("OnOffApplication", LOG_LEVEL_INFO);

	ConfigStore inputConfig;
	inputConfig.ConfigureDefaults ();
	cmd.Parse (argc, argv);

	Ptr<LteHelper> lteHelper = CreateObject<LteHelper>();
	Ptr<PointToPointEpcHelper> epcHelper = CreateObject<PointToPointEpcHelper>();
	lteHelper->SetEpcHelper(epcHelper);

	Config::SetDefault ("ns3::LteEnbRrc::SrsPeriodicity", UintegerValue (160));

	//trace files prefix
	std::string tracefilePrefix = "icn5";

	//add trace file prefx
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
	NS_LOG_INFO ("Assign IP Addresses to pgw and remote host.");
	Ipv4AddressHelper ipv4h;
	ipv4h.SetBase("1.0.0.0", "255.0.0.0");
	Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign(internetDevices);
	// interface 0 is localhost, 1 is the p2p device
	Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress (1);

	Ipv4StaticRoutingHelper ipv4RoutingHelper;
	Ptr<Ipv4StaticRouting> remoteHostStaticRouting;
	remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting(remoteHost->GetObject<Ipv4>());
	//remoteHostStaticRouting->AddNetworkRouteTo(epcHelper->GetEpcIpv4NetworkAddress(), Ipv4Mask ("255.255.0.0"), 1);
	remoteHostStaticRouting->AddNetworkRouteTo(Ipv4Address("7.0.0.0"), Ipv4Mask("255.255.0.0"), 1);

	NodeContainer enbNodes;
	enbNodes.Create(1);
	NodeContainer ueNodes;
	ueNodes.Create(10);

	MobilityHelper mobility;
	Ptr<ListPositionAllocator> positionAlloc1 = CreateObject<ListPositionAllocator>();
	positionAlloc1->Add(Vector(50,50,0));
	mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
	mobility.SetPositionAllocator(positionAlloc1);
	mobility.Install(enbNodes);
	BuildingsHelper::Install(enbNodes);


	ObjectFactory pos;
	pos.SetTypeId ("ns3::RandomRectanglePositionAllocator");
	pos.Set ("X", StringValue ("ns3::UniformRandomVariable[Min=0.0|Max=300.0]"));
	pos.Set ("Y", StringValue ("ns3::UniformRandomVariable[Min=0.0|Max=1500.0]"));
	Ptr<PositionAllocator> taPositionAlloc = pos.Create ()->GetObject<PositionAllocator> ();
	std::ostringstream speedUniformRandomVariableStream;
	speedUniformRandomVariableStream << "ns3::UniformRandomVariable[Min=0.0|Max=" << 20 << "]";

	std::ostringstream pauseConstantRandomVariableStream;
	pauseConstantRandomVariableStream << "ns3::ConstantRandomVariable[Constant="
			<< 0.1
			<< "]";

	mobility.SetMobilityModel ("ns3::RandomWaypointMobilityModel",
			"Speed", StringValue (speedUniformRandomVariableStream.str ()),
			"Pause", StringValue (pauseConstantRandomVariableStream.str ()),
			"PositionAllocator", PointerValue (taPositionAlloc)
	);
	mobility.Install(ueNodes);
	BuildingsHelper::Install(ueNodes);

	NetDeviceContainer enbLteDevs = lteHelper->InstallEnbDevice(enbNodes);
	NetDeviceContainer ueLteDevs = lteHelper->InstallUeDevice(ueNodes);


	//install IP stack on the UEs
	internet.Install(ueNodes);
	Ipv4InterfaceContainer ueIpIface;
	//ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (ueLteDevs));


	//assign IP addresses to UEs
	NS_LOG_INFO ("Assign IP Addresses to UEs.");
	for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
	{
		Ptr<Node> ue = ueNodes.Get (u);
		Ptr<NetDevice> ueLteDevice = ueLteDevs.Get (u);
		Ipv4InterfaceContainer ueIpIface;
		ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (ueLteDevice));
		// set the default gateway for the UE
		Ptr<Ipv4StaticRouting> ueStaticRouting;
		ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (ue->GetObject<Ipv4> ());
		ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);
	}

//	Ptr<EpcTft> tft = Create<EpcTft> ();
//	EpcTft::PacketFilter pf;
//	pf.localPortStart = 1234;
//	pf.localPortEnd = 1234;
//	tft->Add (pf);
//	lteHelper->ActivateDedicatedEpsBearer (ueLteDevs, EpsBearer (EpsBearer::NGBR_VIDEO_TCP_DEFAULT),tft);

	lteHelper->Attach(ueLteDevs, enbLteDevs.Get(0));

	//Install applications on UEs
	//uint16_t dlPort = 1234;
	uint16_t ulPort = 2000;
	uint16_t otherPort = 3000;
	ApplicationContainer clientApps;
	ApplicationContainer serverApps;
	std::ostringstream onConstantRandomVariableStream;
	onConstantRandomVariableStream << "ns3::ConstantRandomVariable[Constant=" << 0.4 << "]";
	for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
	{
		++ulPort;
		++otherPort;

		//PacketSinkHelper dlPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), dlPort));

		PacketSinkHelper ulPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (remoteHostAddr, ulPort));

		//serverApps.Add (dlOnOffHelper.Install (ueNodes.Get(u)));
		//serverApps.Add(dlPacketSinkHelper.Install(ueNodes.Get(u)));
		serverApps.Add (ulPacketSinkHelper.Install (remoteHost));
		//serverApps.Add (packetSinkHelper.Install (ueNodes.Get(u)));

//		UdpClientHelper dlClient (ueIpIface.GetAddress (u), dlPort);
//		dlClient.SetAttribute ("Interval", TimeValue (MilliSeconds(100)));
//		dlClient.SetAttribute ("MaxPackets", UintegerValue(1000000));

		OnOffHelper ulOnOffHelper("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
		ulOnOffHelper.SetAttribute("Remote", AddressValue(InetSocketAddress (Ipv4Address::GetAny (), ulPort)));
		ulOnOffHelper.SetAttribute("OnTime", StringValue(onConstantRandomVariableStream.str()));
		ulOnOffHelper.SetAttribute ("OffTime", StringValue ("ns3::ExponentialRandomVariable[Mean=0.01]"));
		ulOnOffHelper.SetAttribute ("DataRate", DataRateValue (DataRate ("5Mbps")));
		ulOnOffHelper.SetAttribute ("PacketSize", UintegerValue (64));
		ulOnOffHelper.SetAttribute("MaxBytes", UintegerValue(96));

		//clientApps.Add (dlClient.Install (remoteHost));
		clientApps.Add(ulOnOffHelper.Install (ueNodes.Get(u)));
	}

	serverApps.Start (Seconds (0.01));
	clientApps.Start (Seconds (0.01));

	lteHelper->EnableTraces ();
	Ptr<RadioBearerStatsCalculator> rlcStats = lteHelper->GetRlcStats();
	rlcStats->SetAttribute("EpochDuration", TimeValue(rlcStatsEpoch));
	//p2ph.EnablePcapAll("icn5");
	//p2ph.EnablePcap

	//p2ph.EnablePcap("icn5", pgw->GetId(), internetDevices.Get(0)->GetIfIndex(), true);
	//p2ph.EnablePcap("icn5", remoteHost->GetId(), internetDevices.Get(1)->GetIfIndex(), true);
	//p2ph.EnablePcap("icn5", remoteHost->GetId(), internetDevices.Get(0)->GetIfIndex(), true);
	p2ph.EnablePcap("icn5",enbNodes, false);
	p2ph.EnablePcap("icn5", ueNodes, false);

	internet.EnablePcapIpv4("ipv5-internet", ueNodes.Get (0)->GetId (), 1, true);


	//double statsStartTime = 0.040; // need to allow for RRC connection establishment + SRS
	//double statsDuration = 2.0;
	//Simulator::Stop (Seconds (statsStartTime + statsDuration - 0.0001));
	//Simulator::Run ();

	Simulator::Stop(Seconds(1.0));
	Simulator::Run();
	Simulator::Destroy();
	return 0;
}
