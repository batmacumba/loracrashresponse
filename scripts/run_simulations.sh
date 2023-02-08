# eXtreme Go Horse Methodology ;)

rm ../../data/10
for i in $(seq 1 1 30)
do
   ~/Developer/ns-3/ns3 run "scratch/crash-response/crash-response-sim.cc --nNodes=10" \
>> ../../data/10 2>&1
done

rm ../../data/20
for i in $(seq 1 1 30)
do
   ~/Developer/ns-3/ns3 run "scratch/crash-response/crash-response-sim.cc --nNodes=20" \
>> ../../data/20 2>&1
done

rm ../../data/40
for i in $(seq 1 1 30)
do
   ~/Developer/ns-3/ns3 run "scratch/crash-response/crash-response-sim.cc --nNodes=40" \
>> ../../data/40 2>&1
done

rm ../../data/80
for i in $(seq 1 1 30)
do
   ~/Developer/ns-3/ns3 run "scratch/crash-response/crash-response-sim.cc --nNodes=80" \
>> ../../data/80 2>&1
done

rm ../../data/160
for i in $(seq 1 1 30)
do
   ~/Developer/ns-3/ns3 run "scratch/crash-response/crash-response-sim.cc --nNodes=160" \
>> ../../data/160 2>&1
done

rm ../../data/320
for i in $(seq 1 1 30)
do
   ~/Developer/ns-3/ns3 run "scratch/crash-response/crash-response-sim.cc --nNodes=320" \
>> ../../data/320 2>&1
done