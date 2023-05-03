#ifndef ZOOMERNET_H
#define ZOOMERNET_H

#include "Plan.h"

class ZoomerNet : public Plan {
private:
    friend class PlanFactory;
public:
    ZoomerNet();
};

#endif // ZOOMERNET_H
