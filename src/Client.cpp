#include "Client.h"

Client::Client() {
    // TODO
}

void Client::write(std::ostream &os) const {
    // TODO
}

void Client::read(std::istream &is) {
    // TODO
}

void Client::setDataPlan(DataPlan *data_plan) {
    this->data_plan = data_plan;
}

DataPlan const *Client::getDataPlan() const {
    return data_plan;
}
