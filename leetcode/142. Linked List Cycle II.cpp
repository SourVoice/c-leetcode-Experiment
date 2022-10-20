// 142. 环形链表 II
#include <string>
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
    ListNode(int x) : val(x), next(NULL) {}
};
// 使用哈希表;集合作弊
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        set<ListNode *> st;
        while (head)
        {
            if (!st.count(head))
                st.emplace(head);
            else
                return head;
            head = head->next;
        }
        return nullptr;
    }
};
// 快慢指针
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        bool first = true;
        while (first ? first : slow != fast)
        {
            first = false;
            slow = slow->next;
            if (slow == nullptr || fast == nullptr || fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
        }
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};