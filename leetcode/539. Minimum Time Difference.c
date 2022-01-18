#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
//排序,最小的一定是相邻两个找最小或者最后一个与第一个
int toMinute(char *s)
{
    int hour = atoi(s);
    while (*s != ':')
    {
        s++;
    }
    int minute = atoi(s + 1);
    return hour * 60 + minute;
}
int cmpFunc(const void *a, const *b)
{
    return *(int *)a - *(int *)b;
}
int findMinDifference(char **timePoints, int timePointsSize)
{
    int *minuteArr = (int *)malloc(sizeof(int) * timePointsSize);
    for (int i = 0; i < timePointsSize; i++)
        minuteArr[i] = toMinute(timePoints[i]);
    qsort(minuteArr, timePointsSize, sizeof(int), cmpFunc);
    int min = INT_MAX;
    for (int i = 1; i < timePointsSize; i++)
    {
        min = fmin(minuteArr[i] - minuteArr[i - 1], min);
    }
    return fmin(fabs(minuteArr[0] + 1440 - minuteArr[timePointsSize - 1]), min);
}
//鸽巢原理
// 一共有 24×60=1440 种不同的时间。由鸽巢原理可知，如果
// \textit{timePoints}timePoints 的长度超过 14401440，那么必然会有两个相同的时间，
//此时可以直接返回 00。

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int getMinutes(const char *t)
{
    return ((t[0] - '0') * 10 + (t[1] - '0')) * 60 + (t[3] - '0') * 10 + (t[4] - '0');
}

int cmp(const void *pa, const void *pb)
{
    return strcmp(*(char **)pa, *(char **)pb);
}

int findMinDifference(char **timePoints, int timePointsSize)
{
    if (timePointsSize > 1440)
    {
        return 0;
    }
    qsort(timePoints, timePointsSize, sizeof(char *), cmp);
    int ans = 1440;
    int t0Minutes = getMinutes(timePoints[0]);
    int preMinutes = t0Minutes;
    for (int i = 1; i < timePointsSize; ++i)
    {
        int minutes = getMinutes(timePoints[i]);
        ans = MIN(ans, minutes - preMinutes); // 相邻时间的时间差
        preMinutes = minutes;
    }
    ans = MIN(ans, t0Minutes + 1440 - preMinutes); // 首尾时间的时间差
    return ans;
}
