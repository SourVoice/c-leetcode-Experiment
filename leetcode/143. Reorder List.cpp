// 143. 重排链表
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
    void reorderList(ListNode *head)
    {
        // 快慢指针找到中点
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转后半段链表
        ListNode *suffix = reverseList(slow);
        // 合并两段链表
        ListNode *recSuffix = suffix;
        ListNode *recHead = head;
        while (suffix && head)
        {
            recHead = head->next;
            recSuffix = suffix->next;
            head->next = suffix;
            suffix->next = recHead;
            head = recHead;
            suffix = recSuffix;
        }
    }
    // 递归原理: 保持node位置不变, 将每次递归中的head形成环关系, 之后去掉环
    ListNode *reverseList(ListNode *head)
    {
        if (!head->next)
            return head;
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};
/*
3->4->5->null
递归返回至第二次:
       h  node
       ↓  ↓
    3->4->5->     ; head->next->next = head
       ↑----↓

    h            node
    ↓            ↓
    3->4->null   5->     ; head->next = nullptr
       ↑-----------↓
*/