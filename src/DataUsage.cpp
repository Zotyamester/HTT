#include "DataUsage.h"

#include "String.h"

DataUsage::DataUsage(const utils::String &phone, int minutes, int smsCount) : phone(phone), minutes(minutes),
                                                                              sms_count(smsCount) {}

utils::String const &DataUsage::getPhone() const {
    return phone;
}

int DataUsage::getMinutes() const {
    return minutes;
}

int DataUsage::getSmsCount() const {
    return sms_count;
}

void DataUsage::write(std::ostream &os) const {
    os << phone << minutes << sms_count << std::endl;
}

void DataUsage::read(std::istream &is) {
    (is >> phone >> minutes >> sms_count).ignore(1);
}
