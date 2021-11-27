#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define LIST_INIT_SIZE 10 /*��ʼ�ռ������*/
#define LIST_INCREMENT 2  /*��������*/
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
void DestoryList(SqList *L) /*�������Ա�L*/
{
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
}
void ClearList(SqList *L) /*�����Ա�L��Ϊ�ձ�*/
{
    if (L->elem)
        memset(L->elem, 0, sizeof(ElemType) * L->listsize); /*��L����������*/
    L->length = 0;
}
int isEmpty(SqList L) /*�ж����Ա�LΪ��*/
{
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}
int ListLength(SqList L) /*���ر���Ԫ�ظ���*/
{
    return L.length;
}
int GetElem(SqList L, int i, ElemType *e) /*���أ����ʣ����Ա��i��Ԫ��*/
{
    if (i < 1 || i > L.length) /*�Ϸ���*/
        return FALSE;
    *e = *(L.elem + i - 1);
    return TRUE;
}
int ListInsert(SqList *L, int i, ElemType e) /*����e��L��i��*/
{
    if (i < 0 || i > L->length) /*�Ϸ���*/
        return FALSE;
    if (L->length >= L->listsize) /*�ռ䳤�Ȳ����貹��*/
    {
        ElemType *buf = (ElemType *)realloc(L->elem, (L->listsize + LIST_INCREMENT));
        if (!buf)
            return FALSE;
        L->elem = buf; /*ͷָ������*/
        L->listsize += LIST_INCREMENT;
    }
    ElemType *pos = &(L->elem[i]); /*posָ��L���е�i��*/
    for (ElemType *p = &(L->elem[L->length - 1]); p >= pos; p--)
    {
        *(p + 1) = *p; /*��L.elem[L.length - 1]��pos��i��������Ԫ������ƶ�*/
    }
    *pos = e;
    L->length++;
    return TRUE;
}
int PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) /*����Ԫ��cur_e��ǰ����pre_e*/
{
    int i = 2;
    ElemType *p = L.elem + 1;
    while (i <= L.length && *p != cur_e) /*�ҵ�cur_eλ��*/
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
int NextElem(SqList L, ElemType cur_e, ElemType *next_e) /*����cur_e�ĺ��Ԫ�ص�next_e*/
{
    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.length && *p != cur_e) /*�ҵ�cur_eλ��*/
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
int ListDelet(SqList *L, int i, ElemType *e) /*ɾ��L�ĵ�i��Ԫ�أ���������e��*/
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
            L1->elem[i] = L1->elem[--end]; //end�仯
            L1->elem[end] = temp;
        }
        else
            i++;
    }
    //endΪ�ָ������
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