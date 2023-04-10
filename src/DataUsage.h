#ifndef DATAUSAGE_H
#define DATAUSAGE_H

#include "Serializable.h"
#include "String.h"

class DataUsage : public Serializable {
private:
    utils::String phone;
    int minutes;
    int sms_count;
public:
    explicit DataUsage(const utils::String &phone = "", int minutes = 0, int smsCount = 0);

    utils::String const &getPhone() const;

    int getMinutes() const;

    int getSmsCount() const;

    void write(std::ostream &os) const override;

    void read(std::istream &is) override;
};

#endif // DATAUSAGE_H
