#ifndef DATAPLANFACTORY_H
#define DATAPLANFACTORY_H

#include "Plan.h"

/**
 * Az adatcsomagok létrehozásáért felelős osztály.
 */
class PlanFactory {
private:
    /**
     * Priváttá tett konstruktor, hogy ne jöhessen létre példány az osztályból.
     */
    PlanFactory() = default;
public:
    /**
     * Létrehozza dinamikusan a megfelelő adatcsomagot @p plan_name alapján.
     *
     * Ha hibás, nem létező csomagra hivatkozik a név, kivételt dob!
     * @param plan_name adatcsomag neve
     * @return a dinamikusan létrehozott adatcsomag, melynek felszabadítása a hívó felelőssége
     * @throw std::invalid_argument
     */
    static Plan* createPlan(const utils::String& plan_name);
};

#endif // DATAPLANFACTORY_H
