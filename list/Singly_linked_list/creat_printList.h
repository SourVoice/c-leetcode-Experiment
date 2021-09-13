#include <stdio.h>
#include <stdlib.h>
struct LINK
{
    int val;
    struct LINK *next;
};
struct LINK *creat_list(int total_elements)
{
    struct LINK *head;
    head = (struct LINK *)malloc(sizeof(struct LINK));
    struct LINK *current = head;
    struct LINK *newnode = NULL;
    for (int i = 0; i < total_elements; i++)
    {
        newnode = (struct LINK *)malloc(sizeof(struct LINK));
        if (newnode == NULL)
            return NULL;
        scanf("%d", &newnode->val);
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
    }
    return head->next;
}
void print_List(struct LINK *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->val);
        head = head->next;
    }
    printf("\n");
}
void print_nodeAddress(struct LINK *head)
{
    while (head != NULL)
    {
        printf("node_address = 0x%x\t", head);
        head = head->next;
    }
    printf("\n");
}
