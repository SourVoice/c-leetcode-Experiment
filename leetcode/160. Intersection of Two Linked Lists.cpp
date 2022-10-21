// 160. �ཻ����
#include <set>
#include <iostream>
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
//��ϣ��:
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        set<ListNode *> st;
        ListNode *curA = headA;
        while (curA)
        {
            st.insert(curA);
            curA = curA->next;
        }
        ListNode *curB = headB;

        while (curB)
        {
            if (st.count(curB))
                return curB;
            curB = curB->next;
        }
        return NULL;
    }
};
//˫ָ�뷨
class Solution2
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB)
        {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
// ��ˢ;˫ָ��
class Solution2
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) // ��ͷ�����±���
        {
            pa = pa ? pa->next : headA;
            pb = pb ? pb->next : headB;
        }
        return pa;
    }
};
/*
1->2->3->4->
            5->6->
2->3->5--->
*/