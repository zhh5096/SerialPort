#ifndef FIR_BANDPASSFILTER_H
#define FIR_BANDPASSFILTER_H

#include <QWidget>
#include "bandpassfilter_cofficient.h"

void Bandpassfilter_CreateListHear(bandpassfilter_pDelayLinkList *L, uint16_t n);
double FIR_BandPassFilter(double data, bandpassfilter_pDelayLinkList *L);

#endif // FIR_BANDPASSFILTER_H
