// 83. 删除排序链表中的重复元素
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *cur = head;
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};
// 取地址
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode **p = &head;
        ListNode *a, *b;

        while ((a = *p) && (b = a->next))
        {
            if (b->val == a->val)
                a->next = b->next;
            else
                p = &(a->next);
        }
        return head;
    }
};
