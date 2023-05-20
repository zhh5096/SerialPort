#include "fir_highpassfilter.h"

/* 使用头插法初始化一个带有头节点的单链线性表，线性表长度为n */
void Highpassfilter_CreateListHear(highpassfilter_pDelayLinkList *L, uint16_t n)
{
    highpassfilter_pDelayLinkList p;
    *L = (highpassfilter_pDelayLinkList)malloc(sizeof(highpassfilter_pDelayNode));
    (*L)->next = nullptr;
    for(uint16_t i=0; i<n; i++){
        p = (highpassfilter_pDelayLinkList)malloc(sizeof(highpassfilter_pDelayNode));
        p->data = 0;
        p->next = (*L)->next;
        (*L)->next = p;
        (*L)->data++;
    }
}

/* 滤波处理 */
double FIR_HighPassFilter_01(double data, highpassfilter_pDelayLinkList *L)
{
    highpassfilter_pDelayLinkList p,q;
    double output=0;
    p = *L;
    // 在线性表L的头结点之后插入一个新的节点q
    q = (highpassfilter_pDelayLinkList)malloc(sizeof(highpassfilter_pDelayNode));
    q->data = data;
    q->next = p->next;
    p->next = q;
    (*L)->data++;
    // 滤波处理
    for(uint16_t i=0; i<FIR_Highpassfilter_FilterLength; i++){
        output = output + FIR_Highpassfilter_Coefficient[i]*(p->next->data);
        p = p->next;
    }
    // 删除线性表L的尾部结点
    q = p->next;
    p->next = q->next;
    free(q);
    (*L)->data--;
    return output;
}
