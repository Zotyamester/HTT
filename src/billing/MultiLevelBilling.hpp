#ifndef MULTILEVELBILLING_HPP
#define MULTILEVELBILLING_HPP

#include <cstddef>
#include <initializer_list>
#include "BillingStrategy.hpp"

template<typename T, size_t LEVEL_COUNT>
class MultiLevelBilling : public BillingStrategy<T> {
public:
    struct LevelCost {
        T usage;
        int cost;

        LevelCost(T usage = 0, int cost = 0) : usage(usage), cost(cost) {}
    };

private:
    LevelCost cost_of_levels[LEVEL_COUNT];
public:
    MultiLevelBilling(std::initializer_list<LevelCost> init) {
        std::copy(init.begin(), init.end(), cost_of_levels);
    }

    int cost(T usage) const override {
        int total = 0;
        for (size_t level = 0; level < LEVEL_COUNT && usage != 0; level++) {
            int usage_on_this_level = utils::min(usage, cost_of_levels[level].usage);
            total += usage_on_this_level * cost_of_levels[level].cost;
            usage -= usage_on_this_level;
        }
        return total;
    }
};

#endif // MULTILEVELBILLING_HPP
