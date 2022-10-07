#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 递归
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        ListNode *ret = new ListNode;
        if (!l1 && !l2)
        {
            if (carry)
            {
                ret->val = 1;
                carry = 0;
                ret->next = addTwoNumbers(l1 != nullptr ? l1->next : l1, l2 != nullptr ? l2->next : l2);
                return ret;
            }
            return nullptr;
        }
        if (l1)
            sum += l1->val;
        if (l2)
            sum += l2->val;
        sum += carry;
        if (sum > 9)
        {
            ret->val = sum % 10;
            carry = 1;
            ret->next = addTwoNumbers(l1 != nullptr ? l1->next : l1, l2 != nullptr ? l2->next : l2); // 只有当节点不为空我们才进行传递
            return ret;
        }
        ret->val = sum;
        carry = 0;
        ret->next = addTwoNumbers(l1 != nullptr ? l1->next : l1, l2 != nullptr ? l2->next : l2);
        return ret;
    }

private:
    int carry = 0;
};
// TODO: 模拟

// 曾经C语言解法
typedef struct LINK
{
    int val;
    struct LINK *next;
};

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