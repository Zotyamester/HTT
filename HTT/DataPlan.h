#ifndef DATAPLAN_H
#define DATAPLAN_H

class DataPlan
{
private:
	int base_price;
public:
	virtual ~DataPlan() {}
	int basePrice() const;
	virtual int minuteFee(int minutes) const;
	virtual int smsFee(int sms_count) const;
};

#endif
