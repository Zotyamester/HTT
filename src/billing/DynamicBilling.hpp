#ifndef DYNAMICBILLING_HPP
#define DYNAMICBILLING_HPP

#include "BillingStrategy.hpp"

#include "../memtrace.h"

/**
 * A dinamikus számlázást megvalósító osztály, mely adott egységnyi adathasználatot ingyen lehetővé tesz,
 * és csak az afölötti adathasználat után számláz arányosan.
 * @tparam T milyen típusú adathasználat utáni számlázást ír le (pl. int, double)
 */
template <typename T>
class DynamicBilling : public BillingStrategy<T> {
private:
    // ingyenes kvóta
    T free_usage;
    // tarifa
    int cost_per_unit;
public:
    /**
     * A konstruktor beállítja a számlázás paramétereit.
     * @param free_usage ingyenes kvóta
     * @param cost_per_unit tarifa
     */
    DynamicBilling(T free_usage, int cost_per_unit) : free_usage(free_usage), cost_per_unit(cost_per_unit) {}

    int cost(T usage) const override {
        if (usage <= free_usage)
            return 0;
        return (usage - free_usage) * cost_per_unit;
    }

    BillingStrategy<T>* clone() const override {
        return new DynamicBilling<T>(*this);
    }
};

#endif // DYNAMICBILLING_HPP
