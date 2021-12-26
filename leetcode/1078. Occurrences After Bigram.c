// 1078. Bigram ·Ö´Ê
#include <string.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findOcurrences(char *text, char *first, char *second, int *returnSize)
{
    char *prefix = (char *)malloc(sizeof(char) * (strlen(first) + strlen(second) + 2));
    strcpy(prefix, first);
    strcat(prefix, " ");
    strcat(prefix, second);

    int prefixLen = strlen(prefix);
    int textLen = strlen(text);
    int secondLen = strlen(second);
    int textIndex = 0;
    int index[10001];
    *returnSize = 0;
    while (1)
    {
        int find = 1;
        int size = 0;
        for (int i = 0; i < prefixLen; i++, textIndex++)
        {

            if (text[textIndex] != prefix[i])
            {
                find = 0;
                break;
            }
            size++;
        }
        if (find)
        {
            find = 0;
            index[(*returnSize)++] = textIndex + 1;
            textIndex = textIndex - prefixLen;
        }
        if (size == strlen(first) + 1)
            continue;
        while (text[textIndex] != ' ' && textIndex < textLen)
            textIndex++;
        textIndex++;
        if (textIndex == textLen)
            break;
        if (text[textIndex] == ' ')
            textIndex++;
    }

    char **ans = (char **)malloc(sizeof(char *) * (*returnSize));
    for (int i = 0; i < *returnSize; i++)
    {
        int size = 0;
        int tmp = index[i];
        while (text[tmp] != ' ' && text[tmp] != '\0')
        {
            size++;
            tmp++;
        }
        ans[i] = calloc(size + 1, sizeof(char)); // calloc can initial memory to 0,if use malloc, must set the last one to '\0'
        ans[i] = strncpy(ans[i], text + index[i], size);
    }
    return ans;
}