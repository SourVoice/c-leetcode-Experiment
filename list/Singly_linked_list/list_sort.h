#include <stdlib.h>
#include <stdio.h>

typedef struct LINK
{
    int value;
    struct LINK *next;
} Link;
/*非结点交换的冒泡排序*/
void ListSort(Link *head)
{
    if (head == NULL)
        return;
    int temp_int = 0;
    Link *n = head;
    /*暂存指针*/
    Link *current = NULL;
    Link *end = NULL;

    while (current != end)
    {
        while (current->next != end)
        {
            if (current->value > current->next->value)
            {
                temp_int = current->value;
                current->value = current->next->value;
                current->next->value = current->value;
            }
            current = current->next;
        }
        /*尾指针前移,用于确定排序轮数*/
        end = current;
        current = head;
    }
}