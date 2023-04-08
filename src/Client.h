#ifndef CLIENT_H
#define CLIENT_h

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

    virtual void write(std::ostream &os) const;

    virtual void read(std::istream &is);

    void setDataPlan(DataPlan *data_plan);

    DataPlan const *getDataPlan() const;
};

#endif // CLIENT_H
