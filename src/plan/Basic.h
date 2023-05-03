#ifndef BASIC_H
#define BASIC_H

#include "Plan.h"

/**
 * A Basic díjcsomag fix tarifájú SMS-eket és hívásokat nyújt.
 */
class Basic : public Plan {
private:
    friend class PlanFactory;

public:
    /**
     * A díjcsomag egzakt árait meghatározó konstruktor.
     */
    Basic();
};

#endif // BASIC_H
