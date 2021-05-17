
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 32

typedef struct
{
    char data[MAXSIZE];
    int top_index;
} sqstack; //ջ�ṹ

sqstack *sqstack_creat();
void sqstack_push(sqstack *, char);  //��ջ
void sqstack_pop(sqstack *, char *); //��ջ
char sqstack_top(sqstack *);         //ջ����¼
int is_empty(sqstack *);             //���Կ�ջ
int is_full(sqstack *);              //�������
void sqstack_display(sqstack *);

int main(void)
{
    //������ʽ
    char equation[7] = {0};
    for (int i = 0; i < 7; i++)
    {
        equation[i] = getchar();
    }
    //��׺ת��׺
    sqstack *pre = sqstack_creat();     //��׺���ʽ
    sqstack *operator= sqstack_creat(); //������ջ
    for (int i = 0; i < 7; i++)
    {
        if (equation[i] >= '0' && equation[i] <= '9')
            sqstack_push(pre, equation[i]);
        else
        {
            if (i == 1)
                sqstack_push(operator, equation[i]);
            else
            {
                char operator_top = sqstack_top(operator);
                switch (equation[i])
                {
                case '+':
                    if (operator_top == '*' || operator_top == '/') //ջ��Ϊ'*'��'/'ʱ��������ջ���׺ջ
                        while (operator->top_index != 0)
                        {
                            sqstack_push(pre, operator_top);
                            sqstack_pop(operator, & operator_top);
                            operator_top = sqstack_top(operator);
                        }
                    else
                        sqstack_push(operator, equation[i]);
                    break;
                case '-':
                    if (operator_top == '*' || operator_top == '/') //ջ��Ϊ'*'��'/'ʱ��������ջ���׺ջ
                        while (operator->top_index != 0)
                        {
                            sqstack_push(pre, operator_top);
                            sqstack_pop(operator, & operator_top);
                            operator_top = sqstack_top(operator);
                        }
                    else
                        sqstack_push(operator, equation[i]);
                    break;
                case '*':
                    sqstack_push(operator, equation[i]);
                    break;
                case '/':
                    sqstack_push(operator, equation[i]);
                    break;
                }
            }
        }
    }
    //������ջȫ��������push����pre
    char operator_top = sqstack_top(operator);
    while (operator->top_index != 0)
    {
        sqstack_push(pre, operator_top);
        sqstack_pop(operator, & operator_top);
        operator_top = sqstack_top(operator);
    }
    //pre��ת
    sqstack *tail_equation = sqstack_creat(); //��׺���ʽ��ջ��ʽ
    char pre_top = sqstack_top(pre);
    while (pre->top_index != 0)
    {
        sqstack_push(tail_equation, pre_top);
        sqstack_pop(pre, &pre_top);
        pre_top = sqstack_top(pre);
    }
    //�����׺���ʽ
    sqstack *result_stack = sqstack_creat();
    char top_tail = sqstack_top(tail_equation);
    while (tail_equation->top_index != 0)
    {
        if (top_tail >= '0' && top_tail <= '9')
        {
            sqstack_push(result_stack, top_tail);
            sqstack_pop(pre, &top_tail);
        }
        else
        {
            char top_num = '0';
            //ȡ��һ����������pop��
            top_num = sqstack_top(result_stack);
            char first_operate_num = top_num;
            sqstack_pop(result_stack, &first_operate_num);
            //ȡ�ڶ�����������pop��
            top_num = sqstack_top(result_stack);
            char second_operate_num = top_num;
            sqstack_pop(result_stack, &second_operate_num);
            int temp_result_num = 0;
            switch (top_tail)
            {
            case '+':
                temp_result_num = second_operate_num + first_operate_num;
                sqstack_push(result_stack, temp_result_num);
                break;
            case '*':
                temp_result_num = second_operate_num * first_operate_num;
                sqstack_push(result_stack, temp_result_num);
                break;
            case '-':
                temp_result_num = second_operate_num - first_operate_num;
                sqstack_push(result_stack, temp_result_num);
                break;
            case '/':
                temp_result_num = second_operate_num / first_operate_num;
                sqstack_push(result_stack, temp_result_num);
                break;
            }
        }
        top_tail = sqstack_top(tail_equation);
    }
    int result = sqstack_top(result_stack);
    return 0;
}
//��ʼ��ջ
sqstack *sqstack_creat()
{
    sqstack *stack;
    stack = (sqstack *)malloc(sizeof(sqstack));
    stack->top_index = -1;
    return stack;
}
//push
void sqstack_push(sqstack *stack, char element) //��ջ
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
//����ջ��ֵ
char sqstack_top(sqstack *stack)
{
    assert(!is_empty(stack));
    char element = stack->data[stack->top_index];
    return element;
}

//���
int is_empty(sqstack *stack)
{
    return stack->top_index == -1;
}
//����
int is_full(sqstack *stack)
{
    return stack->top_index == MAXSIZE - 1;
}