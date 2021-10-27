#include <stdio.h>
#include <string.h>
#include "judgeFunction.h"
int shunting_yard(const char *input, char *output)
{
    const char *strpos = input, *strend = input + strlen(input);
    char c, stack[32], sc, *outpos = output;
    unsigned int sl = 0;
    while (strpos < strend)
    {
        c = *strpos;
        if (c != ' ')
        {
            // 扫描到左括号直接入栈
            if (c == '(')
            {
                stack[sl] = c;
                ++sl;
            }
            // 如果输入为数字，则直接入输出队列
            else if (is_ident(c))
            {
                if (is_ident(*(strpos + 1)))
                {
                    *outpos = c;
                    ++outpos;

                    ++strpos;
                    continue;
                }
                *outpos = c;
                ++outpos;

                *outpos = ' ';
                ++outpos;
            }
            // 如果输入为函数记号，则压入堆栈
            else if (is_function(c))
            {
                stack[sl] = c;
                ++sl;
            }
            // 如果输入为函数分割符（如:逗号）
            else if (c == ',')
            {
                int pe = false;
                while (sl > 0)
                {
                    sc = stack[sl - 1];
                    //扫描到左括号
                    //跳出输出循环，此时左括号作为函数边界判定，所以不出栈
                    if (sc == '(')
                    {
                        pe = true;
                        break;
                    }
                    else
                    {
                        // 栈顶元素不是左括号
                        // 将栈顶元素依次出栈并放入输出队列
                        *outpos = sc;
                        ++outpos;

                        *outpos = ' ';
                        ++outpos;
                        sl--;
                    }
                }
                // 如果没有遇到左括号，则有可能是符号放错或者不匹配
                if (!pe)
                {
                    printf("Error: separator or parentheses mismatched\n");
                    return false;
                }
            }
            // 如果输入符号为运算符，然后:
            else if (is_operator(c))
            {
                while (sl > 0)
                {
                    sc = stack[sl - 1];
                    // sc为其栈顶元素
                    // 如果c是左结合性的且它的优先级小于等于栈顶运算符sc的优先级
                    // 或者c是右结合性且它的优先级小于栈顶运算符sc的优先级
                    // 将栈顶元素sc出栈，否则sc进栈
                    if (is_operator(sc) && ((op_left_assoc(c) && (op_preced(c) <= op_preced(sc))) ||
                                            (!op_left_assoc(c) && (op_preced(c) < op_preced(sc)))))
                    {
                        *outpos = sc;
                        ++outpos;

                        *outpos = ' ';
                        ++outpos;
                        sl--;
                    }
                    else
                    {
                        break;
                    }
                }
                //c的优先级大于或大于等于结合性的要求，则将其入栈
                stack[sl] = c;
                ++sl;
            }

            // 扫描到右括号
            else if (c == ')')
            {
                int pe = false;
                // 从栈顶向下扫描左括号，将扫描到左括号之前的栈顶运算符出栈并放入输出队列
                while (sl > 0)
                {
                    sc = stack[sl - 1];
                    if (sc == '(')
                    {
                        pe = true;
                        break;
                    }
                    else
                    {
                        *outpos = sc;
                        ++outpos;

                        *outpos = ' ';
                        ++outpos;
                        sl--;
                    }
                }
                // 如果没有扫描到左括号，则有可能是符号放错或者不匹配
                if (!pe)
                {
                    printf("Error: parentheses mismatched\n");
                    return false;
                }
                // 左括号出栈且不放入输出队列
                sl--;
                // 扫描完左括号后
                // 如果栈顶元素是函数运算符
                // 则将其出栈并放入输出队列
                if (sl > 0)
                {
                    sc = stack[sl - 1];
                    if (is_function(sc))
                    {
                        *outpos = sc;
                        ++outpos;

                        *outpos = ' ';
                        ++outpos;
                        sl--;
                    }
                }
            }
            //未知运算符c
            else
                printf("Unknown token %c\n", c);
        }
        ++strpos;
    }
    // 当所有元素已经读完
    // 栈中还有剩余运算符
    while (sl > 0)
    {
        sc = stack[sl - 1];
        //如果剩余括号，则符号放错或者不匹配
        if (sc == '(' || sc == ')')
        {
            printf("Error: parentheses mismatched\n");
            return false;
        }
        //出栈并放入输出队列
        *outpos = sc;
        ++outpos;

        *outpos = ' ';
        ++outpos;
        --sl;
    }
    *outpos = 0; //指针置零
    return true;
}

int postfixPreformOperation(const char *postfix)
{
    const char *strpos = postfix, *strend = postfix + strlen(postfix);
    int numstack[128];
    int sl; /*stack length*/
    char c;
    int num = 0;
    while (strpos < strend)
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
                int rightop = numstack[--sl];
                int leftop = numstack[--sl];
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
int postfixEvaluator(const char *input)
{
    int result = 0;
    char *output;
    shunting_yard(input, output);
    result = postfixPreformOperation(output);
    return result;
}
