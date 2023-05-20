#include "fir_bandpassfilter.h"

/* 使用头插法初始化一个带有头节点的单链线性表，线性表长度为n */
void Bandpassfilter_CreateListHear(bandpassfilter_pDelayLinkList *L, uint16_t n)
{
    bandpassfilter_pDelayLinkList p;
    *L = (bandpassfilter_pDelayLinkList)malloc(sizeof(bandpassfilter_pDelayNode));
    (*L)->next = nullptr;
    for(uint16_t i=0; i<n; i++){
        p = (bandpassfilter_pDelayLinkList)malloc(sizeof(bandpassfilter_pDelayNode));
        p->data = 0;
        p->next = (*L)->next;
        (*L)->next = p;
        (*L)->data++;
    }
}

/* 滤波处理 */
double FIR_BandPassFilter(double data, bandpassfilter_pDelayLinkList *L)
{
    bandpassfilter_pDelayLinkList p,q;
    double output=0;
    p = *L;
    // 在线性表L的头结点之后插入一个新的节点q
    q = (bandpassfilter_pDelayLinkList)malloc(sizeof(bandpassfilter_pDelayNode));
    q->data = data;
    q->next = p->next;
    p->next = q;
    (*L)->data++;
    // 滤波处理
    for(uint16_t i=0; i<FIR_Bandpassfilter_FilterLength; i++){
        output = output + FIR_Bandpassfilter_Coefficient[i]*(p->next->data);
        p = p->next;
    }
    // 删除线性表L的尾部结点
    q = p->next;
    p->next = q->next;
    free(q);
    (*L)->data--;
    return output;
}
