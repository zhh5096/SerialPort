#ifndef FIR_LOWPASSFILTER_H
#define FIR_LOWPASSFILTER_H

#include <QWidget>
#include "lowpassfilter_cofficient.h"

void Lowpassfilter_CreateListHear(lowpassfilter_pDelayLinkList *L, uint16_t n);
double FIR_LowPassFilter(double data, lowpassfilter_pDelayLinkList *L);

#endif // FIR_LOWPASSFILTER_H
