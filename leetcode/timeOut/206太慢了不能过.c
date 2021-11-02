#include <stdio.h>
struct LINK
{
    int val;
    struct LINK *next;
};

struct LINK *reverseList(struct LINK *head)
{
    struct LINK *block = NULL;
    struct LINK *current = NULL;
    struct LINK *newnode = NULL;
    struct LINK *inversion = NULL;
    struct LINK *newcurrent = inversion;
    inversion = (struct LINK *)malloc(sizeof(struct LINK *));
    newnode = inversion;
    while (current != head)
    {
        while (current->next != block)
            current = current->next;
        newnode = (struct LINK *)malloc(sizeof(struct LINK *));
        newnode->val = current->val;
        newnode->next = NULL;
        newcurrent = newnode;
        newcurrent = newcurrent->next;
        block = current;
        current = head;
    }
    return inversion;
}