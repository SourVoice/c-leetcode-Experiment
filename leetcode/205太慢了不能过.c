#include <stdio.h>
int isIsomorphic(char *s, char *t)
{
    char relfection[256][2] = {0};
    for (int index = 0; *s != '\0'; index++)
    {
        relfection[index][0] = *s;
        relfection[index][1] = *t;
        for (int j = 0; j <= index; j++)
        {
            if (s[j] == relfection[j][0])
            {
                if (t[j] != relfection[j][1])
                    return 0;
                else
                    break;
            }
        }
        s++;
        t++;
    }
    return 1;
}
int main()
{
    char *str1 = "paper";
    char *str2 = "title";
    printf("%d ", isIsomorphic(str1, str2));
}