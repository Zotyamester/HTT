#ifndef DATAPLANFACTORY_H
#define DATAPLANFACTORY_H

#include "Plan.h"
#include "../utils/Vector.hpp"

class PlanFactory {
public:
    static Plan* createPlan(const utils::String& plan_name);
};


#endif // DATAPLANFACTORY_H
