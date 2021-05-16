#include <stdio.h>
#include <stdlib.h>
/*
这里展示的是有序双链表(非循环)的插入
1.插入到链表中间
2.插入至链表头部
3.插入至结束
4.插入至开始和结束(原链表空)
*/

typedef struct LINK
{
    int value;
    struct LINK *forward;
    struct LINK *backward;
} Link;

Link *insert(Link *head, int new_value)
{

    Link *new = NULL;
    Link *current = NULL;
    Link *preview = current;
    /*有重复的值就返回*/
    for (preview = head; current = preview->forward != NULL; preview = current)
    {
        if (current->value == new_value)
            return -1;
        else if (current->value > new_value)
            break;
    }
    /*set_new_link*/
    new = (Link *)malloc(sizeof(Link));
    if (new == NULL)
        return -1;
    new->value = new_value;
    /*确定指向的两个指针*/
    new->forward = current;
    preview->forward = new;
    /*位于头部时new->backword的指向情况*/
    if (preview != head)
        new->backward = preview;
    else
        new->backward = NULL;
    /*current->backword和new->forward只用考虑是否位于尾部*/
    /*current已经判断出了是否为空,这里只用考虑头指针的backward指向末尾*/
    if (current != NULL)
        current->backward = new;
    else
        head->backward = new;
}