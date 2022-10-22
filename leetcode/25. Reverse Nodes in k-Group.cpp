// 25. K 个一组翻转链表
#include <string>
#include <stack>
#include <bitset>
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head)
            return nullptr;
        int cnt = 0;
        ListNode *pre = head;
        while (cnt < k)
        {
            cnt++;
            if (head == nullptr) // 不足k不用反转
                return pre;
            head = head->next;
        }
        ListNode *node = reverseList(pre, head);
        pre->next = reverseKGroup(head, k);
        return node;
    }
    ListNode *reverseList(ListNode *head, ListNode *end)
    {
        if (head->next == end)
            return head;
        ListNode *node = reverseList(head->next, end);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};