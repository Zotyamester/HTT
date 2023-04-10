#include "DataPlan.h"

DataPlan::DataPlan(const utils::String &plan_name, int basePrice, int minutePrice, int smsPrice)
        : plan_name(plan_name), base_price(basePrice), minute_price(minutePrice),
          sms_price(smsPrice) {}

utils::String const &DataPlan::name() const {
    return plan_name;
}

int DataPlan::baseCost() const {
    return base_price;
}

int DataPlan::minuteCost(int minutes) const {
    return minute_price * minutes;
}

int DataPlan::smsCost(int sms_count) const {
    return sms_price * sms_count;
}

int DataPlan::totalCost(DataUsage const &usage) const {
    return baseCost() + minuteCost(usage.getMinutes()) + smsCost(usage.getSmsCount());
}
