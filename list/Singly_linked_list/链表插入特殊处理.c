#include <stdlib.h>
typedef struct LINK
{
    int value;
    struct LINK *next;
} Link;

/*插入函数,检验插入是否在头节点,**root代表指向链表地址的指针*/
Link *insert_f(Link **rootp, int new_value)
{
    Link *current;
    Link *new;
    Link *previous = NULL;
    current = *rootp;
    while (current->value < new_value)
    {
        previous = current;
        current = current->next;
    }
    /*创立新节点*/
    new = (Link *)malloc(sizeof(Link));
    if (new == NULL) //check divation
        return 0;
    new->value = new_value;
    new->next = current;
    previous->next = new;
    if (previous == NULL)
        *rootp = new;
    else
        previous->next = new;
}