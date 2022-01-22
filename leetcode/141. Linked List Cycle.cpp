// 141. Linked List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//哈希表法
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> st;
        struct ListNode *curr = head;
        while (curr && curr->next)
        {
            if (st.count(curr))
                return true;
            st.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};

//快慢指针法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}