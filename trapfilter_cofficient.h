#ifndef TRAPFILTER_COFFICIENT_H
#define TRAPFILTER_COFFICIENT_H

#include <QWidget>

extern bool TrapFilterStatus;

extern uint16_t FIR_Trapfilter_FilterLength;
extern double   FIR_Trapfilter_Coefficient[505];

// 单链表结点定义
typedef struct trapfilter_pDelayNode
{
    double data; // data用于存储链表节点的值，如果该节点为头节点，则存储的是链表中的节点数量
    struct trapfilter_pDelayNode *next;
}trapfilter_pDelayNode, *trapfilter_pDelayLinkList;

extern trapfilter_pDelayLinkList trapfilter_pDelay[8];

#endif // TRAPFILTER_COFFICIENT_H
