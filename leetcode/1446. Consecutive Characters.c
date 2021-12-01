/*Á¬Ðø×Ö·û*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxPower(char *s)
{
    int pool[10000] = {0};
    char *strpos = s, *strend = s + strlen(s);
    int len = 0;
    int index = 0;
    while (strpos < strend)
    {
        if (*(strpos + 1) == *strpos)
        {
            len++;
        }
        else
        {
            pool[index++] = len;
            len = 0;
        }
        strpos++;
    }
    int max = 0;
    for (int i = 0; i < index; i++)
    {
        if (pool[i] >= max)
            max = pool[i];
    }
    return max = 1 ? max + 1 : max + 2;
}
int main()
{
    char *s =
        "abbcccddddeeeeedcba";
    printf("%d", maxPower(s));
}