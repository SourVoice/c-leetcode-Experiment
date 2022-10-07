// 19. ɾ������ĵ����� N �����
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
// ˫ָ��
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        int cnt = 0;
        // �ɿ�ָ����ǰ��n��, ��ָ��������total - nλ��
        while (cnt < n && fast)
        {
            fast = fast->next;
            cnt++;
        }
        // !! fast����β˵��Ҫɾ����������ͷָ��
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
