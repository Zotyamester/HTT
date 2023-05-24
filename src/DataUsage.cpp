#include "DataUsage.h"

#include "utils/String.h"

#include "memtrace.h"

DataUsage::DataUsage(const utils::String& phone, const utils::String& date, int minutes, int sms_count, double data)
        : phone(phone), date(date), minutes(minutes), sms_count(sms_count), data(data) {}

utils::String const& DataUsage::getPhone() const {
    return phone;
}

const utils::String& DataUsage::getDate() const {
    return date;
}

int DataUsage::getMinutes() const {
    return minutes;
}

int DataUsage::getSmsCount() const {
    return sms_count;
}

double DataUsage::getData() const {
    return data;
}

void DataUsage::write(std::ostream& os) const {
    os << phone << std::endl;
    os << date << std::endl;
    os << minutes << ' ' << sms_count << ' ' << data << std::endl;
}

void DataUsage::read(std::istream& is) {
    getline(is, phone);
    getline(is, date);
    (is >> minutes >> sms_count >> data).ignore(1);
    if (data < 0)
        throw std::runtime_error("Mobile data usage must not be negative");
}
