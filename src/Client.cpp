#include "Client.h"

#include <stdexcept>
#include "plan/PlanFactory.h"

Client::Client() : name(), address(), phone(), data_plan(nullptr), usages() {}

Client::Client(const utils::String& name, const utils::String& address, const utils::String& phone,
               const utils::String& plan_name, const utils::Vector<DataUsage>& usages) : name(name), address(address),
               phone(phone), data_plan(PlanFactory::createPlan(plan_name)), usages(usages) {}

const utils::String& Client::getPhone() const {
    return phone;
}

void Client::writePersonalData(std::ostream& os) const {
    os << name << std::endl;
    os << address << std::endl;
    os << phone << std::endl;
}

void Client::writeBilling(std::ostream& os) const {
    if (data_plan == nullptr)
        throw std::logic_error("No data plan was attached to the client yet.");

    writePersonalData(os);
    for (const DataUsage& usage : usages) {
        os << " - " << usage.getDate() << std::endl;
        int minute_cost = data_plan->minuteCost(usage.getMinutes());
        os << "   - fee after minutes: " << minute_cost << " Ft" << std::endl;
        int sms_cost = data_plan->smsCost(usage.getSmsCount());
        os << "   - fee after SMS: " << sms_cost << " Ft" << std::endl;
        int data_cost = data_plan->dataCost(usage.getData());
        os << "   - fee after mobile data: " << data_cost << " Ft" << std::endl;
        int total = data_plan->baseCost() + minute_cost + sms_cost + data_cost;
        os << "   - total: " << total << " Ft" << std::endl;
    }
}

void Client::addDataUsage(const DataUsage& usage) {
    if (usage.getPhone() != phone)
        throw std::invalid_argument("DataUsage is not related to Client");
    usages.push(usage);
}

void Client::write(std::ostream& os) const {
    writePersonalData(os);
    if (data_plan != nullptr)
        os << data_plan->name() << std::endl;
}

void Client::read(std::istream& is) {
    getline(is, name);
    getline(is, address);
    getline(is, phone);

    utils::String plan_line;
    getline(is, plan_line);
    data_plan = PlanFactory::createPlan(plan_line);
    is.ignore(1);
}
