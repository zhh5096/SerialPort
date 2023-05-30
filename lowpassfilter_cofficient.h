#ifndef LOWPASSFILTER_COFFICIENT_H
#define LOWPASSFILTER_COFFICIENT_H

#include <QWidget>

extern bool LowPassFilterStatus;

extern uint16_t FIR_Lowpassfilter_FilterLength;
extern double   FIR_Lowpassfilter_Coefficient[782];

// 单链表结点定义
typedef struct lowpassfilter_pDelayNode
{
    double data; // data用于存储链表节点的值，如果该节点为头节点，则存储的是链表中的节点数量
    struct lowpassfilter_pDelayNode *next;
}lowpassfilter_pDelayNode, *lowpassfilter_pDelayLinkList;

extern lowpassfilter_pDelayLinkList lowpassfilter_pDelay[8];

#endif // LOWPASSFILTER_COFFICIENT_H
