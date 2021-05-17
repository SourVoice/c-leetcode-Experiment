#include "sqstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����ջ
sqstack *sqstack_creat()
{
    sqstack *stack;
    stack = (sqstack *)malloc(sizeof(stack));
    stack->top_index = -1;
    return stack;
}
//push it
int sqstack_push(sqstack *stack, int element)
{
    assert(!is_full(stack));
    stack->data[++stack->top_index] = element;
    return 0;
}
//�鶥
int sqstack_pop(sqstack *stack, int *element)
{
    assert(!is_empty(stack));
    *element = stack->data[stack->top_index--];
    return 0;
}
int sqstack_top(sqstack *stack, int *element)
{
    assert(!is_empty(stack));
    *element = stack->data[stack->top_index];
    return 0;
}
//����ջ
int is_empty(sqstack *stack)
{
    return stack->top_index == -1;
}
int is_full(sqstack *stack)
{
    return stack->top_index == MAXSIZE - 1;
}