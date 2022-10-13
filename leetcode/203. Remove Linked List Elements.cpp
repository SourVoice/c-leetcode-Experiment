// 203. ÒÆ³ıÁ´±íÔªËØ
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode **p = &head;
        ListNode *a, *b;
        while ((a = *p) && (b = a->next))
        {
            if (b->val == val)
                a->next = b->next;
            else
                p = &(a->next);
        }
        return head && head->val == val ? head->next : head;
    }
};