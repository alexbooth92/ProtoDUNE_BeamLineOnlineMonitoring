#!/bin/sh

export LD_LIBRARY_PATH=/nfs/sw/BeamLineMonitoring/dip-5.6.3/lib64:/nfs/sw/rce/data-mon/boost_1_66_0/lib
exec /nfs/sw/BeamLineMonitoring/DIPExtraction/dipClient_MiscVars.exe -t 1438 -f 1 /scratch/DIPMiscVarsOutput `cat /nfs/sw/BeamLineMonitoring/DIPExtraction/SubscriptionLists/miscVars` &

