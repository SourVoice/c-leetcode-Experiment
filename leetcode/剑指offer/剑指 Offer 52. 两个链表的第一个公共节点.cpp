#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// ¹þÏ£±í
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        set<ListNode *> st1, st2;
        while (headA || headB)
        {
            if (headA && !st1.count(headA))
            {
                st1.emplace(headA);
            }
            if (headB && !st2.count(headB))
            {
                st2.emplace(headB);
            }
            if (headB && st1.count(headB))
                return headB;
            if (headA && st2.count(headA))
                return headA;
            if (headA)
                headA = headA->next;
            if (headB)
                headB = headB->next;
        }
        return nullptr;
    }
};
// Ë«Ö¸Õë
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;
        ListNode *pa = headA, *pb = headB;
        while (pa != pb)
        {
            if (pa)
                pa = pa->next;
            else
                pa = headB;
            if (pb)
                pb = pb->next;
            else
                pb = headA;
        }
        return pa;
    }
};