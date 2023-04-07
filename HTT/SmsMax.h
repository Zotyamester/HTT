#ifndef SMSMAX_H
#define SMSMAX_H

#include "DataPlan.h"

class SmsMax : public DataPlan
{
private:
	int minute_price;
public:
	int minuteFee(int minutes) const override;
	int smsFee(int sms_count) const override;
};

#endif // !SMSMAX_H
