#include <stdio.h>
#include "list_sort.h"

Link *delet(Link **rootp, int target_value)
{
    Link *current = NULL;
    Link *head = NULL;
    head = *rootp;
    current = *rootp;
    rootp = &current->next;
    if (*rootp == NULL)
        return;

    while (current != NULL)
    {

        if (current->value == target_value)
        {
            /*删除头节点*/
            if (current == head)
            {
                head = head->next;
                free(current);
                current = head;
                continue;
            }

            else
            {
                *rootp = current->next;
                free(current);
                current = *rootp;
            }
        }
        rootp = &current->next;
        current = *rootp;
    }
    return head;
}