#ifndef FIR_TRAPFILTER_H
#define FIR_TRAPFILTER_H

#include <QWidget>
#include "trapfilter_cofficient.h"

void Trapfilter_CreateListHear(trapfilter_pDelayLinkList *L, uint16_t n);
double FIR_TrapFilter(double data, trapfilter_pDelayLinkList *L);

#endif // FIR_TRAPFILTER_H
