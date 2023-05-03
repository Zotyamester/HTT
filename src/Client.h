#ifndef CLIENT_H
#define CLIENT_H

#include "utils/String.h"
#include "plan/Plan.h"
#include "Serializable.h"
#include "utils/Vector.hpp"

class Client : public Serializable {
private:
    // név
    utils::String name;
    // cím
    utils::String address;
    // telefonszám (az ügyfél azonosítója)
    utils::String phone;
    // díjcsomag
    const Plan* data_plan;
    // havi adathasználatok listája
    utils::Vector<DataUsage> usages;
public:
    Client();

    Client(const utils::String& name, const utils::String& address, const utils::String& phone,
           const utils::String& plan_name, const utils::Vector<DataUsage>& usages);

    const utils::String& getPhone() const;

    const Plan& getDataPlan() const;

    void write(std::ostream& os) const override;

    void read(std::istream& is) override;

    void writeBilling(std::ostream& os) const;

    void writePersonalData(std::ostream& os) const;

    void addDataUsage(const DataUsage& usage);
};

#endif // CLIENT_H
