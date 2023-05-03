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
    utils::String plan_name;
    int base_price;
    BillingStrategy<int>* minute_billing;
    BillingStrategy<int>* sms_billing;
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
     * Visszaadja az csomag nevét.
     * @return a csomag neve
     */
    const utils::String& name() const;

    /**
     * Visszatér a csomag alap díjszabásával.
     * @return a fizetendő összeg (forintban)
     */
    int baseCost() const;

    /**
     * Kiszámolja egy ügyfél által a percdíjas hívások után fizetendő összeget a díjcsomag alapján.
     * @param minutes a híváspercek
     * @return a fizetendő összeg (forintban)
     */
    int minuteCost(int minutes) const;

    /**
     * Kiszámolja egy ügyfél által elküldött SMS-ek után fizetendő összeget a díjcsomag alapján.
     * @param sms_count az SMS-ek száma
     * @return a fizetendő összeg (forintban)
     */
    int smsCost(int sms_count) const;

    int dataCost(double data_usage) const;
};

#endif // DATAPLAN_H
