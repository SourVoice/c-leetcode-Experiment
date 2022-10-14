// 21. �ϲ�������������
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <malloc.h>
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
// ����ģ��
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *result = new ListNode();
        ListNode *head = result;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                result->next = list1;
                list1 = list1->next;
            }
            else
            {
                result->next = list2;
                list2 = list2->next;
            }
            result = result->next;
        }
        result->next = list1 ? list1 : list2;
        return head->next;
    }
};
// �ݹ�
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};
// ����Ϊ ԭC�������
// ����ģ��
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head = p;
    head->next = l1;

    if (!p)
        return NULL;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            p = l1;
            l1 = l1->next;
        }
        else
        {
            struct ListNode *tmp = l2->next;
            p->next = l2;
            p = l2;
            l2->next = l1;
            l2 = tmp;
        }
    }
    if (l1)
        p->next = l1;
    else
        p->next = l2;
    return head->next;
}
