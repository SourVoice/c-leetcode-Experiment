/*回文链表*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define bool int
#define true 1
#define false 0

struct ListNode
{
    int val;
    struct ListNode *next;
};
bool isPalindrome(struct ListNode *head)
{
    if (head->next)
        return true;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    int stack[50001];
    int index = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        stack[index] = slow->val;
    }
    if (fast) //奇数
        slow = slow->next;
    while (slow)
    {
        if (stack[--index] != slow->val)
            return false;
    }
    return true;
}