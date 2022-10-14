#include <stdio.h>
#include <stdlib.h>
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
// 模拟
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *pre = head;
        ListNode *cur = pre->next;
        head->next = nullptr;
        while (cur)
        {
            ListNode *node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = node;
        }
        head = pre;
        return head;
    }
};
// 递归
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node; // node永远指向反转后的头节点
    }
};
/*
1->2->3->4->5
first:
               he   no
1 -> 2 -> 3 -> 4 -> 5   he -> ne -> ne = he, he->ne = nul

second:
          he         no
1 -> 2 -> 3 -> 4 <- 5   he -> ne -> ne = null, so let he -> ne -> ne = he, he->ne = nul

...
*/