// 377. 组合总和 Ⅳ
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//动态规划;类似于爬楼梯
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= nums[j])
                {
                    if (dp[i] <= INT_MAX - dp[i - nums[j]])
                        dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};