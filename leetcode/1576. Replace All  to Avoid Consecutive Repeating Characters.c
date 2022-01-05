// 1576. 替换所有的问号
char *modifyString(char *s)
{
    char replace[3] = {'a', 'b', 'c'};

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '?')
        {
            if (i == 0)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (s[i + 1] != replace[k])
                    {
                        s[i] = replace[k];
                        break;
                    }
                }
            }
            else if (s[i + 1] == '\0')
            {
                for (int k = 0; k < 3; k++)
                {
                    if (s[i - 1] != replace[k])
                    {
                        s[i] = replace[k];
                        break;
                    }
                }
            }
            else
            {
                for (int k = 0; k < 3; k++)
                {
                    if (s[i + 1] != replace[k] && s[i - 1] != replace[k])
                    {
                        s[i] = replace[k];
                        break;
                    }
                }
            }
        }
    }
    return s;
}