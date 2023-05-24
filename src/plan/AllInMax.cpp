#include "AllInMax.h"
#include "../billing/FixedBilling.hpp"

#include "../memtrace.h"

AllInMax::AllInMax() : Plan("AllInMax",
                            9990,
                            new FixedBilling<int>(0),
                            new FixedBilling<int>(0),
                            new FixedBilling<double>(0)) {}

Plan* AllInMax::clone() const {
    return new AllInMax(*this);
}
