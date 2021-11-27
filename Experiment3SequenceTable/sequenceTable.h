#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define LIST_INIT_SIZE 10 /*初始空间分配量*/
#define LIST_INCREMENT 2  /*分配增量*/
#define ElemType int
#define TRUE 1
#define FALSE 0
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;
typedef struct
{
    SqList L[256];
} SqListPool;

void InitList(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem)
        exit(FALSE);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
}
void DestoryList(SqList *L) /*销毁线性表L*/
{
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
}
void ClearList(SqList *L) /*将线性表L置为空表*/
{
    if (L->elem)
        memset(L->elem, 0, sizeof(ElemType) * L->listsize); /*表L中数据清零*/
    L->length = 0;
}
int isEmpty(SqList L) /*判断线性表L为空*/
{
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}
int ListLength(SqList L) /*返回表中元素个数*/
{
    return L.length;
}
int GetElem(SqList L, int i, ElemType *e) /*返回（访问）线性表第i个元素*/
{
    if (i < 1 || i > L.length) /*合法性*/
        return FALSE;
    *e = *(L.elem + i - 1);
    return TRUE;
}
int ListInsert(SqList *L, int i, ElemType e) /*插入e至L的i处*/
{
    if (i < 0 || i > L->length) /*合法性*/
        return FALSE;
    if (L->length >= L->listsize) /*空间长度不够需补足*/
    {
        ElemType *buf = (ElemType *)realloc(L->elem, (L->listsize + LIST_INCREMENT));
        if (!buf)
            return FALSE;
        L->elem = buf; /*头指针重置*/
        L->listsize += LIST_INCREMENT;
    }
    ElemType *pos = &(L->elem[i]); /*pos指向L表中的i处*/
    for (ElemType *p = &(L->elem[L->length - 1]); p >= pos; p--)
    {
        *(p + 1) = *p; /*从L.elem[L.length - 1]至pos（i处）所有元素向后移动*/
    }
    *pos = e;
    L->length++;
    return TRUE;
}
int PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) /*返回元素cur_e的前驱到pre_e*/
{
    int i = 2;
    ElemType *p = L.elem + 1;
    while (i <= L.length && *p != cur_e) /*找到cur_e位置*/
    {
        p++;
        i++;
    }
    if (i > L.length)
        return FALSE;
    else
    {
        *pre_e = *--p;
        return TRUE;
    }
}
int NextElem(SqList L, ElemType cur_e, ElemType *next_e) /*返回cur_e的后继元素到next_e*/
{
    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.length && *p != cur_e) /*找到cur_e位置*/
    {
        p++;
        i++;
    }
    if (i == L.length)
        return FALSE;
    else
    {
        *next_e = *++p;
        return TRUE;
    }
}
int ListDelet(SqList *L, int i, ElemType *e) /*删除L的第i个元素，并返回至e中*/
{
    ElemType *p, *q;
    if (i < 1 || i > L->length)
        return FALSE;
    p = L->elem + i - 1;
    *e = *p;
    q = L->elem + L->length - 1;
    for (++p; p <= q; ++p)
    {
        *(p - 1) = *p;
    }
    L->length--;
    return TRUE;
}
SqList ListMerge(SqList *L1, SqList *L2, SqList *L3)
{

    int equel;
    int end = L1->length;
    for (int i = 0; i < end;)
    {
        equel = FALSE;
        for (int j = i; j < L2->length; j++)
        {
            if (L1->elem[i] == L2->elem[j])
            {
                int temp = L2->elem[j];
                L2->elem[j] = L1->elem[i];
                L1->elem[i] = temp;
                equel = TRUE;
                break;
            }
        }
        if (equel != TRUE)
        {
            int temp = L1->elem[i];
            L1->elem[i] = L1->elem[--end]; //end变化
            L1->elem[end] = temp;
        }
        else
            i++;
    }
    //end为分割并集的线
    for (int i = 0; i < end; i++)
    {
        ListInsert(L3, i, L1->elem[i]);
    }
    for (int i = end; i < L1->length; i++)
    {
        ListInsert(L3, i, L1->elem[i]);
    }
    for (int i = end; i < L2->length; i++)
    {
        ListInsert(L3, i, L2->elem[i]);
    }
}
void ListDisplay(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->elem[i]);
    }
}