// 24. 两两交换链表中的节点
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
// 递归
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *node = head->next;
        head->next = swapPairs(node->next);
        node->next = head;
        return node;
    }
};
// 循环做法
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode **shaobing = &head;
        ListNode *a, *b;
        while ((a = *shaobing) && (b = a->next))
        {
            a->next = b->next;
            b->next = a;
            *(shaobing) = b;
            shaobing = &(a->next);
        }
        return head;
    }
};
// 二刷,取头节点地址, 之后更新地址
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode **pp = &head;
        ListNode *a = head, *b = head;
        while ((a = *pp) && (b = a->next))
        {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};