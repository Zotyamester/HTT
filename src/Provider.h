#ifndef PROVIDER_H
#define PROVIDER_H

#include "Vector.hpp"
#include "Serializable.h"
#include "DataPlan.h"
#include "Client.h"
#include "DataUsage.h"
#include <iostream>

/**
 * A szolgáltatót reprezentáló osztály tárolja a díjcsomagokat, valamint az ügyfelek adatait és adatforgalmát.
 */
class Provider {
private:
    utils::Vector<Client> clients;
    utils::Vector<DataUsage> data_usages;
public:
    explicit Provider(std::istream &client_is = std::cin, std::istream &usage_is = std::cin);

    void listBills(std::ostream &os = std::cout);
};

#endif // PROVIDER_H
