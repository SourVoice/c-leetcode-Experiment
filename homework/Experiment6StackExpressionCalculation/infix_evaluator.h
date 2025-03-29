#include "judgeFunction.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

int numTop = -1;
int numstackSize = 32;
void pushNum(int *stack, int value)
{
    stack[++numTop] = value;
}
int popNum(int *stack)
{
    return stack[numTop--];
}
int TopNum(int *stack)
{
    return stack[numTop];
}
int isEmptyNum(int *stack)
{
    return numTop == -1;
}
int isFullNum(int *stack)
{
    return numTop == numstackSize - 1;
}

int performOperation(int *numstack, char *operations)
{
    int a = popNum(numstack);
    int b = popNum(numstack);
    char operation = pop(operations);
    switch (operation)
    {
    case '+':
        return a + b;
    case '-':
        return b - a;
    case '*':
        return a * b;
    case '/':
        if (a == 0)
            printf("Cannot divide by zero");
        return b / a;
    }
    return 0;
}

int InfixEvaluation(const char *infix)
{

    //Stack for Numbers
    int numStack[32];

    //Stack for operators
    char operations[32];
    const char *strpos = infix, *strend = infix + strlen(infix);
    int num = 0;
    while (strpos <= strend)
    {
        char c = *strpos;
        //check if it is number
        if (is_ident(c))
        {
            //Entry is Digit, it could be greater than one digit number
            num = num + (c - '0');

            if (is_ident(*(strpos + 1)))
            {
                num *= 10;
                ++strpos;
                continue;
            }
            else
            {
                //push it into stack
                pushNum(numStack, num);
                num = 0;
            }
        }
        else if (c == '(')
        {
            //push it to operators stack
            push(operations, c);
        }
        //Closed brace, evaluate the entire brace
        else if (c == ')')
        {
            while (Top(operations) != '(')
            {
                int output = performOperation(numStack, operations);
                //push it back to stack
                pushNum(numStack, output);
            }
            pop(operations);
        }
        // current character is operator
        else if (is_operator(c))
        {
            //1. If current operator has higher precedence than operator on top of the stack,
            //the current operator can be placed in stack
            // 2. else keep popping operator from stack and perform the operation in  numbers stack till
            //either stack is not empty or current operator has higher precedence than operator on top of the stack
            while (!isEmpty(operations) && op_preced(c) <= op_preced(Top(operations)))
            {
                int output = performOperation(numStack, operations);
                //push it back to stack
                pushNum(numStack, output);
            }
            //now push the current operator to stack
            push(operations, c);
        }
        ++strpos;
    }
    //If here means entire expression has been processed,
    //Perform the remaining operations in stack to the numbers stack

    while (!isEmpty(operations))
    {
        int output = performOperation(numStack, operations);
        //push it back to stack
        pushNum(numStack, output);
    }
    return popNum(numStack);
}
