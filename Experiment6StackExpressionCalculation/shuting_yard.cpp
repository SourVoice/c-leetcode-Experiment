#include <cstring>
#include <cstdio>
unsigned int op_arg_count(const char c)
{
    switch (c)
    {
        //�����
    case '*':
    case '/':
    case '%':
    case '+':
    case '-':
    case '=':
        return 2;
        //�׳�
    case '!':
        return 1;
        //���������
    default:
        return c - 'A';
    }
    return 0;
}

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
            // ɨ�赽������ֱ����ջ
            if (c == '(')
            {
                stack[sl] = c;
                ++sl;
            }
            // �������Ϊ���֣���ֱ�����������
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
            // �������Ϊ�����Ǻţ���ѹ���ջ
            else if (is_function(c))
            {
                stack[sl] = c;
                ++sl;
            }
            // �������Ϊ�����ָ������:���ţ�
            else if (c == ',')
            {
                int pe = false;
                while (sl > 0)
                {
                    sc = stack[sl - 1];
                    //ɨ�赽������
                    //�������ѭ������ʱ��������Ϊ�����߽��ж������Բ���ջ
                    if (sc == '(')
                    {
                        pe = true;
                        break;
                    }
                    else
                    {
                        // ջ��Ԫ�ز���������
                        // ��ջ��Ԫ�����γ�ջ�������������
                        *outpos = sc;
                        ++outpos;

                        *outpos = ' ';
                        ++outpos;
                        sl--;
                    }
                }
                // ���û�����������ţ����п����Ƿ��ŷŴ���߲�ƥ��
                if (!pe)
                {
                    printf("Error: separator or parentheses mismatched\n");
                    return false;
                }
            }
            // ����������Ϊ�������Ȼ��:
            else if (is_operator(c))
            {
                while (sl > 0)
                {
                    sc = stack[sl - 1];
                    // scΪ��ջ��Ԫ��
                    // ���c�������Ե����������ȼ�С�ڵ���ջ�������sc�����ȼ�
                    // ����c���ҽ�������������ȼ�С��ջ�������sc�����ȼ�
                    // ��ջ��Ԫ��sc��ջ������sc��ջ
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
                //c�����ȼ����ڻ���ڵ��ڽ���Ե�Ҫ��������ջ
                stack[sl] = c;
                ++sl;
            }

            // ɨ�赽������
            else if (c == ')')
            {
                int pe = false;
                // ��ջ������ɨ�������ţ���ɨ�赽������֮ǰ��ջ���������ջ�������������
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
                // ���û��ɨ�赽�����ţ����п����Ƿ��ŷŴ���߲�ƥ��
                if (!pe)
                {
                    printf("Error: parentheses mismatched\n");
                    return false;
                }
                // �����ų�ջ�Ҳ������������
                sl--;
                // ɨ���������ź�
                // ���ջ��Ԫ���Ǻ��������
                // �����ջ�������������
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
            //δ֪�����c
            else
                printf("Unknown token %c\n", c);
        }
        ++strpos;
    }
    // ������Ԫ���Ѿ�����
    // ջ�л���ʣ�������
    while (sl > 0)
    {
        sc = stack[sl - 1];
        //���ʣ�����ţ�����ŷŴ���߲�ƥ��
        if (sc == '(' || sc == ')')
        {
            printf("Error: parentheses mismatched\n");
            return false;
        }
        //��ջ�������������
        *outpos = sc;
        ++outpos;

        *outpos = ' ';
        ++outpos;
        --sl;
    }
    *outpos = 0; //ָ������
    return true;
}

int execution_order(const char *input)
{
    printf("order: (arguments in reverse order)\n");
    const char *strpos = input, *strend = input + strlen(input);
    char c, res[4];
    unsigned int sl = 0, sc, stack[32], rn = 0;
    // While there are input tokens left
    while (strpos < strend)
    {
        // Read the next token from input.
        c = *strpos;
        // If the token is a value or identifier
        if (is_ident(c))
        {
            // Push it onto the stack.
            stack[sl] = c;
            ++sl;
        }
        // Otherwise, the token is an operator  (operator here includes both operators, and functions).
        else if (is_operator(c) || is_function(c))
        {
            sprintf(res, "_%02d", rn);
            printf("%s = ", res);
            ++rn;
            // It is known a priori that the operator takes n arguments.
            unsigned int nargs = op_arg_count(c);
            // If there are fewer than n values on the stack
            if (sl < nargs)
                return false; // (Error) The user has not input sufficient values in the expression.
            // Else, Pop the top n values from the stack.
            // Evaluate the operator, with the values as arguments.
            if (is_function(c))
            {
                printf("%c(", c);
                while (nargs > 0)
                {
                    sc = stack[sl - 1];
                    sl--;
                    if (nargs > 1)
                        printf("%s, ", &sc);
                    else
                        printf("%s)\n", &sc);
                    --nargs;
                }
            }
            else
            {
                if (nargs == 1)
                {
                    sc = stack[sl - 1];
                    sl--;
                    printf("%c %s;\n", c, &sc);
                }
                else
                {
                    sc = stack[sl - 1];
                    sl--;
                    printf("%s %c ", &sc, c);
                    sc = stack[sl - 1];
                    sl--;
                    printf("%s;\n", &sc);
                }
            }
            // Push the returned results, if any, back onto the stack.
            stack[sl] = *(unsigned int *)res;
            ++sl;
        }
        ++strpos;
    }
    // If there is only one value in the stack
    // That value is the result of the calculation.
    if (sl == 1)
    {
        sc = stack[sl - 1];
        sl--;
        printf("%s is a result\n", &sc);
        return true;
    }
    // If there are more values in the stack
    // (Error) The user input has too many values.
    return false;
}

int main()
{
    // functions: A() B(a) C(a, b), D(a, b, c) ...
    // identifiers: 0 1 2 3 ... and a b c d e ...
    // operators: = - + / * % !
    const char *input = "12+(256*7-1)-10";
    char output[128];
    printf("input: %s\n", input);
    if (shunting_yard(input, output))
    {
        printf("output: %s\n", output);
        if (!execution_order(output))
            printf("\nInvalid input\n");
    }
    return 0;
}
/*
a = D(f - b * c + d, !e, g)
12+(256*7-1)-10
*/