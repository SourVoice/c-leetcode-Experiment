#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
//����,��С��һ����������������С�������һ�����һ��
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