// 71. ¼ò»¯Â·¾¶
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *simplifyPath(char *path)
{
    char *simplify = (char *)malloc(sizeof(char) * 10000);
    simplify[0] = '\0';

    int size = 0;
    int i = 0;
    int left = 0;
    int right = 0;

    int len = strlen(path);

    while (i < len)
    {
        while (i < len && path[i] == '/')
            i++;
        left = i;
        while (i < len && path[i] != '/')
            i++;
        right = i;
        if (right - left == 0)
            continue;
        if (right - left == 1 && path[left] == '.') // format is: "////./"
            continue;
        if (right - left == 2 && path[left] == '.' && path[left + 1] == '.') // format is: "//..//"
        {
            if (size <= 0) // format is: "/../"
                continue;
            while (simplify[size - 1] != '/') // when touch .. then go back one word
                size--;
            size--;
            continue;
        }
        simplify[size++] = '/';
        while (left < right)
            simplify[size++] = path[left++];
    }
    if (size == 0)
        simplify[size++] = '/';
    simplify[size] = '\0';
    return simplify;
}