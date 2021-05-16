#include <stdio.h>
#include "list_sort.h"

Link *find_mid(Link *head)
{
    Link *slow = head;
    Link *fast = head;
    while (slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    /*1:2速度走遍链表,fast到达终点时,slow到达中点或偏后一个*/
}