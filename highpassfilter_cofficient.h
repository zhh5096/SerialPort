#ifndef HIGHPASSFILTER_COFFICIENT_H
#define HIGHPASSFILTER_COFFICIENT_H

#include <QWidget>

extern bool HighPassFilterStatus;

extern uint16_t FIR_Highpassfilter_FilterLength;
extern double   FIR_Highpassfilter_Coefficient[1303];

// 单链表结点定义
typedef struct highpassfilter_pDelayNode
{
    double data; // data用于存储链表节点的值，如果该节点为头节点，则存储的是链表中的节点数量
    struct highpassfilter_pDelayNode *next;
}highpassfilter_pDelayNode, *highpassfilter_pDelayLinkList;

extern highpassfilter_pDelayLinkList highpassfilter_pDelay[8];

#endif // HIGHPASSFILTER_COFFICIENT_H
