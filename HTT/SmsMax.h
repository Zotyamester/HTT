#ifndef SMSMAX_H
#define SMSMAX_H

#include "DataPlan.h"

class SmsMax : public DataPlan
{
public:
	int minuteFee(int minutes) const override;
	int smsFee(int sms_count) const override;
};

#endif // !SMSMAX_H
