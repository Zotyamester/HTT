#ifndef PROVIDER_H
#define PROVIDER_H

#include "utils/Vector.hpp"
#include "Serializable.h"
#include "plan/Plan.h"
#include "Client.h"
#include "DataUsage.h"
#include <iostream>

#include "memtrace.h"

/**
 * A szolgáltatót reprezentáló osztály tárolja a díjcsomagokat, valamint az ügyfelek adatait és adatforgalmát.
 */
class Provider {
private:
    /**
     * szolgáltató ügyfeleinek listája
     */
    utils::Vector<Client> clients;
public:
    /**
     * A konstruktor beolvassa a @p client_is és a @p usage_is adatfolyamokról a szolgáltató ügyfeleit, és
     * a hozzájuk tartozó adathasználatokat.
     * @param client_is ügyfeleket megadó bemeneti adatfolyam
     * @param usage_is adathasználatokat megadó bemeneti adatfolyam
     */
    explicit Provider(std::istream& client_is = std::cin, std::istream& usage_is = std::cin);

    /**
     * Kilistázza a szolgáltató ügyfeleit a hozzájuk tartozó adathasználat után fizetendő összeggel együtt.
     * @param os kimeneti adatfolyam
     */
    void createReport(std::ostream& os = std::cout);

    /**
     * Hozzáad a szolgáltatóhoz egy új ügyfelet.
     * @param client ügyfél
     */
    void addClient(const Client& client);
};

#endif // PROVIDER_H
