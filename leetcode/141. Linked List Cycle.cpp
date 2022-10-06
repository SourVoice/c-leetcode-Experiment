// 141. 环形链表
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
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
//哈希表法
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> st;
        ListNode *cur = head;
        while (cur && cur->next)
        {
            if (st.count(cur))
                return true;
            st.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};

//快慢指针法
bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && fast->next) // fast 先进行判断, 防止fast->next为UB
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
