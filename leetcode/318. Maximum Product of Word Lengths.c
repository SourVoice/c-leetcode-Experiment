/*318. 最大单词长度乘积*/
/*暴力法*/
int maxProduct(char **words, int wordsSize)
{
    int *rec = (int *)malloc(sizeof(int) * 26);
    for (int i = 0; i < 26; i++)
    {
        rec[i] = 0;
    }
    int l1 = strlen(words[0]);

    int find = 0;
    int multiRes = 0;
    int res[2] = {0}; //record the l1's index and l2's index
    for (int i = 0; i < wordsSize - 1; i++)
    {
        for (int j = 0; j < strlen(words[i]); j++) //record the first word's letter
        {
            if (!rec[(int)((words[i][j]) - 'a')])
            {
                rec[(int)((words[i][j]) - 'a')]++;
            }
        }
        int l1 = strlen(words[i]);
        for (int j = i + 1; j < wordsSize; j++) //words after the i's word
        {
            for (int k = 0; k < strlen(words[j]); k++)
            {
                if (rec[(int)(words[j][k] - 'a')])
                {
                    find = 0;
                    break;
                }
                find = 1;
            }
            if (find)
            {
                int l2 = strlen(words[j]);
                if (l1 * l2 > multiRes)
                {
                    res[0] = i;
                    res[1] = j;
                    multiRes = l1 * l2;
                }
                find = 0;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            rec[i] = 0;
        }
    }
    return multiRes;
}