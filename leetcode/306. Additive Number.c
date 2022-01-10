// 306. ÀÛ¼ÓÊý
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isAdditiveNumber(char *num)
{
    int len = strlen(num);
    for (int second1 = 1; second1 < len - 1; second1++)
    {
        if (num[0] == '0' && second1 != 1)
            break;
        for (int second2 = second1; second2 < len - 1; second2++)
        {
            if (num[second1] == '0' && second1 != second2) // if begin is '0' but more than one number
                break;
            if (valid(second1, second2, num))
                return true;
        }
    }
    return false;
}

bool valid(int secondStart, int secondEnd, char *num)
{
    int len = strlen(num);
    int firstStart = 0;
    int firstEnd = secondStart - 1;
    while (secondEnd <= len - 1)
    {
        char *third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
        int thirdStart = secondEnd + 1;
        int thirdEnd = secondEnd + strlen(third);
        if (thirdEnd >= len || !(strstr(thirdStart, thirdEnd - thirdStart + 1) == third)) // find the third
            break;

        if (thirdEnd == len - 1)
            return true;
        firstStart = secondStart;
        firstEnd = secondEnd;
        secondStart = thirdStart;
        secondEnd = thirdEnd;
    }
    return false;
}
char *stringAdd(char *s, int firstStart, int firstEnd, int secondStart, int secondEnd)
{
    char *third = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    int thirdSize = 0;
    int carry = 0;
    int cur = 0;
    while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0)
    {
        cur = carry;
        if (firstEnd >= firstStart)
        {
            cur += s[firstEnd] - '0';
            --firstEnd;
        }
        if (secondEnd >= secondStart)
        {
            cur += s[secondEnd] - '0';
            --secondEnd;
        }
        carry = cur / 10;
        cur %= 10;
        third[thirdSize++] = cur + '0';
    }
    third[thirdSize] = '\0';
    strrev(third);
    return third;
}