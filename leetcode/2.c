/**
 * Definition for singly-linked list.
 * typedef struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * }List;
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int flag = 0;
    struct ListNode *newlist = NULL;
    struct ListNode *temp = NULL;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (temp == NULL)
        return NULL;

    struct ListNode *head = NULL;
    head = temp;

    if (l1 == NULL && l2 == NULL)
        return l1;
    if (l1 == NULL && l2 != NULL)
        return l2;
    if (l1 != NULL && l2 == NULL)
        return l1;

    while (l1->next && l2->next)
    {
        newlist = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (newlist == NULL)
            return NULL;
        if (newlist == NULL)
            return 0;
        if ((l1->val + l2->val) < 10)
        {
            if (l1->val + l2->val + flag == 10)
            {
                newlist->val = l1->val + l2->val + flag - 10;
                flag = 1;
            }
            else
            {
                newlist->val = l1->val + l2->val + flag;
                flag = 0;
            }
        }
        else
        {
            newlist->val = l1->val + l2->val - 10 + flag;
            flag = 1;
        }
        newlist->next = NULL;
        temp->next = newlist;
        temp = newlist;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 && l2)
    {
        newlist = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (newlist == NULL)
            return NULL;
        if (l1->val + l2->val + flag >= 10)
        {
            newlist->val = l1->val + l2->val - 10 + flag;
            flag = 1;
        }
        else
        {
            newlist->val = l1->val + l2->val + flag;
            flag = 0;
        }
        newlist->next = NULL;
        temp->next = newlist;
        temp = newlist;
        l1 = l1->next;
        l2 = l2->next;
    }
    newlist = l1 ? l1 : l2;

    if (newlist != NULL)
    {
        while (newlist != NULL)
        {
            if ((flag != 0) && (newlist->val == 9))
            {
                newlist->val = 0;
                flag = 1;
            }
            else
            {
                newlist->val = newlist->val + flag;
                flag = 0;
            }
            temp->next = newlist;
            temp = newlist;
            newlist = newlist->next;
        }
    }

    if (newlist == NULL && flag == 1)
    {
        newlist = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *tail = (struct ListNode *)malloc(sizeof(struct ListNode));
        tail->val = flag;
        tail->next = NULL;
        newlist = tail;
        temp->next = newlist;
    }
    return head->next;
}