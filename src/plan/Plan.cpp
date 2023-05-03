#include "Plan.h"

Plan::Plan(const utils::String& plan_name, int base_price, BillingStrategy<int>* minute_billing,
           BillingStrategy<int>* sms_billing, BillingStrategy<double>* data_billing) : plan_name(plan_name),
                                                                                       base_price(base_price),
                                                                                       minute_billing(minute_billing),
                                                                                       sms_billing(sms_billing),
                                                                                       data_billing(data_billing) {}

Plan::~Plan() {
    delete minute_billing;
    delete sms_billing;
    delete data_billing;
}

const utils::String& Plan::name() const {
    return plan_name;
}

int Plan::baseCost() const {
    return base_price;
}

int Plan::minuteCost(int minutes) const {
    return minute_billing->cost(minutes);
}

int Plan::smsCost(int sms_count) const {
    return sms_billing->cost(sms_count);
}

int Plan::dataCost(double data_usage) const {
    return data_billing->cost(data_usage);
}
