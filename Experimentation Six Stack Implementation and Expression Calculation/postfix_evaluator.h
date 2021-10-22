#include <stdio.h>
#include <string.h>

#define op_left_assoc(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '%') /*����*/
#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=')
#define is_function(c) (c >= 'A' && c <= 'Z')
#define is_ident(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
#define false 0
#define true 1
/*���ȼ��ж�*/
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
    //�����벻�������
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

int postfixEvaluator(const char *postfix)
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
