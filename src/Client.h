#ifndef CLIENT_H
#define CLIENT_h

#include "String.h"
#include "Serializable.h"

class Client : public Serializable
{
private:
	utils::String name;
	utils::String address;
	utils::String phone;
	DataPlan const* data_plan;
public:
	Client();

	void write(std::ostream& os) const override;
	void read(std::istream& is) override;

	void setDataPlan(DataPlan* data_plan);
	DataPlan const* getDataPlan() const;
};

#endif // !CLIENT_H
