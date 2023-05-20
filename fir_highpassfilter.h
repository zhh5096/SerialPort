#ifndef FIR_HIGHPASSFILTER_H
#define FIR_HIGHPASSFILTER_H

#include <QWidget>
#include "highpassfilter_cofficient.h"

void Highpassfilter_CreateListHear(highpassfilter_pDelayLinkList *L, uint16_t n);
double FIR_HighPassFilter_01(double data, highpassfilter_pDelayLinkList *L);

#endif // FIR_HIGHPASSFILTER_H
