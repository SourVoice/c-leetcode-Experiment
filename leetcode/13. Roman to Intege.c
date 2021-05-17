#include <stdio.h>
int getroman_INT(char ch)
{
    int roman_int;
    switch (ch)
    {
    case 'I':
        roman_int = 1;
        break;
    case 'V':
        roman_int = 5;
        break;
    case 'X':
        roman_int = 10;
        break;
    case 'L':
        roman_int = 50;
        break;
    case 'C':
        roman_int = 100;
        break;
    case 'D':
        roman_int = 500;
        break;
    case 'M':
        roman_int = 1000;
        break;
    }
    return roman_int;
}
int romanToInt(char *s)
{
    int num = 0;
    int roman_int = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        roman_int = getroman_INT(s[i]);
        if (getroman_INT(s[i + 1]) > roman_int)
            num -= roman_int;
        else
            num += roman_int;
    }
    return num;
}

int main()
{
    char *roman = "III";
    int n = romanToInt(roman);
    printf("%d\n", n);
    return 0;
}