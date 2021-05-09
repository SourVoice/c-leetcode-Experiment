#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char *s)
{
    char *p1 = s;
    char *p2 = s;
    char ch_ASSIC[256] = {0}; //用于记录每个重复字符，出现重复则将其重置为全零
    int counter = 0;          //字符长度
    do
    {
        counter = p2 - p1 >= counter ? (p2 - p1) : counter;
        if (ch_ASSIC[*p2] == 1) //p1++
        {
            while (p2 != p1)
                ch_ASSIC[*--p2] = '\0'; //重置字符池
            p1++;
            p2 = p1;
        }
        if (*p2 == '\0') //外循环结束条件
            break;
        ch_ASSIC[*p2] = 1;
        p2++;

    } while (1);
    return counter;
}
int main()
{
    char *str = "au";
    printf("%d\n", lengthOfLongestSubstring(str));
    return 0;
}