#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "stack_malloc.h"

typedef struct STACK_NODE
{
    STACK_TYPE value;
    struct STACK_NODE *next;
} Stack_Node;

static Stack_Node *stack; //堆栈指向链表

void creat_stack();

void destory_stack()
{
    assert(stack != NULL);
    free(stack);
    stack = NULL;
}

void push(STACK_TYPE new_value)
{
    /*这相当于一个尾插*/
    Stack_Node *new_node = NULL;

    new_node = (Stack_Node *)malloc(sizeof(Stack_Node));
    assert(new_node != NULL);
    new_node->value = new_value;
    new_node->next = stack;
    stack = new_node;
}

void pop()
{
    Stack_Node *delete_this = NULL;

    assert(!is_empty());
    delete_this = stack; //取当前结点
    stack = delete_this->next;
    free(delete_this); //去掉该节点
    printf("\n");
}

STACK_TYPE
top()
{
    assert(!is_empty());
    printf("\n");
    return stack->value;
}

int is_empty()
{
    return stack == NULL;
}

int is_full()
{
    return 0; //动态的不可能填满
}

void printStack()
{

    int flag_for_top = 1;
    while (!is_empty())
    {
        printf("%d ", stack->value);
        if (top())
        {
            printf("%d ", top());
            continue;
        }
        stack = stack->next;
    }
}

int main()
{
    for (int counter = 0; counter < 10; counter++)
        push(counter);

    printStack();
    return 0;
}