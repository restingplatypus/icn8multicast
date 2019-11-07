/**
 *
 *   simTime = 50
 *   numberOfUe = 30
 *   eNB bandwidth = 25 RBs or % MHz
 *   ul bandwidth = 25 RBs
 *   Scheduler = PF Scheduler
 *   SRS Periodicity = 160
 *   eNB Bandwidth = 46 dBm
 *   Mobiity Model = Steady State Random Waypoint Model
 *   Maximum UE Speed = 25 m/s
 *   Minimum UE Speed = 20 m/s
 *   Request size from UE = 64 bytes
 *   Response size from server = 2048 bytes
 *   Request Arrival Statistics = Poisson Arrivals with mean arrival time of 2 sec
 *   Wait Period  = 3.0 Seconds
 *   Zipf Parameter alpha = 1.5
 *   Number of contents = 100
 *
 *
 */


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
#include "ns3/flow-monitor-module.h"


using namespace ns3;
NS_LOG_COMPONENT_DEFINE ("ICN8_1");

void
ClientTx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet)
{
	Ptr<Packet> p = packet->Copy ();
	IcnHeader icnHeader;
	p->RemoveHeader(icnHeader);
	uint16_t data = icnHeader.GetData();
	//	NS_LOG_INFO ("Client has successfully transmitted a packet with GUID "
	//			<< data << ".");

	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << data << std::endl;

	//std::cout<<"Client has successfully transmitted a packet with GUID " << data << " at "<< Simulator::Now().GetSeconds()<< "." << std::endl;

	//NS_LOG_INFO (" sent a packet of " << packet->GetSize () << " bytes.");
}

void
ClientRx(Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet)
{
	Ptr<Packet> p = packet-> Copy();
	IcnHeader icnHeader;
	p->RemoveHeader(icnHeader);
	uint16_t data = icnHeader.GetData();
	//	NS_LOG_INFO ("Client has successfully transmitted a packet with GUID "
	//			<< data << ".");

	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << data << std::endl;

	//std::cout<<"Client has successfully received a packet with GUID " << data << " at "<< Simulator::Now().GetSeconds()<< "." << std::endl;
}


void
ServerRx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet)
{
//	AsciiTraceHelper asciiTraceHelper;
//	Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream ("icn8_1_serverRx.out");

	Ptr<Packet> p = packet->Copy ();
	IcnHeader icnHeader;
	p->RemoveHeader(icnHeader);
	uint16_t data = icnHeader.GetData();
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << data << std::endl;
	//	NS_LOG_INFO ("Server has successfully received a packet with GUID " << data<< ".");
	//std::cout<<"Server has successfully received a packet with GUID " << data<< " at " << Simulator::Now().GetSeconds() << "." << std::endl;
}

void
WindowTraceCallback(Ptr<OutputStreamWrapper> stream, uint16_t guid, uint16_t rnti)
{
	NS_LOG_INFO("Sink Created");
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << guid << "\t" << rnti << std::endl;
}


int main (int argc, char *argv[])
{
	Time rlcStatsEpoch = Seconds(1);
	double totalTime = 20;
	uint16_t numberOfEnb = 1;
	//uint16_t numberOfUe = 10;
	Time waitPeriod = Seconds(3.0);
	double meanArrival = 2;
//	Time txWaitDelay = Seconds(3.0);
	double txWaitDelay = 0.5;
	uint16_t dlBandwidth = 25;
	uint16_t ulBandwidth = 25;
	//double enbTxPowerDbm = 46;
	double alpha = 1.5;
	uint16_t f_density = 20; // in veh/mile/lane
	uint32_t contentSize=2048; // content size in bytes





	std::map<uint16_t, uint16_t> freewayMap = {{20, 58}, {40, 40}, {60, 28}, {80, 19}};
	//std::map<uint16_t, uint16_t> tunnelMap;

	double distance = 1000;
	Box macroUeBox = Box (-distance * 0.25, distance * 0.25, -distance * 0.25, distance * 0.25, 1.5, 1.5);




	CommandLine cmd;
	cmd.AddValue("rlcStatsEpoch", "RLC stats epoch duration", rlcStatsEpoch);
	cmd.AddValue("totalTime", "Total simulation time", totalTime);
	//cmd.AddValue("interPacketInterval", "Inter packet interval [ms])", interPacketInterval);
	cmd.AddValue("numberOfEnb", "Number of eNB", numberOfEnb);
	//cmd.AddValue("numberOfUe", "Number of UEs", numberOfUe);
	cmd.AddValue("waitPeriod", "Waiting time for aggregating the requests", waitPeriod);
	cmd.AddValue("meanArrival", "Mean arrival time for Poisson requests", meanArrival);
	cmd.AddValue("txWaitDelay", "The transmission delay due to aggregation", txWaitDelay);
	cmd.AddValue("dlBandwidth", " The downlink bandwidth", dlBandwidth);
	cmd.AddValue("ulBandwidth", " The uplink bandwidth", ulBandwidth);
	//cmd.AddValue("enbTxPowerDbm", " The transmit power for eNB", enbTxPowerDbm);
	cmd.AddValue("alpha", " The Zipf Parameter", alpha);
	cmd.AddValue("f_density", "The density of highspeed freeway in vehicles per mile ", f_density);
	cmd.AddValue("contentSize", "The content size returned by server in bytes", contentSize);
	cmd.Parse (argc, argv);

	ConfigStore inputConfig;
	inputConfig.ConfigureDefaults ();
	cmd.Parse (argc, argv);


	uint16_t numberOfUe = f_density*3;

	//LogComponentEnable ("LteEnbRrc", LOG_LEVEL_INFO);
	//LogComponentEnable ("LteUeMac", LOG_LEVEL_INFO);
	//LogComponentEnable ("LteEnbMac", LOG_LEVEL_INFO);
	//LogComponentEnable("EpcEnbApplication", LOG_LEVEL_INFO);
	//LogComponentEnable("IcnEchoServerApplication", LOG_LEVEL_INFO);
	//LogComponentEnable("EpcSgwPgwApplication", LOG_LEVEL_INFO);
	//LogComponentEnable("LtePdcp", LOG_LEVEL_INFO);

	Ptr<LteHelper> lteHelper = CreateObject<LteHelper>();
	Ptr<PointToPointEpcHelper> epcHelper = CreateObject<PointToPointEpcHelper>();
	lteHelper->SetEpcHelper(epcHelper);
	//lteHelper->SetSpectrumChannelType ("ns3::MultiModelSpectrumChannel");
	lteHelper->SetAttribute ("PathlossModel", StringValue ("ns3::Cost231PropagationLossModel"));
	//lteHelper->SetAttribute ("PathlossModel", StringValue ("ns3::ItuR1411LosPropagationLossModel"));
	lteHelper->SetSchedulerType ("ns3::PfFfMacScheduler");
	lteHelper->SetEnbDeviceAttribute ("DlBandwidth", UintegerValue (dlBandwidth));
	lteHelper->SetEnbDeviceAttribute ("UlBandwidth", UintegerValue (ulBandwidth));

	std::string tracefilePrefix = "icn8_1";

	Config::SetDefault ("ns3::LteEnbRrc::SrsPeriodicity", UintegerValue (320));
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
	Config::SetDefault("ns3::LteEnbMac::WaitPeriod", TimeValue(Seconds(waitPeriod)));
	Config::SetDefault ("ns3::LteEnbRrc::TxWaitDelay", DoubleValue(txWaitDelay));
	//Config::SetDefault ("ns3::LteEnbPhy::TxPower", DoubleValue (enbTxPowerDbm));
	Config::SetDefault ("ns3::LteUeMac::Alpha", DoubleValue (alpha));
	Config::SetDefault ("ns3::IcnEchoServer::PacketSize", UintegerValue(contentSize));



	switch(f_density)
	{
	case 10:
		meanArrival = 0.57;
		break;
	case 20:
		meanArrival = 0.34;
		break;
	case 30:
		meanArrival = 0.25;
		break;
	case 40:
		meanArrival = 0.208;
		break;
	case 50:
		meanArrival = 0.22;
		break;
	case 60:
		meanArrival = 0.213;
		break;
	case 70:
		meanArrival = 0.216;
		break;
	case 80:
		meanArrival = 0.231;
		break;
	}



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

//	/**
//	 *  Density and Speed Map calculation
//	 */
//
//	std::map<uint16_t, uint16_t>::iterator it;
//	for(it = freewayMap.begin() ; it != freewayMap.end(); it++)
//	{
//		it->first = 20;
//		it->send
//	}

	MobilityHelper mobility;
	Ptr<RandomBoxPositionAllocator> randomUePositionAlloc = CreateObject<RandomBoxPositionAllocator> ();
	Ptr<UniformRandomVariable> xVal = CreateObject<UniformRandomVariable> ();
	xVal->SetAttribute ("Min", DoubleValue (macroUeBox.xMin));
	xVal->SetAttribute ("Max", DoubleValue (macroUeBox.xMax));
	randomUePositionAlloc->SetAttribute ("X", PointerValue (xVal));
	Ptr<UniformRandomVariable> yVal = CreateObject<UniformRandomVariable> ();
	yVal->SetAttribute ("Min", DoubleValue (macroUeBox.yMin));
	yVal->SetAttribute ("Max", DoubleValue (macroUeBox.yMax));
	randomUePositionAlloc->SetAttribute ("Y", PointerValue (yVal));
	Ptr<UniformRandomVariable> zVal = CreateObject<UniformRandomVariable> ();
	zVal->SetAttribute ("Min", DoubleValue (macroUeBox.zMin));
	zVal->SetAttribute ("Max", DoubleValue (macroUeBox.zMax));
	randomUePositionAlloc->SetAttribute ("Z", PointerValue (zVal));


	std::ostringstream speedConstantRandomVariableStream;

	double min, max;
	switch(f_density)
	{
	case 10:
		min = 26;
		max = 32;
		break;

	case 20:
		min = 21;
		max = 27;
		break;

	case 30:
		min = 19;
		max = 25;
		break;

	case 40:
		min = 17;
		max = 23;
		break;

	case 50:
		min = 12;
		max = 18;
		break;

	case 60:
		min = 10;
		max = 16;
		break;

	case 70:
		min = 8;
		max = 14;
		break;

	case 80:
		min = 6;
		max = 12;
		break;

	}


	speedConstantRandomVariableStream << "ns3::UniformRandomVariable[Min=" << min << "|Max=" << max << "]";
	mobility.SetMobilityModel ("ns3::RandomWaypointMobilityModel", "Speed", StringValue (speedConstantRandomVariableStream.str ()),
			"Pause", StringValue ("ns3::ConstantRandomVariable[Constant=2.0]"), "PositionAllocator", PointerValue (randomUePositionAlloc));
	mobility.SetPositionAllocator (randomUePositionAlloc);
	mobility.Install (ueNodes);



//	MobilityHelper mobility;
//	mobility.SetMobilityModel ("ns3::SteadyStateRandomWaypointMobilityModel");
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MinX", DoubleValue (macroUeBox.xMin));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MinY", DoubleValue (macroUeBox.yMin));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MaxX", DoubleValue (macroUeBox.xMax));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MaxY", DoubleValue (macroUeBox.yMax));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::Z", DoubleValue (macroUeBox.zMin));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MaxSpeed", DoubleValue (25));
//	Config::SetDefault ("ns3::SteadyStateRandomWaypointMobilityModel::MinSpeed", DoubleValue (20));
//
//	Ptr<RandomBoxPositionAllocator> randomUePositionAlloc = CreateObject<RandomBoxPositionAllocator> ();
//	Ptr<UniformRandomVariable> xVal = CreateObject<UniformRandomVariable> ();
//	xVal->SetAttribute ("Min", DoubleValue (macroUeBox.xMin));
//	xVal->SetAttribute ("Max", DoubleValue (macroUeBox.xMax));
//	randomUePositionAlloc->SetAttribute ("X", PointerValue (xVal));
//	Ptr<UniformRandomVariable> yVal = CreateObject<UniformRandomVariable> ();
//	yVal->SetAttribute ("Min", DoubleValue (macroUeBox.yMin));
//	yVal->SetAttribute ("Max", DoubleValue (macroUeBox.yMax));
//	randomUePositionAlloc->SetAttribute ("Y", PointerValue (yVal));
//	Ptr<UniformRandomVariable> zVal = CreateObject<UniformRandomVariable> ();
//	zVal->SetAttribute ("Min", DoubleValue (macroUeBox.zMin));
//	zVal->SetAttribute ("Max", DoubleValue (macroUeBox.zMax));
//	randomUePositionAlloc->SetAttribute ("Z", PointerValue (zVal));
//	mobility.SetPositionAllocator (randomUePositionAlloc);
//	mobility.Install (ueNodes);



//	Ptr<RandomBoxPositionAllocator> positionAlloc = CreateObject<RandomBoxPositionAllocator> ();
//	mobility.SetPositionAllocator (positionAlloc);
//	mobility.Install (ueNodes);
//	for (NodeContainer::Iterator it = ueNodes.Begin ();
//			it != ueNodes.End ();
//			++it)
//	{
//		(*it)->Initialize ();
//	}


	Ptr<ListPositionAllocator> positionAlloc1 = CreateObject<ListPositionAllocator>();
	positionAlloc1->Add(Vector(0,0,50));
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


	/**
	 *
	 *  INSTALLING APPLICATIONS ON REMOTE HOST AND UEs
	 *
	 */
	IcnEchoServerHelper echoServer (9);
	ApplicationContainer serverApps = echoServer.Install(remoteHost);
	serverApps.Start(Seconds(0.0));
	Ptr<IcnEchoServer> icnServer = serverApps.Get (0)->GetObject<IcnEchoServer> ();
	AsciiTraceHelper asciiTraceHelper;
	Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream ("icn8_1_serverRx.out");
	icnServer->TraceConnectWithoutContext("Rx", MakeBoundCallback (&ServerRx, stream));
	//icnServer->TraceConnectWithoutContext ("Rx", MakeCallback (&ServerRx));
	serverApps.Stop(Seconds(totalTime));

	IcnEchoClientHelper echoClient(internetIpIfaces.GetAddress(1), 9);
	echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
	//echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
	echoClient.SetAttribute ("PacketSize", UintegerValue (64));

	Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream ("icn8_1_clientTx.out");
	Ptr<OutputStreamWrapper> stream2 = asciiTraceHelper.CreateFileStream ("icn8_1_clientRx.out");

	for(uint32_t i = 0; i < ueNodes.GetN(); i++)
	{
		Ptr<ExponentialRandomVariable> var = CreateObject<ExponentialRandomVariable>();
		var->SetAttribute("Mean", DoubleValue(meanArrival));
		double startTime = var->GetValue();

		ApplicationContainer clientApps = echoClient.Install(ueNodes.Get(i));
		clientApps.Start(Seconds(startTime));
		Ptr<IcnEchoClient> icnClient = clientApps.Get (0)->GetObject<IcnEchoClient> ();
		icnServer->TraceConnectWithoutContext("Tx", MakeBoundCallback (&ClientTx, stream1));
		icnServer->TraceConnectWithoutContext("Rx", MakeBoundCallback (&ClientTx, stream2));
		//icnClient->TraceConnectWithoutContext ("Tx", MakeCallback (&ClientTx));
		//icnClient->TraceConnectWithoutContext("Rx", MakeCallback(&ClientRx));
		clientApps.Stop(Seconds(totalTime));
	}




	Ptr<OutputStreamWrapper> stream3 = asciiTraceHelper.CreateFileStream ("icn8_1_window.txt");

	std::ostringstream oss;
	oss<< "/NodeList/*/DeviceList/*/ComponentCarrierMap/*/LteEnbMac/AxRnti";
	Config::ConnectWithoutContext(oss.str(), MakeBoundCallback (&WindowTraceCallback, stream3));
	//lteHelper->TraceConnect("/NodeList/*/DeviceList/*/ComponentCarrierMap/*/LteEnbMac/AxRnti", MakeBoundCallback (&WindowTraceCallback, stream3));

	lteHelper->EnableTraces ();
	//lteHelper->EnableRlcTraces ();
	Ptr<RadioBearerStatsCalculator> rlcStats = lteHelper->GetRlcStats();
	rlcStats->SetAttribute("EpochDuration", TimeValue(rlcStatsEpoch));
	//p2ph.EnablePcapAll("icn8_1");


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

	FlowMonitorHelper fl;
	Ptr<FlowMonitor> monitor;
	monitor = fl.Install(ueNodes);
	monitor->SetAttribute ("DelayBinWidth", DoubleValue(0.001));
	monitor->SetAttribute ("JitterBinWidth", DoubleValue(0.001));
	monitor->SetAttribute ("PacketSizeBinWidth", DoubleValue(20));

	Simulator::Stop(Seconds(totalTime));
	Simulator::Run();

	monitor->SerializeToXmlFile ("flowResults.xml" , true, true );

	Simulator::Destroy();
	return 0;
}
