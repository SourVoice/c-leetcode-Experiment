// 452. 用最少数量的箭引爆气球
//贪心
int cmpFunc(const void **a, const void **b)
{
    return (*(int **)a)[1] < (*(int **)b)[1] ? -1 : 1;
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize)
{
    if (!pointsSize)
        return 0;
    qsort(points, pointsSize, sizeof(points[0]), cmpFunc);
    int ans = 1;
    int right = points[0][1];
    for (int i = 0; i < pointsSize; i++)
    {
        if (points[i][0] > right)
        {
            ans++;
            right = points[i][1];
        }
    }
    return ans;
}