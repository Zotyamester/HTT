#ifndef FIXEDBILLING_HPP
#define FIXEDBILLING_HPP

#include "BillingStrategy.hpp"

template <typename T>
class FixedBilling : public BillingStrategy<T> {
private:
    int cost_per_unit;
public:
    explicit FixedBilling(int costPerUnit) : cost_per_unit(costPerUnit) {}

    int cost(T usage) const override {
        return usage * cost_per_unit;
    }
};


#endif // FIXEDBILLING_HPP
