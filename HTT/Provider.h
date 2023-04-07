#ifndef PROVIDER_H
#define PROVIDER_H

#include "Vector.h"
#include <iostream>

class Provider
{
private:
	utils::Vector<DataPlan*> data_plans;
	utils::Vector<Client> clients;
	utils::Vector<DataUsage> data_usages;
public:
	Provider(const char* filename);
	~Provider();
	void listBills(std::ostream& os);
};

#endif // !PROVIDER_H
