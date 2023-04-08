#include "DataPlan.h"

DataPlan::DataPlan(int basePrice, int minutePrice, int smsPrice) : base_price(basePrice), minute_price(minutePrice),
                                                                   sms_price(smsPrice) {}

int DataPlan::basePrice() const {
    return base_price;
}

int DataPlan::minuteFee(int minutes) const {
    return minute_price * minutes;
}

int DataPlan::smsFee(int sms_count) const {
    return sms_price * sms_count;
}
