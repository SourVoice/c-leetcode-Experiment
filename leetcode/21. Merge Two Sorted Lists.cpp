// 21. 合并两个有序链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <malloc.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head = p;
    head->next = l1;

    if (!p)
    {
        return NULL;
    }
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            p = l1;
            l1 = l1->next;
        }
        else
        {
            struct ListNode *tmp = l2->next;
            p->next = l2;
            p = l2;
            l2->next = l1;
            l2 = tmp;
        }
    }
    if (l1)
        p->next = l1;
    else
        p->next = l2;
    return head->next;
}