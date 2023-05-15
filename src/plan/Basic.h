#ifndef BASIC_H
#define BASIC_H

#include "Plan.h"

/**
 * A Basic díjcsomag fix tarifájú SMS-eket és hívásokat nyújt.
 */
class Basic : public Plan {
public:
    /**
     * Beállítja az ősosztály számlázási startégiáit.
     */
    Basic();
};

#endif // BASIC_H
