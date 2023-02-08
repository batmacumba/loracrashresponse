#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"

// LoRaWAN Library includes
#include "ns3/end-device-lora-phy.h"
#include "ns3/gateway-lora-phy.h"
#include "ns3/end-device-lorawan-mac.h"
#include "ns3/gateway-lorawan-mac.h"
#include "ns3/simulator.h"
#include "ns3/log.h"
#include "ns3/constant-position-mobility-model.h"
#include "ns3/lora-helper.h"
#include "ns3/mobility-helper.h"
#include "ns3/node-container.h"
#include "ns3/position-allocator.h"
#include "ns3/command-line.h"
#include "ns3/mobility-module.h"
#include "ns3/netanim-module.h"

// Local includes
#include "crash-response-helper.h"
#include "util/params.h"
#include <time.h>

using namespace ns3;
using namespace lorawan;

NS_LOG_COMPONENT_DEFINE("CrashResponseSim");
Ptr<LoraChannel> createChannel();

int
main(int argc, char* argv[])
{
    uint32_t nNodes = 1;

    CommandLine cmd(__FILE__);
    cmd.AddValue("nNodes", "Number of nodes in network", nNodes);
    cmd.Parse(argc, argv);
    srand (time(NULL));
    

    // Set up logging
    LogComponentEnable ("CrashResponseSim", LOG_LEVEL_DEBUG);
    LogComponentEnable ("CrashResponseHelper", LOG_LEVEL_DEBUG);
    LogComponentEnable ("CrashResponse", LOG_LEVEL_DEBUG);
    NS_LOG_DEBUG(nNodes);
    
    LogComponentEnableAll (LOG_PREFIX_FUNC);
    LogComponentEnableAll (LOG_PREFIX_NODE);
    LogComponentEnableAll (LOG_PREFIX_TIME);

    Time::SetResolution(Time::NS);

    Ptr<LoraChannel> channel = createChannel();

    /************************
    *  Create the helpers  *
    ************************/
    NS_LOG_INFO ("Setting up helpers...");
    MobilityHelper mobility;
    mobility.SetPositionAllocator("ns3::RandomDiscPositionAllocator",
                                  "X",
                                  StringValue("100.0"),
                                  "Y",
                                  StringValue("100.0"),
                                  "Rho",
                                  StringValue(POSITION_STRING));
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");

    // Create the LoraPhyHelper
    LoraPhyHelper phyHelper = LoraPhyHelper ();
    phyHelper.SetChannel (channel);

    // Create the LorawanMacHelper
    LorawanMacHelper macHelper = LorawanMacHelper ();

    // Create the LoraHelper
    LoraHelper helper = LoraHelper ();

    /************************
    *  Create End Devices  *
    ************************/
    NS_LOG_INFO ("Creating the end device...");

    // Create a set of nodes
    NodeContainer endDevices;
    endDevices.Create (nNodes);

    // Assign a mobility model to the node
    mobility.Install (endDevices);

    // Create the LoraNetDevices of the end devices
    phyHelper.SetDeviceType (LoraPhyHelper::ED);
    macHelper.SetDeviceType (LorawanMacHelper::ED_A);
    helper.Install (phyHelper, macHelper, endDevices);

    /*********************************************
    *  Install applications on the end devices  *
    *********************************************/
    CrashResponseHelper crashResponseHelper;
    // Intermediates
    crashResponseHelper.SetSendTime (Seconds (SIMULATION_LENGTH + 1));
    crashResponseHelper.Install (endDevices);
    // Caller
    crashResponseHelper.SetSendTime (Seconds (INITIAL_CALL));
    crashResponseHelper.Install (endDevices.Get(0));

    /****************
    *  Simulation  *
    ****************/
    AnimationInterface anim("wireless-animation.xml"); // Mandatory
    Simulator::Stop (Seconds (SIMULATION_LENGTH));
    Simulator::Run ();
    Simulator::Destroy ();
    return 0;
}


Ptr<LoraChannel>
createChannel()
{
    NS_LOG_INFO ("Creating the channel...");

    Ptr<LogDistancePropagationLossModel> loss = CreateObject<LogDistancePropagationLossModel> ();
    loss->SetPathLossExponent (3.76);
    loss->SetReference (1, 7.7);

    Ptr<PropagationDelayModel> delay = CreateObject<ConstantSpeedPropagationDelayModel> ();
    return CreateObject<LoraChannel> (loss, delay);
}