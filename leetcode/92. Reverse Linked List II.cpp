// 92. 反转链表 II
#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <map>
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
#include <sstream>
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *pre = dummy;
        for (int i = 1; i < left; i++)
        {
            pre = pre->next;
        }
        ListNode *prev = pre; // 子链表头节点的前一个节点
        ListNode *sublist_begin = prev->next;

        for (int i = 1; i <= right - left + 1; i++)
        {
            pre = pre->next;
        }

        ListNode *sublist_end = pre; // 子链表的最后一个节点
        pre = sublist_end->next;     // 子链表的最后一个节点的后一个

        prev->next = nullptr;
        sublist_end->next = nullptr;

        reverseList(sublist_begin); // 反转链表

        // 拼接
        // 1 -> 2 -> 3
        // be        en
        // 1 <- 2 <- 3
        // be        en
        prev->next = sublist_end;
        sublist_begin->next = pre; // begin变为尾结点

        return dummy->next;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};
