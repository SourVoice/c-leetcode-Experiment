// 1816. �ضϾ���
char *truncateSentence(char *s, int k)
{
    int cnt = 0;

    char *str = s;
    while (cnt < k && *str != '\0')
    {
        if (*str == ' ')
            cnt++;
        str++;
    }
    s[str - s] = '\0';
    return s;
}
int main()
{
    char *s = "Hello how are you Contestant";
    truncateSentence(s, 4);
}