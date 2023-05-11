Experiments related to the paper "A Crash Response System using LoRa-based V2X Communications" (Authored by Bruno Carneiro da Cunha, Daniel Macêdo Batista, Roberto Hirata Jr., Kifayat Ullah) presented at the 6th International Workshop on Intelligent Transportation and Autonomous Vehicles Technologies (ITAVT 2023) in conjunction with IEEE/IFIP Network Operations and Management Symposium (NOMS 2023). The experiments were planned to show the performance (packet delivery ratio,latency, and network coverage) of an automated crash response system based on LoRa communications.

### Installing:

1. Download ns-3:
	https://www.nsnam.org

2. Download and install the LoRaWAN library:
	https://github.com/signetlabdei/lorawan

3. Move or link this folder into ./ns3/scratch

### Running:

$ ./ns3 run "scratch/crash-response/crash-response-sim.cc --nNodes=10"
