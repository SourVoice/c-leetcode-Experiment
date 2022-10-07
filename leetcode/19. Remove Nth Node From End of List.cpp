// 19. 删除链表的倒数第 N 个结点
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 双指针
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        int cnt = 0;
        // 由快指针提前走n步, 慢指针正好走total - n位置
        while (cnt < n && fast)
        {
            fast = fast->next;
            cnt++;
        }
        // !! fast到结尾说明要删除的内容在头指针
        if (!fast)
            return head->next;
        while (fast->next && slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
