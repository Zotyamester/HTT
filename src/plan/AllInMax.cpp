#include "AllInMax.h"
#include "../billing/FixedBilling.hpp"

AllInMax::AllInMax() : Plan("AllInMax",
                            9990,
                            new FixedBilling<int>(0),
                            new FixedBilling<int>(0),
                            new FixedBilling<double>(0)) {}
