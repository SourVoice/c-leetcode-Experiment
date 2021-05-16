#include <stdlib.h>
#include <stdio.h>
typedef struct LINK
{
    int value;
    struct LINK *link;
} Link;
Link *creat_a_link(Link *head)
{
    Link *next = NULL;
    Link *p = NULL;
    p = (Link *)malloc(sizeof(Link));
    next = (Link *)malloc(sizeof(Link));
    if (next != NULL && p != NULL)
    {
        next->value = 5;
        next->link = NULL;
        p->link = next;
        next = next->link;
        next = (Link *)malloc(sizeof(Link));
        if (next != NULL && p->link != NULL)
        {
            next->value = 10;
            next->link = NULL;
            p->link->link = next;
            next = next->link;
            next = (Link *)malloc(sizeof(Link));
            if (next != NULL && p->link->link != NULL)
            {
                next->value = 15;
                next->link = NULL;
                p->link->link->link = next;
                next = next->link;
                next = (Link *)malloc(sizeof(Link));
                if (next != NULL)
                    next->link = NULL;
                p->link->link->link->link = next;
            }
        }
    }
    head = p;
    //free(next);//不能提前释放,否则,next存在尾处,释放后就没地址了
    return head;
}
/*遍历它*/
void printLINK()
{
    Link *head = NULL;
    head = (Link *)malloc(sizeof(Link));
    head = creat_a_link(head);
    head = head->link;
    while (head->link != NULL)
    {
        printf("%d\n", head->value);
        head = head->link;
    }
}

int main()
{
    printLINK();
    return 0;
}