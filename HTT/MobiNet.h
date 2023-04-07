#ifndef MOBINET_H
#define MOBINET_H

#include "DataPlan.h"

class MobiNet : public DataPlan
{
private:
	int free_sms_count;
public:
	int minuteFee(int minutes) const override;
	int smsFee(int sms_count) const override;
};

#endif // !MOBINET_H
