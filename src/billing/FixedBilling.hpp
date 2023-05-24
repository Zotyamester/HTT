#ifndef FIXEDBILLING_HPP
#define FIXEDBILLING_HPP

#include "BillingStrategy.hpp"

#include "../memtrace.h"

/**
 * A fix számlázást megvalósító osztály, mely minden adathasználatot arányosan számláz a tarifa szerint.
 * @tparam T milyen típusú adathasználat utáni számlázást ír le (pl. int, double)
 */
template <typename T>
class FixedBilling : public BillingStrategy<T> {
private:
    // tarifa
    int cost_per_unit;
public:
    /**
     * A konstruktor beállítja a számlázás paramétereit.
     * @param cost_per_unit tarifa
     */
    explicit FixedBilling(int cost_per_unit) : cost_per_unit(cost_per_unit) {}

    int cost(T usage) const override {
        return usage * cost_per_unit;
    }

    BillingStrategy<T>* clone() const override {
        return new FixedBilling<T>(*this);
    }
};

#endif // FIXEDBILLING_HPP
