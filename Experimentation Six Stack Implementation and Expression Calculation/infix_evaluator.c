#include "judgeFunction.h"
#include <stdio.h>
#include <string.h>

int top = -1;
int numstackSize = 32;
void pushNum(char *stack, int value)
{
    stack[++top] = value;
}
int popNum(char *stack)
{
    return stack[top--];
}
int topNum(const char *stack)
{
    return stack[top];
}
int isEmptyNum(char *stack)
{
    return top == -1;
}
int isFullNum(char *stack)
{
    return top == numstackSize - 1;
}
int InfixEvaluation(const char *infix)
{

    //Stack for Numbers
    char stack[32];

    //Stack for operators
    char operations[32];
    const char *strpos = infix, *strend = infix + strlen(infix);
    for (int i = 0; i < strlen(infix); i++)
    {
        char c = expression.charAt(i);
        //check if it is number
        if (Character.isDigit(c))
        {
            //Entry is Digit, it could be greater than one digit number
            int num = 0;
            while (Character.isDigit(c))
            {
                num = num * 10 + (c - '0');
                i++;
                if (i < expression.length())
                    c = expression.charAt(i);
                else
                    break;
            }
            i--;
            //push it into stack
            numbers.push(num);
        }
        else if (c == '(')
        {
            //push it to operators stack
            operations.push(c);
        }
        //Closed brace, evaluate the entire brace
        else if (c == ')')
        {
            while (operations.peek() != '(')
            {
                int output = performOperation(numbers, operations);
                //push it back to stack
                numbers.push(output);
            }
            operations.pop();
        }
        // current character is operator
        else if (isOperator(c))
        {
            //1. If current operator has higher precedence than operator on top of the stack,
            //the current operator can be placed in stack
            // 2. else keep popping operator from stack and perform the operation in  numbers stack till
            //either stack is not empty or current operator has higher precedence than operator on top of the stack
            while (!operations.isEmpty() && op_preced(c) <= op_preced(operations.peek()))
            {
                int output = performOperation(numbers, operations);
                //push it back to stack
                numbers.push(output);
            }
            //now push the current operator to stack
            operations.push(c);
        }
    }
    //If here means entire expression has been processed,
    //Perform the remaining operations in stack to the numbers stack

    while (!operations.isEmpty())
    {
        int output = performOperation(numbers, operations);
        //push it back to stack
        numbers.push(output);
    }
    return numbers.pop();
}