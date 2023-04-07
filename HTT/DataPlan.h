#ifndef DATAPLAN_H
#define DATAPLAN_H

class DataPlan
{
private:
	int base_price;
public:
	virtual ~DataPlan() {}
	int basePrice() const;
	virtual int minuteFee(int minutes) const = 0;
	virtual int smsFee(int sms_count) const = 0;
};

#endif
