#ifndef BILLINGSTRATEGY_HPP
#define BILLINGSTRATEGY_HPP

#include "../memtrace.h"

/**
 * Egy számlázási stratégiát leíró osztály.
 * @tparam T milyen típusú adathasználat utáni számlázást ír le (pl. int, double)
 */
template<typename T>
class BillingStrategy {
public:
    /**
     * Kiszámolja, mennyit kell adott adathasználat után fizetni (forintban).
     * @param usage adathasználat
     * @return fizetendő összeg (forintban)
     */
    virtual int cost(T usage) const = 0;

    /**
     * Virtuális destruktor, hogy a leszármazottak (erőforrásai) kezelhetőek maradjanak az ősosztály pointerén
     * keresztül is.
     */
    virtual ~BillingStrategy() = default;

    /**
     * A konkrét számlázási stratégiát lemásoló függvény.
     * @return visszatér a számlázási stratégia egy dinamikusan foglalt másolatával
     */
    virtual BillingStrategy<T>* clone() const = 0;
};

#endif // BILLINGSTRATEGY_HPP
