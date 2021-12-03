#include "stack.h"
#include <assert.h>
#include <stdio.h>

#define STACK_SIZE 100 //只能通过宏来限制堆栈中的值的数量

/*静态数组的堆栈*/
static STACK_TYPE stack[STACK_SIZE];
static int top_element = -1;

/*压入栈*/
void push(STACK_TYPE value)
{
    assert(!is_full()); //检测非满
    top_element += 1;   //push后角标加一
    stack[top_element] = value;
}

/*弹出堆栈*/
void pop(void)
{
    assert(!is_empty()); //assert()是一个检查函数(宏),计算表达式后返回错误
    top_element -= 1;
}

/*去堆栈顶部*/
STACK_TYPE
top(void) //弹出元素的类型是一个堆栈类型,所以返回堆栈类
{
    assert(!is_empty());
    return stack[top_element];
}

int is_empty(void)
{
    return top_element == -1;
}

/*满堆栈后角标减一*/
int is_full(void)
{
    return top_element == STACK_SIZE - 1;
}

void printStack()
{
    int i = top_element;
    printf("打印静态数组堆栈值:\n");
    if (i == -1)
        printf("an empty stack\n");
    while (i != -1)
        printf("%d ", stack[i--]);
    printf("\n");
}

void creatStack(void)
{
    int i = 10;
    while (i != -1)
        push(i--);
    printf("push压入数值后的堆栈:\n");
    printStack();
}

int main()
{
    printStack(); //打印一个空栈
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    creatStack(); //压一个堆栈并打印
    //
    pop();
    pop(); //弹出几个
    pop();
    //
    printStack();
    printf("%d", top()); //取个栈顶

    return 0;
}