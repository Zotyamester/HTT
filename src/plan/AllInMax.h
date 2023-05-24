#ifndef ALLINMAX_H
#define ALLINMAX_H

#include "Plan.h"

#include "../memtrace.h"

/**
 * Az AllInMax adatcsomagot megvalósító osztály.
 */
class AllInMax : public Plan {
public:
    /**
     * Beállítja az ősosztály számlázási startégiáit.
     */
    AllInMax();

    Plan* clone() const override;
};

#endif // ALLINMAX_H
