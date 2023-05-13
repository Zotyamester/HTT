#include "PlanFactory.h"

#include "AllInMax.h"
#include "ZoomerNet.h"
#include "Basic.h"

Plan* PlanFactory::createPlan(const utils::String& plan_name) {
    if (plan_name == "Basic") {
        return new Basic;
    } else if (plan_name == "ZoomerNet") {
        return new ZoomerNet;
    } else if (plan_name == "AllInMax") {
        return new AllInMax;
    } else {
        throw std::invalid_argument("Invalid base plan");
    }
}

