#include "Client.h"

#include <stdexcept>
#include "DataPlanFactory.h"

Client::Client() : name(), address(), phone(), data_plan(nullptr) {}

Client::Client(const utils::String &name, const utils::String &address, const utils::String &phone,
               const utils::String &plan_name) : name(name), address(address), phone(phone),
                                                 data_plan(&DataPlanFactory::getDataPlan(plan_name)) {}

const utils::String &Client::getPhone() const {
    return phone;
}

const DataPlan &Client::getDataPlan() const {
    if (data_plan == nullptr)
        throw std::runtime_error("No data plan was attached to the client yet.");
    return *data_plan;
}

void Client::write(std::ostream &os) const {
    os << name << std::endl;
    os << address << std::endl;
    os << phone << std::endl;

    os << data_plan->name() << std::endl;
}

// TODO: this isn't exception-safe
void Client::read(std::istream &is) {
    getline(is, name);
    getline(is, address);
    getline(is, phone);

    utils::String plan_name;
    getline(is, plan_name);
    data_plan = &DataPlanFactory::getDataPlan(plan_name);
}
