#ifndef DATAPLAN_H
#define DATAPLAN_H

/**
 * A DataPlan egy absztrakt osztály, ami definiálja a díjcsomagok közös tulajdonságait és interfészét.
 */
class DataPlan {
private:
    int base_price;
    int minute_price;
    int sms_price;
public:
    DataPlan(int basePrice, int minutePrice, int smsPrice);

    virtual ~DataPlan() {}

    /**
     * Visszatér a csomag alap díjszabásával.
     * @return a fizetendő összeg (forintban)
     */
    int basePrice() const;

    /**
     * Kiszámolja egy ügyfél által a percdíjas hívások után fizetendő összeget a díjcsomag alapján.
     * @param minutes - a híváspercek
     * @return a fizetendő összeg (forintban)
     */
    virtual int minuteFee(int minutes) const;

    /**
     * Kiszámolja egy ügyfél által elküldött SMS-ek után fizetendő összeget a díjcsomag alapján.
     * @param sms_count - az SMS-ek száma
     * @return a fizetendő összeg (forintban)
     */
    virtual int smsFee(int sms_count) const;
};

#endif // DATAPLAN_H
