// 300. 最长递增子序列
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
//动态规划法
int lengthOfLIS(int *nums, int numsSize)
{
    int dp[11000];
    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 11000; i++)
    {
        if (dp[i] > max)
            max = dp[i];
    }
    return max;
};
// 二刷
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
//贪心+二分
