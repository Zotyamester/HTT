#include "DataPlanFactory.h"

Basic DataPlanFactory::basic;
MobiNet DataPlanFactory::mobiNet;
SmsMax DataPlanFactory::smsMax;

DataPlan const &DataPlanFactory::getDataPlan(const utils::String &plan_name) {
    if (plan_name == basic.name())
        return basic;
    else if (plan_name == mobiNet.name())
        return mobiNet;
    else if (plan_name == smsMax.name())
        return smsMax;
    else
        throw std::runtime_error("No such plan available");
}
