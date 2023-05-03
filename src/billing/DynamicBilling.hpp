#ifndef DYNAMICBILLING_HPP
#define DYNAMICBILLING_HPP

#include "BillingStrategy.hpp"

template <typename T>
class DynamicBilling : public BillingStrategy<T> {
private:
    T free_usage;
    int cost_per_unit;
public:
    DynamicBilling(T freeUsage, int costPerUnit) : free_usage(freeUsage), cost_per_unit(costPerUnit) {}

    int cost(T usage) const override {
        if (usage <= free_usage)
            return 0;
        return (usage - free_usage) * cost_per_unit;
    }
};

#endif // DYNAMICBILLING_HPP
