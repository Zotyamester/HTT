#ifndef MULTILEVELBILLING_HPP
#define MULTILEVELBILLING_HPP

#include <initializer_list>
#include "BillingStrategy.hpp"

/**
 * A többszintű számlázást megvalósító osztály, mely szintenként más tarifa szerint számláz.
 * @tparam T milyen típusú adathasználat utáni számlázást ír le (pl. int, double)
 * @tparam LEVEL_COUNT hány szintű a számlázás
 */
template<typename T, size_t LEVEL_COUNT>
class MultiLevelBilling : public BillingStrategy<T> {
public:
    /**
     * Egy szint számlázási paramétereit leíró osztály.
     */
    struct LevelCost {
        // mekkora adathasználatig érvényes a szint tarifája
        T usage;
        // tarifa
        int cost;

        /**
         * Beállítja a szint számlázási paramétereit
         * @param usage mekkora adathasználatig érvényes a szint tarifája
         * @param cost tarifa
         */
        LevelCost(T usage = 0, int cost = 0) : usage(usage), cost(cost) {}
    };

private:
    // az egyes szinthez tartozó számlázási paraméterek
    LevelCost cost_of_levels[LEVEL_COUNT];
public:
    /**
     * A konstruktor beállítja a számlázás paramétereit, mely a szintenkénti számlázás listája.
     * @param init inicializáló lista a szintek számlázási paramétereivel
     */
    MultiLevelBilling(std::initializer_list<LevelCost> init) {
        size_t count = utils::min(init.size(), LEVEL_COUNT);
        std::copy(init.begin(), init.begin() + count, cost_of_levels);
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
