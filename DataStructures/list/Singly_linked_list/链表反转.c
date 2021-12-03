#include <stdlib.h>
#include <stdio.h>

typedef struct LINK
{
    struct LINK *next;
    int value;
} Link;
int num[8] = {1, 2, 3, 4, 5, 6, 7, 8};
/*创建链表*/
Link *creat(Link *head)
{
    Link *current = head;
    if (head == NULL)
        return NULL;
    Link *new = NULL;
    for (int i = 0; i < 8; i++)
    {
        new = (Link *)malloc(sizeof(Link));
        if (new == NULL)
            break;
        current->next = new;
        new->value = num[i];
        new->next = NULL;
        current = new;
    }
    return head;
}
/*反转函数*/
Link *sll_reverse(Link *head)
{
    Link *inversion = NULL;
    Link *new_current = NULL;
    Link *new = NULL;

    inversion = (Link *)malloc(sizeof(Link));
    if (inversion == NULL)
        return NULL;
    new_current = inversion;

    Link *tail = NULL; //阻塞节点,使每次遍历阻塞前移
    Link *current = NULL;
    while (current != head)
    {
        current = head;
        while (current->next != tail)
            current = current->next;
        tail = current;

        new = (Link *)malloc(sizeof(Link));
        if (new == NULL)
            return NULL;
        if (current == head) //提前结束
        {
            new = NULL;
            break;
        }
        new = current;
        new->next = NULL;
        new_current->next = new;
        new_current = new_current->next;
    }
    return inversion;
}
/*显示链表*/
void printList(Link *head)
{

    head = creat(head);
    head = sll_reverse(head);
    head = head->next;
    while (head != NULL)
    {
        printf("%d\n", head->value);
        head = head->next;
    }
}
int main()
{
    Link *head = NULL;
    head = (Link *)malloc(sizeof(Link));
    if (head == NULL)
        return -1;
    printList(head);
    return 1;
}
