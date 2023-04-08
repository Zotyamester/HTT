#ifndef DATAUSAGE_H
#define DATAUSAGE_H

#include "Serializable.h"
#include "String.h"
#include "Client.h"

class DataUsage : public Serializable {
private:
    Client const* client;
    int minutes;
    int sms_count;
public:
    int getMinutes() const;

    int getSmsCount() const;

    void write(std::ostream &os) const override;

    void read(std::istream &is) override;
};

#endif // DATAUSAGE_H
