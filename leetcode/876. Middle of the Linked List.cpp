// 876. 链表的中间结点
#include <string>
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
// 链表;双指针
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *p = head, *q = head;
        while (q && q->next)
        {
            q = q->next->next;
            p = p->next;
        }
        return p;
    }
};