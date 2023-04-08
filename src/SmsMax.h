#ifndef SMSMAX_H
#define SMSMAX_H

#include "DataPlan.h"

/**
 * Az SmsMax díjcsomag korlátlan számú, díjmentes SMS küldését teszi lehetővé.
 */
class SmsMax : public DataPlan {
public:
    SmsMax();
};

#endif // SMSMAX_H
