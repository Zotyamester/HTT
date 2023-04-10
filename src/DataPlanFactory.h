#ifndef DATAPLANFACTORY_H
#define DATAPLANFACTORY_H


#include "DataPlan.h"
#include "Basic.h"
#include "MobiNet.h"
#include "SmsMax.h"

class DataPlanFactory {
private:
    static Basic basic;
    static MobiNet mobiNet;
    static SmsMax smsMax;
public:
    static DataPlan const& getDataPlan(const utils::String& plan_name);
};


#endif // DATAPLANFACTORY_H
