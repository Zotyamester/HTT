#ifndef BASIC_H
#define BASIC_H

#include "DataPlan.h"

/**
 * A Basic díjcsomag fix tarifájú SMS-eket és hívásokat nyújt.
 */
class Basic : public DataPlan {
private:
    Basic();

    friend class DataPlanFactory;
};

#endif // BASIC_H
