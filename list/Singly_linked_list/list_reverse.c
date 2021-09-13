#include <stdio.h>
#include <stdlib.h>
#include "creat_printList.h"

struct LINK *reverse(struct LINK *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    print_nodeAddress(head);
    struct LINK *new_head = reverse(head->next); //new_head 递去最终为最后一个结点，此后每次返回new_head以保持new_head始终为新的头节点
    // print_nodeAddress(head);
    head->next->next = head;
    head->next = NULL;
    // print_List(head);
    print_nodeAddress(new_head);
    return new_head;
}
int main()
{
    struct LINK *head = NULL;
    head = creat_list(3);
    print_List(head);
    head = reverse(head);
    print_List(head);
}
