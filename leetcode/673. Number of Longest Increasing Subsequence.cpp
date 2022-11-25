// 673. 最长递增子序列的个数
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
// 动态规划
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);  // 组合长度
        vector<int> cnt(n, 1); // 最长组合数, 以nums[i]结尾的
        int maxLen = 0;        // 记录最长的子序列长度
        if (n == 1)
            return 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i]) // 最长子序列长度更新
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i]) // 相同长度子序列
                    {
                        cnt[i] += cnt[j];
                    }
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        int ans = 0;
        // 累计个数
        for (int i = 0; i < n; i++)
        {
            if (maxLen == dp[i])
                ans += cnt[i];
        }
        return ans;
    }
};
// TODO: 贪心 + 前缀和 + 二分查找