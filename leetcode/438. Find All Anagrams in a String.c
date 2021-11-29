/*438. 找到字符串中所有字母异位词*/
#include <stdlib.h>
#include <string.h>

int *findAnagrams(char *s, char *p, int *returnSize)
{

    int SMap[26] = {0}; //record alpha's count in s str
    int PMap[26] = {0}; //record alpha's count in P str
    int count = 0;
    int len1 = strlen(s);
    int len2 = strlen(p);
    int len = len1 - len2;
    //维护一个len2长的窗口

    int *res = (int *)calloc(len1 + 1, sizeof(int));
    *returnSize = 0;
    if (len1 < 0 || len2 < 0)
    {
        return res;
    }
    for (int i = 0; i < len2; i++)
    {
        PMap[p[i] - 'a']++;
    }

    char *tmp = s;
    for (int j = 0; j <= len; j++)
    {
        tmp = s + j;
        count = 0;
        for (int k = 0; k < len2; k++)
        {
            SMap[tmp[k] - 'a']++;
        }
        for (int m = 0; m < 26; m++)
        {
            if (SMap[m] == PMap[m])
            {
                count++;
            }
            SMap[m] = 0;
        }
        if (count == 26)
        {
            res[(*returnSize)++] = j;
        }
    }
    return res;
}