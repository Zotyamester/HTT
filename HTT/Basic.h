#ifndef BASIC_H
#define BASIC_H

#include "DataPlan.h"

class Basic : public DataPlan
{
public:
	int minuteFee(int minutes) const override;
	int smsFee(int sms_count) const override;
};

#endif // !BASIC_H
