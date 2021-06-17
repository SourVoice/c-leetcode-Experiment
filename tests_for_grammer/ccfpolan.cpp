
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 32

typedef struct
{
    char data[MAXSIZE];
    int top_index;
} sqstack; //栈结构

sqstack *sqstack_creat();
void sqstack_push(sqstack *, char);  //入栈
void sqstack_pop(sqstack *, char *); //出栈
char sqstack_top(sqstack *);         //栈顶记录
int is_empty(sqstack *);             //断言空栈
int is_full(sqstack *);              //断言溢出
void sqstack_display(sqstack *);
void solution();
int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();
    while (n)
    {
        solution();
        n--;
    }
    return 0;
}

void solution()
{
    //输入表达式
    char equation[7] = {0};
    for (int i = 0; i < 7; i++)
    {
        equation[i] = getchar();
    }
    getchar();
    //中缀转后缀
    sqstack *pre = sqstack_creat();       //后缀表达式
    sqstack *operation = sqstack_creat(); //操作符栈
    for (int i = 0; i < 7; i++)
    {
        if (equation[i] >= '0' && equation[i] <= '9')
            sqstack_push(pre, equation[i]);
        else
        {
            if (i == 1)
                sqstack_push(operation, equation[i]);
            else
            {
                char operation_top = sqstack_top(operation);
                switch (equation[i])
                {
                case '+':
                    if (operation_top == '*' || operation_top == '/') //栈顶为'*'或'/'时弹出符号栈入后缀栈
                        while (!is_empty(operation))
                        {
                            sqstack_push(pre, operation_top);
                            sqstack_pop(operation, &operation_top);
                            operation_top = sqstack_top(operation);
                        }
                    else
                        sqstack_push(operation, equation[i]);
                    break;
                case '-':
                    if (operation_top == '*' || operation_top == '/') //栈顶为'*'或'/'时弹出符号栈入后缀栈
                        while (!is_empty(operation))
                        {
                            sqstack_push(pre, operation_top);
                            sqstack_pop(operation, &operation_top);
                            operation_top = sqstack_top(operation);
                        }
                    else
                        sqstack_push(operation, equation[i]);
                    break;
                case '*':
                    sqstack_push(operation, equation[i]);
                    break;
                case '/':
                    sqstack_push(operation, equation[i]);
                    break;
                }
            }
        }
    }
    //操作符栈全部弹出并push进入pre
    while (!is_empty(operation))
    {
        char operation_top = sqstack_top(operation);
        sqstack_push(pre, operation_top);
        sqstack_pop(operation, &operation_top);
    }
    //pre反转
    sqstack *tail_equation = sqstack_creat(); //后缀表达式的栈形式
    while (!is_empty(pre))
    {
        char pre_top = sqstack_top(pre);
        sqstack_push(tail_equation, pre_top);
        sqstack_pop(pre, &pre_top);
    }
    //计算后缀表达式
    sqstack *result_stack = sqstack_creat();
    while (!is_empty(tail_equation) && !is_empty(tail_equation))
    {
        char top_tail = sqstack_top(tail_equation); //后缀式顶元素
        if (top_tail >= '0' && top_tail <= '9')
        {
            sqstack_push(result_stack, top_tail);
        }
        else
        {
            char top_num = '0';
            //取第一个操作数并pop掉
            top_num = sqstack_top(result_stack);
            char first_operate_num = top_num;
            sqstack_pop(result_stack, &first_operate_num);
            //取第二个操作数并pop掉
            top_num = sqstack_top(result_stack);
            char second_operate_num = top_num;
            sqstack_pop(result_stack, &second_operate_num);
            int temp_result_num = 0;
            switch (top_tail)
            {
            case '+':
                temp_result_num = (int)(second_operate_num - '0') + (int)(first_operate_num - '0');
                sqstack_push(result_stack, (char)temp_result_num + '0');
                break;
            case '*':
                temp_result_num = (int)(second_operate_num - '0') * (int)(first_operate_num - '0');
                sqstack_push(result_stack, (char)temp_result_num + '0');
                break;
            case '-':
                temp_result_num = -(int)(second_operate_num - '0') - (int)(first_operate_num - '0');
                sqstack_push(result_stack, (char)temp_result_num + '0');
                break;
            case '/':
                temp_result_num = (int)(second_operate_num - '0') / (int)(first_operate_num - '0');
                sqstack_push(result_stack, (char)temp_result_num + '0');
                break;
            }
        }
        sqstack_pop(tail_equation, &top_tail);
        if (is_empty(tail_equation))
            break;
        top_tail = sqstack_top(tail_equation);
    }
    int result = sqstack_top(result_stack) - '0';
    if (result == 24)
        printf("Yes\n");
    else
        printf("No\n");
}
//初始化栈
sqstack *sqstack_creat()
{
    sqstack *stack;
    stack = (sqstack *)malloc(sizeof(sqstack));
    stack->top_index = -1;
    return stack;
}
//push
void sqstack_push(sqstack *stack, char element) //入栈
{
    assert(!is_full(stack));
    stack->data[++stack->top_index] = element;
}
//pop
void sqstack_pop(sqstack *stack, char *element)
{
    assert(!is_empty(stack));
    *element = stack->data[stack->top_index--];
}
//返回栈顶值
char sqstack_top(sqstack *stack)
{
    assert(!is_empty(stack));
    char element = stack->data[stack->top_index];
    return element;
}

//验空
int is_empty(sqstack *stack)
{
    return stack->top_index == -1;
}
//验满
int is_full(sqstack *stack)
{
    return stack->top_index == MAXSIZE - 1;
}