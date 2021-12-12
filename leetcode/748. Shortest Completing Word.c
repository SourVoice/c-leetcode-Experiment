/*748.最短补全词*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define isLetter(x) (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
char change2lowercase(char c) //转小写
{
    if (c >= 'A' && c <= 'Z')
    {
        c = c + 32;
    }
    return c;
}
char *shortestCompletingWord(char *licensePlate, char **words, int wordsSize)
{
    int pool[26] = {0};
    for (int i = 0; i < strlen(licensePlate); i++)
    {
        if (isLetter(licensePlate[i]))
        {
            licensePlate[i] = change2lowercase(licensePlate[i]);
            pool[licensePlate[i] - 'a']++;
        }
    }
    int ans = 0;
    int lenMin = INT_MAX;
    int length = 0;
    int poolWord[26] = {0};
    int match = 1;
    for (int i = 0; i < wordsSize; i++)
    {
        length = strlen(words[i]);
        for (int j = 0; j < strlen(words[i]); j++)
        {
            poolWord[words[i][j] - 'a']++;
        }
        for (int k = 0; k < 26; k++)
        {
            if (poolWord[k] < pool[k])
            {
                match = 0;
                break;
            }
        }
        if (!match)
        {
            match = 1;
        }
        else
        {
            if (lenMin > length)
            {
                lenMin = length;
                ans = i;
            }
        }
        memset(poolWord, 0, sizeof(int) * 26);
    }
    return words[ans];
}
