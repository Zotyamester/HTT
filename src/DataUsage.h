#ifndef DATAUSAGE_H
#define DATAUSAGE_H

#include "Serializable.h"
#include "utils/String.h"

#include "memtrace.h"

/**
 * Egy ügyfél adathasználatát leíró osztály.
 */
class DataUsage : public Serializable {
private:
    /**
     * az ügyfél telefonszáma, akihez az adatok rögzítve lettek
     */
    utils::String phone;
    /**
     * a számlázás hónapja
     */
    utils::String date;
    /**
     * híváspercek
     */
    int minutes;
    /**
     * SMS-ek száma
     */
    int sms_count;
    /**
     * belföldi adathasználat (MB-ban)
     */
    double data;
public:
    /**
     * Az adathasználat részleteit beállító konstruktor.
     * @param phone az ügyfél telefonszáma, akihez az adatok rögzítve lettek
     * @param date a számlázás hónapja
     * @param minutes híváspercek
     * @param sms_count SMS-ek száma
     * @param data belföldi adathasználat (MB-ban)
     */
    explicit DataUsage(const utils::String& phone = "", const utils::String& date = "", int minutes = 0,
                       int sms_count = 0, double data = 0.0);

    /**
     * Visszatér az ügyfél telefonszámával.
     * @return telefonszám
     */
    utils::String const& getPhone() const;

    /**
     * Visszatér a számlázás hónapjával.
     * @return számlázás hónapja
     */
    const utils::String& getDate() const;

    /**
     * Visszatér a híváspercekkel.
     * @return híváspercek
     */
    int getMinutes() const;

    /**
     * Visszatér az SMS-ek számával.
     * @return SMS-ek száma
     */
    int getSmsCount() const;

    /**
     * Visszatér az adathasználattal.
     * @return adathasználat (MB-ban)
     */
    double getData() const;

    void write(std::ostream& os) const override;

    void read(std::istream& is) override;
};

#endif // DATAUSAGE_H
