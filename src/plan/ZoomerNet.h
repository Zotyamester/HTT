#ifndef ZOOMERNET_H
#define ZOOMERNET_H

#include "Plan.h"

#include "../memtrace.h"

/**
 * A ZoomerNet adatcsomagot megvalósító osztály.
 */
class ZoomerNet : public Plan {
public:
    /**
     * Beállítja az ősosztály számlázási startégiáit.
     */
    ZoomerNet();

    Plan* clone() const override;
};

#endif // ZOOMERNET_H
