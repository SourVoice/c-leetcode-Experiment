#include <stdio.h>
#include <string.h>
int isIsomorphic(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return 0;
    //µ•…‰x-y
    char x[256] = {0};
    char y[256] = {0};
    //µ•…‰y-x
    char x2[256] = {0};
    char y2[256] = {0};
    for (int index = 0; s[index] != '\0' && t[index] != '\0'; index++)
    {
        if (y[t[index]] == t[index] && x[t[index]] != s[index])
            return 0;
        x[t[index]] = s[index];
        y[t[index]] = t[index];
        //
        if (x2[s[index]] == s[index] && y2[s[index]] != t[index])
            return 0;
        y2[s[index]] = t[index];
        x2[s[index]] = s[index];
    }
    return 1;
}
//badc
//baba
//"bbbaaaba"x
//"aaabbbba"y
int main()
{
    char *str1 = "bbbaaaba";
    char *str2 = "aaabbbba";
    printf("%d ", isIsomorphic(str1, str2));
}
//0ms