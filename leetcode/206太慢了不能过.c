#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *block = NULL;
    struct ListNode *current = NULL;
    struct ListNode *newnode = NULL;
    struct ListNode *inversion = NULL;
    struct ListNode *newcurrent = inversion;
    inversion = (struct ListNode *)malloc(sizeof(struct ListNode *));
    newnode = inversion;
    while (current != head)
    {
        while (current->next != block)
            current = current->next;
        newnode = (struct ListNode *)malloc(sizeof(struct ListNode *));
        newnode->val = current->val;
        newnode->next = NULL;
        newcurrent = newnode;
        newcurrent = newcurrent->next;
        block = current;
        current = head;
    }
    return inversion;
}