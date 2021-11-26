#ifndef STACK_H
#define STACK_H
int top = -1;
int size = 32;
void push(char *stack, char data)
{
    stack[++top] = data;
}
char pop(char *stack)
{
    return stack[top--];
}
char Top(const char *stack)
{
    return stack[top];
}
int isEmpty(char *stack)
{
    return top == -1;
}
int isFull(char *stack)
{
    return top == size - 1;
}
#endif
