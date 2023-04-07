#ifndef BASIC_H
#define BASIC_H

#include "DataPlan.h"

class Basic : public DataPlan
{
private:
	int minute_price;
	int sms_price;
public:
	int minuteFee(int minutes) const override;
	int smsFee(int sms_count) const override;
};

#endif // !BASIC_H
