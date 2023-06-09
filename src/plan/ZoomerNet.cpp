#include "ZoomerNet.h"
#include "../billing/FixedBilling.hpp"
#include "../billing/MultiLevelBilling.hpp"
#include <climits>

#include "../memtrace.h"

ZoomerNet::ZoomerNet() : Plan("ZoomerNet",
                              5990,
                              new FixedBilling<int>(15),
                              new MultiLevelBilling<int, 3>{{5,       45},
                                                            {10,      25},
                                                            {INT_MAX, 5}},
                              new FixedBilling<double>(0)) {}

Plan* ZoomerNet::clone() const {
    return new ZoomerNet(*this);
}
