#ifndef CLIENT_H
#define CLIENT_H

#include "String.h"
#include "DataPlan.h"
#include "Serializable.h"

class Client : public Serializable {
private:
    utils::String name;
    utils::String address;
    utils::String phone;
    DataPlan const *data_plan;
public:
    Client();

    Client(const utils::String &name, const utils::String &address, const utils::String &phone,
           const utils::String &plan_name);

    const utils::String &getPhone() const;

    const DataPlan &getDataPlan() const;

    void write(std::ostream &os) const override;

    void read(std::istream &is) override;
};

#endif // CLIENT_H
