/*前缀*/

#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#define op_left_assoc(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '%') /*左结合*/
#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=')
#define is_function(c) (c >= 'A' && c <= 'Z')
#define is_ident(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
#define false 0
#define true 1

// 操作符
// 优先级	符号	运算顺序
// 1		!		从右至左
// 2		* / %	从左至右
// 3		+ -		从左至右
// 4		=		从右至左
int op_preced(const char c)
{
    switch (c)
    {
    case '!':
        return 4;
    case '*':
    case '/':
    case '%':
        return 3;
    case '+':
    case '-':
        return 2;
    case '=':
        return 1;
    }
    //若输入不是运算符
    return 0;
}
void reverse(const char *input, char *output)
//reverse input to output
{
    const char *strstart = input, *strpos = input + (strlen(input) - 1);
    char *outpos = output;
    int k = 0;
    char c;
    while (strstart <= strpos)
    {
        c = *strpos;
        if (c != ' ')
        {
            if (is_ident(c))
            {
                if ((strstart != strpos) && is_ident(*(strpos - 1)))
                {
                    k++;
                    strpos--;
                    continue;
                }
                else
                {
                    for (int index = 0; index <= k; index++)
                    {
                        c = *(strpos + index);
                        *outpos = c;
                        ++outpos;
                    }
                    k = 0;
                }
                *outpos = ' ';
                ++outpos;
            }
            else
            {
                *outpos = c;
                ++outpos;

                *outpos = ' ';
                ++outpos;
            }
        }
        strpos--;
    }
    *outpos = '\0';
}
//turn infix to prefix and put it in output
void infix_to_prefix(const char *infix, char *output)
{
    int i = 0, j = 0;
    char c;
    /*reverse*/
    char *reinfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    reverse(infix, reinfix);
    // Reverse the infix expression
    top = -1;
    char *strpos = reinfix;
    char stack[32]; //stack for operator
    char *prefix = (char *)malloc(128 * sizeof(char));
    while (*strpos != '\0')
    {
        c = *strpos;
        if (c != ' ')
        {
            // if an alphabet is found then copy it to the output string
            if (is_ident(c))
            {
                if (is_ident(*(strpos + 1)))
                {
                    prefix[j] = c;
                    j++;
                    ++strpos;
                    continue;
                }
                prefix[j] = c;
                j++;

                prefix[j] = ' ';
                j++;
            }
            // In the reversed string, closing bracket will be found first so put it in the stack
            else if (c == ')')
            {
                push(stack, c);
            }
            // if an opening bracket is found, then
            else if (c == '(') /* when closing bracket is found */
            {
                if (c == '(')
                {
                    while (Top(stack) != ')') /* pop till opening bracket is found */
                    {
                        prefix[j] = pop(stack);
                        j++;

                        prefix[j] = ' ';
                        j++;
                    }
                    pop(stack);
                }
            }
            else
            {
                // if the stack if empty, then we simply put the operator in stack
                if (isEmpty(stack))
                {
                    push(stack, c);
                }
                // if the precedence of operator is less than the stack top then
                else if (op_preced(c) < op_preced(Top(stack)))
                {
                    prefix[j] = pop(stack); // pop the stack top and add it to the prefix string
                    j++;

                    prefix[j] = ' ';
                    j++;
                    // if you have an operator that has precedence greater than operator
                    while (op_preced(Top(stack)) > op_preced(c))
                    {
                        prefix[j] = pop(stack); // Pop the operator
                        j++;

                        prefix[j] = ' ';
                        j++;
                        if (top < 0)
                        {
                            break;
                        }
                    }
                    push(stack, c);
                }
                // if the precedence of operator is greater than or equal to the stack top
                else if (op_preced(c) >= op_preced(Top(stack)))
                {
                    push(stack, c); // Push it onto the stack
                }
            }
        }
        ++strpos;
    }
    // At the end remove all the operators from the stack
    while (top != -1)
    {
        prefix[j] = pop(stack);
        j++;

        prefix[j] = ' ';
        j++;
    }
    prefix[j] = '\0';
    // Reverse the final string before output
    reverse(prefix, output);

    printf("从 PREFIX NOTATION : %s \n", output);
}

int prefixPerformOperation(const char *prefix)
{
    char *output = (char *)malloc((strlen(prefix) + 1) * sizeof(char));
    reverse(prefix, output);
    const char *strpos = output, *strend = output + strlen(output);
    int numstack[128] = {0};
    int sl = 0; /*stack length*/
    char c;
    int num = 0;
    while (*strpos != '\0')
    {
        c = *strpos;
        if (c != ' ')
        {
            if (is_ident(c))
            {
                num = num + (c - '0');
                if (is_ident(*(strpos + 1)))
                {
                    num *= 10;
                }
                else
                {
                    numstack[sl] = num;
                    ++sl;
                    num = 0;
                }
            }
            else if (is_operator(c))
            {
                int leftop = numstack[--sl];
                int rightop = numstack[--sl];
                switch (c)
                {
                case '+':
                    numstack[sl++] = leftop + rightop;
                    break;
                case '-':
                    numstack[sl++] = leftop - rightop;
                    break;
                case '*':
                    numstack[sl++] = leftop * rightop;
                    break;
                case '/':
                    numstack[sl++] = leftop / rightop;
                    break;
                default:
                    printf("wrong operator");
                    break;
                }
            }
        }
        ++strpos;
    }
    return numstack[0];
}
int prefixEvaculator(const char *input)
{
    int result = 0;
    char *output = (char *)malloc(2 * (strlen(input) + 1) * sizeof(char));
    infix_to_prefix(input, output);
    result = prefixPerformOperation(output);
    return result;
}
int main()
{
    char *input = "12+(256*7-1)-10";
    printf("input:%s\n", input);
    if (input)
    {
        printf("result:%d", prefixEvaculator(input));
    }
    return 0;
}