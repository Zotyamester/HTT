#ifndef PROVIDER_H
#define PROVIDER_H

#include "Vector.h"
#include "Serializable.h"
#include <iostream>

class Provider : public Serializable
{
private:
	utils::Vector<DataPlan*> data_plans;
	utils::Vector<Client> clients;
	utils::Vector<DataUsage> data_usages;
public:
	Provider(const char* filename);
	~Provider();

	void write(std::ostream& os) const override;
	void read(std::istream& is) override;

	void listBills(std::ostream& os);
};

#endif // !PROVIDER_H
