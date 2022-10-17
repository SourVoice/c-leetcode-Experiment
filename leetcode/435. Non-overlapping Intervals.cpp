// 435. ���ص�����
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// ̰��
// ����
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
// ��������
// ̰���㷨�������������ѡ���β��̵ģ�����ſ������Ӹ�������䣨��������������ص���Ӧ�ñ�����βС�ģ�
// ������ת��Ϊ����ܱ������ٸ����䣬ʹ���ǻ����ظ��������յ�����
// ÿ������Ľ�β����Ҫ����βԽС�������Խ�п������ɸ�������䡣
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals));
        int ans = 0;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < right)
            {
                ans++;
                if (intervals[i][1] < right)
                    right = intervals[i][1];
            }
            else
                right = intervals[i][1];
        }
        return ans;
    }
};
// ��̬�滮(��ʱ)
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals));
        int n = intervals.size();
        vector<int> dp(n, 1); // ��i��β�����һ������, �ܹ�ѡ�����������������
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[j][1] <= intervals[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return n - *max_element(dp.begin(), dp.end());
    }
};
