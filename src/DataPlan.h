#ifndef DATAPLAN_H
#define DATAPLAN_H

#include "String.h"
#include "DataUsage.h"

/**
 * A DataPlan egy absztrakt osztály, ami definiálja a díjcsomagok közös tulajdonságait és interfészét.
 */
class DataPlan {
private:
    utils::String plan_name;
    int base_price;
    int minute_price;
    int sms_price;
protected:
    /**
     * Csak a leszármazottak számára elérhető konstruktor, amely beállítja a csomag adatait.
     * @param plan_name név
     * @param basePrice alapár
     * @param minutePrice percdíj
     * @param smsPrice SMS díj
     */
    DataPlan(const utils::String &plan_name, int basePrice, int minutePrice, int smsPrice);

public:
    /**
     * Virtuális destruktor, hogy a leszármazott objektumokat heterogén kollekcióként lehessen kezelni.
     */
    virtual ~DataPlan() {}

    /**
     * Visszaadja az csomag nevét.
     * @return a csomag neve
     */
    utils::String const &name() const;

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
    virtual int minuteCost(int minutes) const;

    /**
     * Kiszámolja egy ügyfél által elküldött SMS-ek után fizetendő összeget a díjcsomag alapján.
     * @param sms_count az SMS-ek száma
     * @return a fizetendő összeg (forintban)
     */
    virtual int smsCost(int sms_count) const;

    /**
     * Kiszámolja egy ügyfél által a teljes adathasználata után fizetendő összeget.
     * @param usage az adathasználat részleteit egységbezáró objektum
     * @return a fizetendő összeg (forintban)
     */
    int totalCost(DataUsage const &usage) const;
};

#endif // DATAPLAN_H
