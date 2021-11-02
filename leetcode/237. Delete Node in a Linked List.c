/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
void deleteNode(struct ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}
struct ListNode *initListNode()
{
    int nodeVal[4] = {1, 4, 5, 2};
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!head)
        return NULL;

    struct ListNode *current = head;
    for (int i = 0; i < 4; i++)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!newNode)
            return NULL;
        newNode->val = nodeVal[i];
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;
    }
    return head;
}
int displayListNode(struct ListNode *head)
{
    if (!head)
        return 0;
    while (head->next)
    {
        printf("%d ", head->next->val);
        head = head->next;
    }
    printf("\n");
    return 1;
}
int main()
{
    struct ListNode *head = initListNode();
    if (!displayListNode(head))
        return 0;
    deleteNode(head->next->next);
    if (!displayListNode(head))
        return 0;
}