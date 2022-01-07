// 1614. 括号的最大嵌套深度
int maxDepth(char *s)
{
        int ans = 0;
        int size = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
                if (s[i] == '(')
                {
                        size++;
                        ans = fmax(ans, size);
                }
                else if (s[i] == ')')
                        size--;
        }
        return ans;
}
