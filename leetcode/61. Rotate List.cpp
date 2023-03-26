// 61. ��ת����
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
// ѭ����ת������ʵ�������ǽ�β����ǰ����K��Ԫ����Ϊͷ��ԭ����ͷ�ӵ�ԭ����β��
// ����ͨ����ͼ���
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
