#ifndef BASIC_H
#define BASIC_H

#include "Plan.h"

#include "../memtrace.h"

/**
 * A Basic adatcsomagot megvalósító osztály.
 */
class Basic : public Plan {
public:
    /**
     * Beállítja az ősosztály számlázási startégiáit.
     */
    Basic();

    Plan* clone() const override;
};

#endif // BASIC_H
