// 435. 无重叠区间
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
// 贪心
// 倒序
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
// 正序排序
// 贪心算法，按照起点排序：选择结尾最短的，后面才可能连接更多的区间（如果两个区间有重叠，应该保留结尾小的）
// 把问题转化为最多能保留多少个区间，使他们互不重复，则按照终点排序，
// 每个区间的结尾很重要，结尾越小，则后面越有可能容纳更多的区间。
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
// 动态规划(超时)
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals));
        int n = intervals.size();
        vector<int> dp(n, 1); // 以i结尾的最后一个区间, 能够选出的最大数量的区间
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
