#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *longestCommonPrefix(char **strs, int strsSize)
{
    char *publicStr = (char *)malloc(sizeof(char) * 200);

    switch (strsSize)
    {
    case 0:
        publicStr[0] = '\0';
        return publicStr;
    case 1:
        strcpy(publicStr, strs[0]);
        return publicStr;
    }
    strcpy(publicStr, strs[0]);
    for (int i = 1; i < strsSize; i++)
    {
        char *str = strs[i];
        for (int j = 0; str[j] != '\0' && publicStr[j] != '\0'; j++)
        {
            if (str[j] != publicStr[j])
            {
                publicStr[j] = '\0';
                break;
            }
        }
        if (publicStr[0] == '\0')
            break;
    }
}
int main()
{

    char **string = (char **)malloc(sizeof(char *) * 2);
    for (int i = 0; i < 2; i++)
    {
        string[i] = (char *)malloc(sizeof(char) * 1);
    }
    string[0] = NULL;
    string[1] = NULL;
    char *publicstr = longestCommonPrefix(string, 2);
    for (int i = 0; publicstr[i] != '\0'; i++)
    {
        printf("%c", publicstr[i]);
    }
    return 0;
}