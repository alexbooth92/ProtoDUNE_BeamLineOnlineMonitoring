DIPHOME=/nfs/sw/BeamLineMonitoring/dip-5.6.3

CC = g++
CFLAGS = -Wall -ansi -I $(DIPHOME)/include -std=c++11

DLIB = $(DIPHOME)/lib64/libdip.so -lpthread -ldl -llog4cplus

all:	dip-client
#all:	dip-client_MiscVars

dip-client:	dipClient_ToROOTFile.C
	$(CC) $(CFLAGS) dipClient_ToROOTFile.C -L$(DIPHOME)/lib64 $(DLIB) -o dipClient.exe $(LIBS) `root-config --cflags --glibs` 

#dip-client_MiscVars:	dipClient_MiscVars.C
#	$(CC) $(CFLAGS) dipClient_MiscVars.C -L$(DIPHOME)/lib64 $(DLIB)  -o dipClient_MiscVars.exe $(LIBS) `root-config --cflags --glibs` 

#export LD_LIBRARY_PATH=/nfs/sw/BeamLineMonitoring/dip-5.6.3/lib64:/nfs/sw/rce/data-mon/boost_1_66_0/lib
