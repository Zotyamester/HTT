#ifndef PROVIDER_H
#define PROVIDER_H

#include "utils/Vector.hpp"
#include "Serializable.h"
#include "plan/Plan.h"
#include "Client.h"
#include "DataUsage.h"
#include <iostream>

/**
 * A szolgáltatót reprezentáló osztály tárolja a díjcsomagokat, valamint az ügyfelek adatait és adatforgalmát.
 */
class Provider {
private:
    utils::Vector<Client> clients;
public:
    explicit Provider(std::istream& client_is = std::cin, std::istream& usage_is = std::cin);

    /**
     * Kilistázza a szolgáltató ügyfeleit a hozzájuk tartozó adathasználat után fizetendő összeggel együtt.
     * @param os a kimeneti adatfolyam
     */
    void createReport(std::ostream& os = std::cout);

    void addClient(const Client& client);
};

#endif // PROVIDER_H
