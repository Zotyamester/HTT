#include "MobiNet.h"
#include "utils.hpp"

MobiNet::MobiNet() : DataPlan("MobiNet", 4000, 20, 5), free_sms_count(100) {}

int MobiNet::smsCost(int sms_count) const {
    int paid_sms_count = utils::max(0, sms_count - free_sms_count);
    return DataPlan::smsCost(paid_sms_count);
}
