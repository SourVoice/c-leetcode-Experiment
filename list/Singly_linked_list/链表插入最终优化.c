#include <stdlib.h>
#include <stdio.h>
typedef struct LINK
{
    int value;
    struct LINK *next;
} Link;

int insert_function(Link **rootp, int new_value)
{
    register Link *current; //在cpu缓存里直接暂存内存更快
    register Link *newnode;
    current = *rootp;
    while (current != NULL &&
           current->value < new_value)
    {
        rootp = &current->next; //指向指针的地址
        current = *rootp;
    }
    /*新节点的内容*/
    newnode = (Link *)malloc(sizeof(Link));
    if (newnode == NULL)
        return 0;
    newnode->value = new_value;
    newnode->next = current;
    /*根指针指向新节点的地址*/
    *rootp = newnode;
    return 1;
}