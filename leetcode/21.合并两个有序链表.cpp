/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <malloc.h>
struct LINK
{
    int val;
    struct LINK *next;
};
struct LINK *mergeTwoLists(struct LINK *l1, struct LINK *l2)
{
    struct LINK *p = (struct LINK *)malloc(sizeof(struct LINK));
    if (!p)
    {
        return NULL;
    }
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1)
        p->next = l1;
    else
        p->next = l2;
    return p;
}