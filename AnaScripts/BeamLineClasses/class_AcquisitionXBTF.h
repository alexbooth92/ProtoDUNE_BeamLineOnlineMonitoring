#ifndef CLASS_AQCUISITIONXBTF_H
#define CLASS_AQCUISITIONXBTF_H

#include <iostream>
#include <array>
#include <bitset>
#include <vector>

class AcquisitionXBTF{

  public:
    bool   fIsEmpty;
    double fTimestamp;
    double fFirstTriggerTimestamp;
    double fLastTriggerTimestamp;
    unsigned int fTimestampCount;
    struct EventRecordRaw{
           unsigned int  fFrac;
           unsigned long fCoarse;
           unsigned long fSeconds;
    };
    struct EventRecordHR{
           unsigned long fSeconds;
           double        fSubSeconds;
           double        fSeconds_FullTime;
    };
    
    AcquisitionXBTF();
    bool         isEmpty();
    double       getTimestamp();
    double       getFirstTriggerTimestamp();
    double       getLastTriggerTimestamp();
    unsigned int getTimestampCount();
    std::vector<EventRecordRaw> getDataRaw();
    std::vector<EventRecordHR>  getDataHR();
    void addAcqDetails(double cTimestamp, unsigned int cTimestampCount);
    void addEventRecord(EventRecordRaw cEventRecord);
    void printRaw();
    void printHR();
    void setEmpty(bool cIsEmpty);

  private:
    EventRecordHR fTimestampCountordHR;
    std::vector<EventRecordRaw> fVecDataRec;
    std::vector<EventRecordHR> fVecDataRecHR;

    EventRecordHR decodeRaw(EventRecordRaw const &cVecDataRec);

};

#endif
