#include <stdlib.h>
#include <stdio.h>
typedef struct LINK
{
    int value;
    struct LINK *link;
} Link;

int insert_function(Link **rootp, int new_value)
{
    register Link *current; //在cpu缓存里直接暂存内存更快
    register Link *new;
    current = *rootp;
    while (current != NULL &&
           current->value < new_value)
    {
        rootp = &current->link; //指向指针的地址
        current = *rootp;
    }
    /*新节点的内容*/
    new = (Link *)malloc(sizeof(Link));
    if (new == NULL)
        return 0;
    new->value = new_value;
    new->link = current;
    /*根指针指向新节点的地址*/
    *rootp = new;
    return 1;
}