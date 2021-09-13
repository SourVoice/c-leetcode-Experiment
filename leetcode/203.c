#include <stdio.h>
#include <stdlib.h>

struct LINK
{
    int val;
    struct LINK *next;
};
//没有使用指针的指针
struct LINK *removeElements(struct LINK *head, int val)
{
    struct LINK *current = head;
    struct LINK *preview = head;
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
struct LINK *creat()
{
    struct LINK *head = NULL;
    head = (struct LINK *)malloc(sizeof(struct LINK *));
    if (head == NULL)
        return NULL;
    struct LINK *current = head;
    struct LINK *newnode = NULL;
    for (int i = 0; i < 1; i++)
    {
        newnode = (struct LINK *)malloc(sizeof(struct LINK *));
        if (newnode == NULL)
            return NULL;
        scanf("%d", &newnode->val);
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
    }
    return head->next;
}
void printList(struct LINK *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}
int main()
{
    struct LINK *head = NULL;
    head = creat();
    printList(head);
    head = removeElements(head, 1);
    printList(head);
    return 0;
}