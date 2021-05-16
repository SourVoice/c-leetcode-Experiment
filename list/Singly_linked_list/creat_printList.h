#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *creat_list(int total_elements)
{
    struct ListNode *head;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = head;
    struct ListNode *newnode = NULL;
    for (int i = 0; i < total_elements; i++)
    {
        newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (newnode == NULL)
            return NULL;
        scanf("%d", &newnode->val);
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
    }
    return head->next;
}
void print_List(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->val);
        head = head->next;
    }
    printf("\n");
}
void print_nodeAddress(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("node_address = 0x%x\t", head);
        head = head->next;
    }
    printf("\n");
}