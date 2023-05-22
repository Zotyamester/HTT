#ifndef DATAPLAN_H
#define DATAPLAN_H

#include "../utils/String.h"
#include "../DataUsage.h"
#include "../billing/BillingStrategy.hpp"

/**
 * A Plan egy absztrakt osztály, ami definiálja a díjcsomagok közös tulajdonságait és interfészét.
 */
class Plan {
private:
    /**
     * csomag neve
     */
    utils::String plan_name;
    /**
     * alapdíj
     */
    int base_price;
    /**
     * híváspercek számlázási stratégiája
     */
    BillingStrategy<int>* minute_billing;
    /**
     * SMS-ek számlázási stratégiája
     */
    BillingStrategy<int>* sms_billing;
    /**
     * mobil-adathasználat számlázási stratégiája
     */
    BillingStrategy<double>* data_billing;
protected:
    /**
     * Csak a leszármazottak számára elérhető konstruktor, amely beállítja a csomag adatait.
     */
    Plan(const utils::String& plan_name, int base_price, BillingStrategy<int>* minute_billing,
         BillingStrategy<int>* sms_billing, BillingStrategy<double>* data_billing);

public:
    /**
     * Virtuális destruktor, hogy a leszármazott objektumokat heterogén kollekcióként lehessen kezelni.
     * Felszabadítja továbbá a számlázási stratégiákat.
     */
    virtual ~Plan();

    /**
     * Visszaadja a csomag nevét.
     * @return csomag neve
     */
    const utils::String& name() const;

    /**
     * Visszatér a csomag alap díjszabásával.
     * @return fizetendő összeg (forintban)
     */
    int baseCost() const;

    /**
     * Kiszámolja egy ügyfél által a hívások után fizetendő összeget a díjcsomag alapján.
     * @param minutes híváspercek
     * @return fizetendő összeg (forintban)
     */
    int minuteCost(int minutes) const;

    /**
     * Kiszámolja egy ügyfél által elküldött SMS-ek után fizetendő összeget a díjcsomag alapján.
     * @param sms_count SMS-ek száma
     * @return fizetendő összeg (forintban)
     */
    int smsCost(int sms_count) const;

    /**
     * Kiszámolja egy ügyfél által az mobil-adathasználat után fizetendő összeget a díjcsomag alapján.
     * @param data_usage mobil-adathasználat
     * @return fizetendő összeg (forintban)
     */
    int dataCost(double data_usage) const;
};

#endif // DATAPLAN_H
