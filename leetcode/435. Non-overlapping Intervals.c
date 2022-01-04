// 435. ���ص�����
//̰��
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
        if (intervals[i][0] >= right) //��������½������һ�����Ͻ�
        {
            ans++;                   //�����䱻ѡ����
            right = intervals[i][1]; //�ٴ��ӹ�ģ����ѡ�������Ͻ�
        }
    }
    return intervalsSize - ans;
}