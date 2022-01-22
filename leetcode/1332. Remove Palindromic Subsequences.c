// 1332. 删除回文子序列

int removePalindromeSub(char *s)
{
    int len = strlen(s);
    char *strend = s + len - 1;
    while (s < strend && *s == *strend)
    {
        strend--;
        s++;
    }
    return strend > s ? 2 : 1;
}