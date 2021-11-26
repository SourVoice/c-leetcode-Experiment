#ifndef JUDGE_FUNCTION_H
#define JUDGE_FUNCTION_H

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
#endif
