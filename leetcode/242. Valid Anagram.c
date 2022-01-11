// 242. 有效的字母异位词
//哈希

bool isAnagram(char *s, char *t)
{
    int s_pool[26] = {0};
    int t_pool[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
        s_pool[s[i] - 'a']++;
    for (int i = 0; t[i] != '\0'; i++)
        t_pool[t[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        if (s_pool[i] != t_pool[i])
            return false;
    return true;
}
//优化:
bool isAnagram(char *s, char *t)
{
    int letters[26] = {0};

    char *temp = s;
    while (*temp)
    {
        letters[*temp - 'a'] += 1;
        temp++;
    }

    temp = t;
    while (*temp)
    {
        letters[*temp - 'a'] -= 1;
        temp++;
    }

    for (int i = 0; i < sizeof(letters) / sizeof(int); i++)
    {
        if (letters[i] != 0)
            return false;
    }
    return true;
}