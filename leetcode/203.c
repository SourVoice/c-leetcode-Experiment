#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
//没有使用指针的指针
struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *current = head;
    struct ListNode *preview = head;
    if (head == NULL)
        return head;
    while (current != NULL)
    {
        if (current->val == val)
        {
            if (current == head)
            {
                head = head->next;
                current = head;
                preview = head;
                continue;
            }
            else
            {
                preview->next = current->next;
                current = current->next;
                continue;
            }
        }
        preview = current;
        current = current->next;
    }
    if (preview != NULL)
    {
        if (preview == head && preview->val == val)
            head = NULL;
    }

    return head;
}
struct ListNode *creat()
{
    struct ListNode *head = NULL;
    head = (struct ListNode *)malloc(sizeof(struct ListNode *));
    if (head == NULL)
        return NULL;
    struct ListNode *current = head;
    struct ListNode *newnode = NULL;
    for (int i = 0; i < 1; i++)
    {
        newnode = (struct ListNode *)malloc(sizeof(struct ListNode *));
        if (newnode == NULL)
            return NULL;
        scanf("%d", &newnode->val);
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
    }
    return head->next;
}
void printList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}
int main()
{
    struct ListNode *head = NULL;
    head = creat();
    printList(head);
    head = removeElements(head, 1);
    printList(head);
    return 0;
}