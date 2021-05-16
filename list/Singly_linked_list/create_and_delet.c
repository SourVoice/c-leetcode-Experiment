#include <stdlib.h>
#include <stdio.h>

typedef struct LINK
{
    int value;
    struct LINK *next;
} Link;
Link *delet(Link **rootp, int target_value)
{
    Link *current = NULL;
    Link *head = NULL;
    head = *rootp;
    current = *rootp;
    rootp = &current->next;
    if (*rootp == NULL)
        return NULL;

    while (current != NULL)
    {

        if (current->value == target_value)
        {
            /*删除头节点*/
            if (current == head)
            {
                head = head->next;
                free(current);
                current = head;
                continue;
            }

            else
            {
                *rootp = current->next;
                free(current);
                current = *rootp;
            }
        }
        rootp = &current->next;
        current = *rootp;
    }
    return head;
}
int main()
{
    /*创建列表*/
    Link *p = NULL;
    p = (Link *)malloc(sizeof(Link));
    if (p == NULL)
        return 0;
    Link *pnew = NULL; //结点内容
    Link *head = NULL;
    head = p; //头节点,记录p最开始指向的地址
    if (head == NULL)
        return 0;
    for (int i = 0; i < 5; i++)
    {
        pnew = (Link *)malloc(sizeof(Link));
        if (pnew == NULL)
            break;
        scanf("%d", &pnew->value);
        pnew->next = NULL;
        p->next = pnew;
        p = pnew;
    }
    /*print all of them*/
    head = head->next;
    head = delet(&head, 10);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", head->value);
        head = head->next;
    }
    return 0;
}