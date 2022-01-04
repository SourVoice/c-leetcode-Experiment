// 435. 无重叠区间
//贪心
#include <stdlib.h>
int cmpFunc(const void **a, const void **b)
{
    return (*(int **)a)[1] - (*(int **)b)[1];
}
int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    if (!intervalsSize)
        return 0;
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmpFunc);
    int right = intervals[0][1];
    int ans = 1;
    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] >= right) //左侧区间下界大于上一区间上界
        {
            ans++;                   //该区间被选择保留
            right = intervals[i][1]; //再从子规模问题选择区间上界
        }
    }
    return intervalsSize - ans;
}