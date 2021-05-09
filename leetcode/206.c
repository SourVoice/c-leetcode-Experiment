#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *preview = NULL;
    struct ListNode *current = NULL;
    struct ListNode *temp = NULL;
    current = head;
    int flag = 0;
    if (head == NULL)
        return NULL;
    preview = current->next;
    while (preview != NULL)
    {
        head->next = NULL;
        temp = preview->next;
        preview->next = current;
        current = preview;
        preview = temp;
        temp = NULL;
    }
    head = current;
    return head;
}
// struct ListNode *creat()
// {
//     struct ListNode *current = NULL;
//     struct ListNode *new = NULL;
//     struct ListNode *head = NULL;
//     head = malloc(sizeof(struct ListNode));
//     current = head;
//     for (int i = 0; i < 3; i++)
//     {
//         new = malloc(sizeof(struct ListNode));
//         new->val = scanf("%d", &new->val);
//         new->next = NULL;
//         current->next = new;
//         current = new;
//         new = NULL;
//     }
//     return head->next;
// }
// void printList(struct ListNode *head)
// {
//     while (head != NULL)
//     {
//         printf("%d ", head->val);
//         head = head->next;
//     }
// }
// int main()
// {
//     struct ListNode *a_list = NULL;
//     a_list = creat();
//     printList(a_list);
//     // a_list = reverseList(a_list);
//     // printList(a_list);
//     return 0;
// }