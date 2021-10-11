#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _Node
{
    int value;
    struct _Node *next;
} Node, *List;

void print_list(List list)
{
    Node *p = list->next;
    while (p)
    {
        printf("%d  ", p->value);
        p = p->next;
    }
}

void free_list(List list)
{
    Node *p = list->next, *q;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
}

void remove_duplicates(List list)
{
    Node *current = NULL;
    Node *pre = NULL;
    Node *p = list->next;
    int val;
    while (p)
    {
        pre = p;
        current = p->next;
        val = p->value;
        while (current)
        {
            if (current->value == val)
            {
                pre->next = current->next;
                free(current);
                current = pre->next;
                continue;
            }
            pre = current;
            current = current->next;
        }
        p = p->next;
    }
}

//  new  element  will  be  appended  to  tail
List create_list()
{
    List list = (Node *)malloc(sizeof(Node));
    list->next = NULL;
    int v;
    Node *prev = list;

    //  sample  input:  1  2  3  #
    int num;
    scanf("%d", &num);
    int i = 0;
    while (i < num)
    {
        i++;
        scanf("%d", &v);
        Node *node = (Node *)malloc(sizeof(Node));
        node->value = v;
        node->next = NULL;
        prev->next = node;
        prev = node;
    }

    return list;
}

int main(int argc, char **argv)
{
    List list = create_list();
    remove_duplicates(list);
    print_list(list);
    free_list(list);
    return 0;
}