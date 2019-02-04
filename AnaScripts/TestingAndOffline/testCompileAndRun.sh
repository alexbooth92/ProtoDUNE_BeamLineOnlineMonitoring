#!/bin/sh

echo "COMPILING"
#g++ -std=c++11 -o AnaTest.exe AnaTest.C ../BeamLineClasses/class_AcquisitionXBPF.C ../BeamLineClasses/class_AcquisitionXBTF.C ../BeamLineClasses/class_Detector.C ../BeamLineClasses/class_BeamLine.C ../BeamLineClasses/class_DetectorCoincidences.C ../BeamLineClasses/unpack.C ../BeamLineClasses/plotting.C `root-config --cflags --glibs`
g++ -std=c++11 -o AnaTest.exe AnaTest.C ../BeamLineClasses/class_AcquisitionXBPF.C ../BeamLineClasses/class_AcquisitionXBTF.C ../BeamLineClasses/class_Detector.C ../BeamLineClasses/class_BeamLine.C ../BeamLineClasses/class_DetectorCoincidences.C ../BeamLineClasses/unpack.C ../BeamLineClasses/plotting.C `root-config --cflags --glibs`
echo "FINISHED COMPILING"

detectorList=`cat /nfs/sw/BeamLineMonitoring/DIPExtraction/SubscriptionLists/detectors`
filesList=`cat /nfs/sw/BeamLineMonitoring/AnaScripts/TestingAndOffline/FileLists/filesList_180911_smallsample.txt`

./AnaTest.exe true $filesList $detectorList
#./AnaTest.exe true `cat firstFiles.txt` $detectorList
#./AnaTest.exe true `cat secondFiles.txt` $detectorList
#./AnaTest.exe true `cat thirdFiles.txt` $detectorList
#./AnaTest.exe true `cat fourthFiles.txt` $detectorList
#./AnaTest.exe true `cat filesList_180908_1700_190909_0000.txt` $detectorList
#./AnaTest.exe true /data0/BeamInstOutput/Pre_181003_1900/Trees_DIPRaw/eventsData_1536629921.root $detectorList
