// 23. 合并K个升序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        for (int i = 0; i < lists.size() - 1; i++)
            lists[i + 1] = helper(lists[i], lists[i + 1]);
        return lists.back();
    }
    ListNode *helper(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val <= l2->val)
        {
            l1->next = helper(l1->next, l2);
            return l1;
        }
        l2->next = helper(l1, l2->next);
        return l2;
    }
};
