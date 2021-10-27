#ifndef JUDGE_FUNCTION_H
#define JUDGE_FUNCTION_H

#define op_left_assoc(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '%') /*����*/
#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=')
#define is_function(c) (c >= 'A' && c <= 'Z')
#define is_ident(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
#define false 0
#define true 1

// ������
// ���ȼ�	����	����˳��
// 1		!		��������
// 2		* / %	��������
// 3		+ -		��������
// 4		=		��������
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
#endif
