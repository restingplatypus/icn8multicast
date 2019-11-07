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
NS_LOG_COMPONENT_DEFINE ("ICN8");


int main (int argc, char *argv[])
{
	Time rlcStatsEpoch = MilliSeconds(250);
	double totalTime = 10;
	double interPacketInterval = 100;
	uint16_t numberOfEnb = 1;
	uint16_t numberOfUe = 30;

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

	std::string tracefilePrefix = "icn8";

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




//
//	mobility.SetMobilityModel ("ns3::SteadyStateRandomWaypointMobilityModel");
//
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MinX", DoubleValue (0));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MinY", DoubleValue (0));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MaxX", DoubleValue (500));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MaxY", DoubleValue (500));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::Z", DoubleValue (0));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MaxSpeed", DoubleValue (25));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MinSpeed", DoubleValue (20));
//
//	// this is not used since SteadyStateRandomWaypointMobilityModel
//	// takes care of initializing the positions;  however we need to
//	// reset it since the previously used PositionAllocator
//	// (SameRoom) will cause an error when used with homeDeploymentRatio=0
//	Ptr<RandomBoxPositionAllocator> positionAlloc = CreateObject<RandomBoxPositionAllocator> ();
//	mobility.SetPositionAllocator (positionAlloc);
//	mobility.Install (ueNodes);
//
//	// forcing initialization so we don't have to wait for Nodes to
//	// start before positions are assigned (which is needed to
//	// output node positions to file and to make AttachToClosestEnb work)
//	for (NodeContainer::Iterator it = ueNodes.Begin ();
//			it != ueNodes.End ();
//			++it)
//	{
//		(*it)->Initialize ();
//	}

	//	mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	//	mobility.Install (ueNodes);
	//	BuildingsHelper::Install(ueNodes);


//	ObjectFactory pos;
//	pos.SetTypeId ("ns3::RandomRectanglePositionAllocator");
//	pos.Set ("X", StringValue ("ns3::UniformRandomVariable[Min=0.0|Max=500.0]"));
//	pos.Set ("Y", StringValue ("ns3::UniformRandomVariable[Min=0.0|Max=500.0]"));
//	Ptr<PositionAllocator> taPositionAlloc = pos.Create ()->GetObject<PositionAllocator> ();
//	std::ostringstream speedUniformRandomVariableStream;
//	speedUniformRandomVariableStream << "ns3::UniformRandomVariable[Min=0.0|Max="
//			<< 20
//			<< "]";
//
//	std::ostringstream pauseConstantRandomVariableStream;
//	pauseConstantRandomVariableStream << "ns3::ConstantRandomVariable[Constant="
//			<< 0.1
//			<< "]";
//
//	mobility.SetMobilityModel ("ns3::RandomWaypointMobilityModel",
//			//                                  "Speed", StringValue ("ns3::UniformRandomVariable[Min=0.0|Max=nodeSpeed]"),
//			"Speed", StringValue (speedUniformRandomVariableStream.str ()),
//			"Pause", StringValue (pauseConstantRandomVariableStream.str ()),
//			"PositionAllocator", PointerValue (taPositionAlloc)
//	);
//	mobility.Install(ueNodes);
//	BuildingsHelper::Install(ueNodes);

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



	//Install applications on UEs

	uint16_t dlPort = 1234;
	uint16_t ulPort = 2000;
	ApplicationContainer clientApps;
	ApplicationContainer serverApps;
	std::ostringstream onConstantRandomVariableStream;
	onConstantRandomVariableStream << "ns3::ConstantRandomVariable[Constant=" << 0.4 << "]";
	for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
	{
		++ulPort;
		Ptr<ExponentialRandomVariable> startTime = CreateObject<ExponentialRandomVariable>();
		startTime->SetAttribute("Mean", DoubleValue(1));
		//startTime->SetAttribute("Bound", DoubleValue(0.3));
		double start = startTime->GetValue();
		double stop = totalTime;


		PacketSinkHelper dlPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), dlPort));
		PacketSinkHelper ulPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
		//serverApps.Add (ulPacketSinkHelper.Install (remoteHost));
		//serverApps.Add (packetSinkHelper.Install (ueNodes.Get(u)));
		serverApps.Add(dlPacketSinkHelper.Install(ueNodes.Get(u)));
		serverApps.Add(ulPacketSinkHelper.Install (remoteHost));
		serverApps.Start(Seconds(0));
		serverApps.Stop(Seconds(stop));

		UdpClientHelper dlClient (ueIpIface.GetAddress (u), dlPort);
		dlClient.SetAttribute ("Interval", TimeValue (MilliSeconds(interPacketInterval)));
		dlClient.SetAttribute ("MaxPackets", UintegerValue(1000000));

		OnOffHelper ulOnOffHelper("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
		ulOnOffHelper.SetAttribute("Remote", AddressValue(InetSocketAddress (Ipv4Address::GetAny (), ulPort)));
		ulOnOffHelper.SetAttribute("OnTime", StringValue(onConstantRandomVariableStream.str()));
		ulOnOffHelper.SetAttribute ("OffTime", StringValue ("ns3::ExponentialRandomVariable[Mean=0.01]"));
		ulOnOffHelper.SetAttribute ("DataRate", DataRateValue (DataRate ("5Mbps")));
		ulOnOffHelper.SetAttribute ("PacketSize", UintegerValue (64));
		ulOnOffHelper.SetAttribute("MaxBytes", UintegerValue(96));

		clientApps.Add(dlClient.Install(remoteHost));
		clientApps.Add(ulOnOffHelper.Install(ueNodes.Get(u)));
		clientApps.Start(Seconds(start));
		clientApps.Stop(Seconds(stop));
	}

	//serverApps.Start (Seconds (0.01));
	//clientApps.Start (Seconds (0.01));

	lteHelper->EnableTraces ();
	Ptr<RadioBearerStatsCalculator> rlcStats = lteHelper->GetRlcStats();
	rlcStats->SetAttribute("EpochDuration", TimeValue(rlcStatsEpoch));
	p2ph.EnablePcapAll("icn8");

//	// Configure Radio Environment Map (REM) output
//	// for LTE-only simulations always use /ChannelList/0 which is the downlink channel
//	Ptr<RadioEnvironmentMapHelper> remHelper = CreateObject<RadioEnvironmentMapHelper> ();
//	remHelper->SetAttribute ("ChannelPath", StringValue ("/ChannelList/1"));
//	remHelper->SetAttribute ("OutputFile", StringValue ("icn8.rem"));
//	remHelper->SetAttribute ("XMin", DoubleValue (-400.0));
//	remHelper->SetAttribute ("XMax", DoubleValue (400.0));
//	remHelper->SetAttribute ("YMin", DoubleValue (-300.0));
//	remHelper->SetAttribute ("YMax", DoubleValue (300.0));
//	remHelper->SetAttribute ("Z", DoubleValue (0.0));
//	remHelper->Install ();

	//BuildingsHelper::MakeMobilityModelConsistent ();

//	lteHelper->EnableTraces ();
//	Ptr<RadioBearerStatsCalculator> rlcStats = lteHelper->GetRlcStats();
//	rlcStats->SetAttribute("EpochDuration", TimeValue(rlcStatsEpoch));
//	p2ph.EnablePcapAll("icn8");




	Simulator::Stop(Seconds(totalTime));
	Simulator::Run();
	Simulator::Destroy();
	return 0;
}
