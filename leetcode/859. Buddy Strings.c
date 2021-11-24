#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0

/*859. Ç×ÃÜ×Ö·û´®*/

bool buddyStrings(char *s, char *goal)
{
    if (strlen(s) != strlen(goal))
        return false;

    int i = 0;
    while (s[i] && goal[i])
    {
        if (goal[i] != s[i])
            break;
        i++;
    }
    if (i == strlen(s))
    {
        int count[26];
        for (int i = 0; i < 26; i++)
            count[i] = 0;
        for (int i = 0; i < strlen(s); i++)
        {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] > 1)
            {
                return true;
            }
        }
        for (int i = 0; i < strlen(s); i++)
        {
            if (count[s[i] - 'a'] > 1)
            {
                return true;
            }
        }
        return false;
    }
    int rec[3] = {0, 0, 0};
    int recIndex = 0;
    while (s[i] && goal[i])
    {
        if (s[i] != goal[i])
            rec[recIndex++] = i;
        if (recIndex >= 3)
            return false;
        i++;
    }
    printf("%s\n", s);
    printf("%c %c\n", s[rec[0]], s[rec[1]]);
    if (recIndex)
    {
        char temp = s[rec[0]];
        s[rec[0]] = s[rec[1]];
        s[rec[1]] = temp;
    }
    else if (recIndex == 0 && s[0] != s[1])
    {
        return false;
    }
    printf("%s\n", s);
    i = 0;
    while (s[i] && goal[i])
    {
        if (goal[i] != s[i])
            return false;
        i++;
    }
    return true;
}
/*
"aa"
"aa"

"ab"
"ab"

"ab"
"ba"

"abcaa"
"abcbb"
*/