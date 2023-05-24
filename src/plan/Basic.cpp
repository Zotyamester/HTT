#include "Basic.h"
#include "../billing/FixedBilling.hpp"
#include "../billing/DynamicBilling.hpp"

#include "../memtrace.h"

Basic::Basic() : Plan("Basic",
                      1990,
                      new FixedBilling<int>(30),
                      new FixedBilling<int>(45),
                      new DynamicBilling<double>(500.0, 5)) {}

Plan* Basic::clone() const {
    return new Basic(*this);
}
