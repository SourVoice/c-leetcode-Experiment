// 143. ��������
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
// �ݹ�
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        // ����ָ���ҵ��е�
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // ��ת��������
        ListNode *suffix = reverseList(slow);
        // �ϲ���������
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
    // �ݹ�ԭ��: ����nodeλ�ò���, ��ÿ�εݹ��е�head�γɻ���ϵ, ֮��ȥ����
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
�ݹ鷵�����ڶ���:
       h  node
       ��  ��
    3->4->5->     ; head->next->next = head
       ��----��

    h            node
    ��            ��
    3->4->null   5->     ; head->next = nullptr
       ��-----------��
*/