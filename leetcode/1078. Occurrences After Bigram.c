// 1078. Bigram ·Ö´Ê
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
    int wordl[10001];
    int num = 0;
    int l = 0;
    for (int i = 0; i < textLen; i++)
    {
        l++;
        if (text[i] == ' ' || text[i] == '\0')
        {
            wordl[num++] = l - 1;
            l = 0;
        }
    }
    printf("\n");

    num = 0;
    while (textIndex <= textLen - prefixLen)
    {
        int tmp = textIndex;
        int find = 1;
        for (int i = 0, textIndex = tmp; i < prefixLen; i++, textIndex++)
        {
            if (text[textIndex] != prefix[i])
            {
                find = 0;
                break;
            }
        }
        if (find)
        {
            printf("%d ", textIndex + prefixLen);
            find = 0;
            index[(*returnSize)++] = textIndex + prefixLen + 1;
        }
        textIndex = tmp + wordl[num++] + 1;
        if (textIndex >= textLen - prefixLen)
            break;
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

int main()
{

    // char *text = "alice is a good girl she is a good student";
    // char *first = "a";
    // char *second = "good";

    char *text = "ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv ypkk";
    char *first = "lnlqhmaohv";
    char *second = "ypkk";

    int *returnSize = malloc(sizeof(int));
    *returnSize = 0;

    char **a;

    a = findOcurrences(text, first, second, returnSize);
    for (int i = 0; i < *returnSize; i++)
    {
        printf("\n%s", a[i]);
    }
    return 0;
}
/*
"ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv ypkk"
"lnlqhmaohv"
"ypkk"
*/