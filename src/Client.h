#ifndef CLIENT_H
#define CLIENT_H

#include "utils/String.h"
#include "plan/Plan.h"
#include "Serializable.h"
#include "utils/Vector.hpp"

class Client : public Serializable {
private:
    // név
    utils::String name;
    // cím
    utils::String address;
    // telefonszám (az ügyfél azonosítója)
    utils::String phone;
    // díjcsomag
    const Plan* data_plan;
    // havi adathasználatok listája
    utils::Vector<DataUsage> usages;
public:
    /**
     * Alapértelmezett konstruktor.
     * Az osztály típusú adattagoknak a beépített konstruktorát implicit meghívja,
     * majd az adatcsomagra mutató pointert kezdetben nullptr értékre inicializálja.
     */
    Client();

    /**
     * Értékekkel inicializáló konstruktor.
     * @param name név
     * @param address cím
     * @param phone telefonszám
     * @param plan_name díjcsomag neve
     * @param usages havi adathasználatok listája
     */
    Client(const utils::String& name, const utils::String& address, const utils::String& phone,
           const utils::String& plan_name, const utils::Vector<DataUsage>& usages);

    /**
     * Visszatér a telefonszámmal.
     * @return telefonszám
     */
    const utils::String& getPhone() const;

    /**
     * Kiírja a kimeneti adatfolyamra az ügyfél adatait.
     * @param os kimeneti adatfolyam
     */
    void writePersonalData(std::ostream& os) const;

    /**
     * Kiírja a kimeneti adatfolyamra az ügyfél számláit.
     * @param os kimeneti adatfolyam
     */
    void writeBilling(std::ostream& os) const;

    /**
     * Hozzáad egy adathasználatot a listához.
     *
     * Kivételt dob, ha az adathasználat nem az ügyféllhez tartozik (vagyis nem egyező telefonszám esetén)!
     * @param usage adathasználat
     * @throw std::invalid_argument
     */
    void addDataUsage(const DataUsage& usage);

    void write(std::ostream& os) const override;

    void read(std::istream& is) override;
};

#endif // CLIENT_H
