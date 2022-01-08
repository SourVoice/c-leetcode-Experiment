// 58. 最后一个单词的长度

int lengthOfLastWord(char *s)
{
    int len_s = strlen(s);
    if (len_s == 1)
        return 1;
    char *strend = s + len_s;
    char *strpos = strend - 1;

    int len = 0;
    while (*strpos == ' ')
        strpos--;
    while (strpos >= s && *strpos != ' ')
    {
        len++;
        strpos--;
    }
    return len;
}