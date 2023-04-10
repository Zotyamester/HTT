#ifndef SMSMAX_H
#define SMSMAX_H

#include "DataPlan.h"

/**
 * Az SmsMax díjcsomag korlátlan számú, díjmentes SMS küldését teszi lehetővé.
 */
class SmsMax : public DataPlan {
private:
    SmsMax();

    friend class DataPlanFactory;
};

#endif // SMSMAX_H
