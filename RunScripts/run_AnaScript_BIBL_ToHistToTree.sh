#!/bin/sh

newFileList=`cat /scratch/BeamInstOutput/Trees_DIPRaw/filesList_BIBL_ToHistToTree.txt`
detectorList=`cat /nfs/sw/BeamLineMonitoring/DIPExtraction/SubscriptionLists/detectors`
echo -n > /scratch/BeamInstOutput/Trees_DIPRaw/filesList_BIBL_ToHistToTree.txt
/nfs/sw/BeamLineMonitoring/AnaScripts/Analyse_BIBL_ToHistToTree.exe true $newFileList $detectorList
/nfs/sw/BeamLineMonitoring/AnaScripts/TestingAndOffline/ROOTScripts/makeTOFChannelByChannel_Online.exe `cat /scratch/BeamInstOutput/HistogramsAndTrees_DIPProcessed/latestTreeFile.txt` `cat /scratch/BeamInstOutput/HistogramsAndTrees_DIPProcessed/latestHistFile.txt`
cp `cat /scratch/BeamInstOutput/HistogramsAndTrees_DIPProcessed/latestHistFile.txt` /scratch/BeamInstOutput/HistogramsAndTrees_DIPProcessed/latestHistFile.root
cp `cat /scratch/BeamInstOutput/HistogramsAndTrees_DIPProcessed/latestTreeFile.txt` /scratch/BeamInstOutput/HistogramsAndTrees_DIPProcessed/latestTreeFile.root
cp /scratch/BeamInstOutput/HistogramsAndTrees_DIPProcessed/latestHistFile.root /data0/BeamInstOutput/
cp /scratch/BeamInstOutput/HistogramsAndTrees_DIPProcessed/latestHistFile.root /nfs/rscratch/BeamInstOutput/
