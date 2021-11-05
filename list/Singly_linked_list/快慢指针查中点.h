#include <stdio.h>
#include "list_sort.h"

Link *find_mid(Link *head)
{
    Link *slow = head;
    Link *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; /*当fast不为空时,结点个数为奇数个,否则为偶数个,且slow偏后*/
    /*1:2速度走遍链表,fast到达终点时,slow到达中点或偏后一个*/
}