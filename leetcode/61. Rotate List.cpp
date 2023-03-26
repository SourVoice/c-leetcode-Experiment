// 61. 旋转链表
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
// 循环旋转，但其实本质上是将尾部向前数第K个元素作为头，原来的头接到原来的尾上
// 可以通过画图解决
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *tail = head;
        int len = 0;
        if (!tail)
            return nullptr;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        int n = len + 1;
        ListNode *p = tail;
        tail->next = head;
        for (int i = 0; i < n - (k % n); i++)
        {
            p = p->next;
        }
        ListNode *q = p->next;
        p->next = nullptr;
        return q;
    }
};
