#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "stack_malloc.h"

static STACK_TYPE *stack; //用指针代替数组
static size_t stack_size;
static int top_element = -1;

/*创建堆栈*/
void creat_stack(size_t size)
{
    assert(stack_size == 0);
    stack_size = size;
    stack = malloc(stack_size * sizeof(STACK_TYPE));
    assert(stack != NULL);
}

/*释放堆栈*/
void destory_stack(void)
{
    assert(stack_size > 0);
    stack_size = 0;
    free(stack);
    stack = NULL;
}

void push(STACK_TYPE value)
{
    assert(!is_full());
    top_element += 1;
    *(stack + top_element) = value;
}

void pop()
{
    assert(!is_empty());
    top_element -= 1;
}

STACK_TYPE top(void)
{
    assert(!is_empty);
    return *(stack + top_element);
}

int is_empty(void)
{
    assert(stack_size > 0);
    return top_element == -1;
}

int is_full(void)
{
    assert(stack_size > 0);
    return top_element == stack_size - 1;
}