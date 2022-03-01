/**
 * Definition for singly-linked list.
 * typedef struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * }List;
 */

struct LINK *addTwoNumbers(struct LINK *l1, struct LINK *l2)
{
    int flag = 0;
    struct LINK *newlist = NULL;
    struct LINK *temp = NULL;
    temp = (struct LINK *)malloc(sizeof(struct LINK));
    if (temp == NULL)
        return NULL;

    struct LINK *head = NULL;
    head = temp;

    if (l1 == NULL && l2 == NULL)
        return l1;
    if (l1 == NULL && l2 != NULL)
        return l2;
    if (l1 != NULL && l2 == NULL)
        return l1;

    while (l1->next && l2->next)
    {
        newlist = (struct LINK *)malloc(sizeof(struct LINK));
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
        newlist = (struct LINK *)malloc(sizeof(struct LINK));
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
        newlist = (struct LINK *)malloc(sizeof(struct LINK));
        struct LINK *tail = (struct LINK *)malloc(sizeof(struct LINK));
        tail->val = flag;
        tail->next = NULL;
        newlist = tail;
        temp->next = newlist;
    }
    return head->next;
}