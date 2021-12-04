/*506.相对名次*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int cmpFunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

char **findRelativeRanks(int *score, int scoreSize, int *returnSize)
{
    int *tmp = (int *)malloc(sizeof(int) * scoreSize);
    char **ans = (char **)malloc(sizeof(char *));

    memcpy(tmp, score, scoreSize * sizeof(int));
    qsort(tmp, scoreSize, sizeof(int), cmpFunc);
    *returnSize = 0;

    for (int i = scoreSize - 1; i >= 0; i--)
    {
        for (int j = 0; j < scoreSize; j++)
        {
            if (tmp[i] == score[j])
            {
                if (i == scoreSize - 1)
                {
                    sprintf(ans[j], "%s", "Gold Medal");
                }
                else if (i == scoreSize - 2)
                {
                    sprintf(ans[j], "%s", "Silver Medal");
                }
                else if (i == scoreSize - 3)
                {
                    sprintf(ans[j], "%s", "Bronze Medal");
                }
                else
                {
                    sprintf(ans[j], "%s", tmp[i]);
                }
            }
            (*returnSize)++;
        }
    }
    return ans;
}