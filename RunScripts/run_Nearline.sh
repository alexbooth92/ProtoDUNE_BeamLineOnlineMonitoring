#!/bin/sh

rm -f /data0/BeamInstOutput/lastHour.txt
CURRENTTIME=`date +%s`
INTEGRATIONTIME=3780
BUFFER=180
for FILENAME in /scratch/BeamInstOutput/HistogramsAndTrees_DIPProcessed/Analyse_BIBL_Hist_*root
  do
    ENDTIME=$(echo $FILENAME | cut -c 86-95)
    if [ $ENDTIME -gt $((CURRENTTIME-INTEGRATIONTIME)) ]
      then
      if [ $ENDTIME -lt $((CURRENTTIME-BUFFER)) ]
        then
        echo $FILENAME >> /data0/BeamInstOutput/lastHour.txt 
      fi
    fi
  done

hadd -f /data0/BeamInstOutput/lastHour.root `cat /data0/BeamInstOutput/lastHour.txt`

