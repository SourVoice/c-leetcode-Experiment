// 82. ɾ�����������е��ظ�Ԫ�� II
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
// ģ��
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *prev = dummy;
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                while (cur->next && cur->val == cur->next->val)
                {
                    cur = cur->next;
                }
                prev->next = cur->next;
                cur = cur->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// �ݹ�
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        if (head->val == head->next->val)
        {
            ListNode *node = new ListNode;
            node = head;
            while (node && node->val == head->val)
                node = node->next;
            // �õ���ͬ��headֵ�Ľڵ�
            // �ݹ鷵��ʱ����deleteDuplicate(node), ֱ��ȥ�������кʹ˴�head��ͬ�Ľڵ�
            return deleteDuplicates(node);
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
