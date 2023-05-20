#ifndef BANDPASSFILTER_COFFICIENT_H
#define BANDPASSFILTER_COFFICIENT_H

#include <QWidget>

extern bool BandPassFilterStatus;

extern uint16_t FIR_Bandpassfilter_FilterLength;
extern double   FIR_Bandpassfilter_Coefficient[1302];

// 单链表结点定义
typedef struct bandpassfilter_pDelayNode
{
    double data; // data用于存储链表节点的值，如果该节点为头节点，则存储的是链表中的节点数量
    struct bandpassfilter_pDelayNode *next;
}bandpassfilter_pDelayNode, *bandpassfilter_pDelayLinkList;

extern bandpassfilter_pDelayLinkList bandpassfilter_pDelay[8];

#endif // BANDPASSFILTER_COFFICIENT_H
