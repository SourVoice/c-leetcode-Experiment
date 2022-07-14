// 309. 最佳买卖股票时机含冷冻期
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        /*
        i表示该天已经结束
        dp[i][0] 表示最大收益,持有股票
        dp[i][1] 表示不持有股票,处于冷冻期,收益为dp[i][1]
        dp[i][2] 表示不持有股票,不处于冷冻期, 收益为dp[i][2],卖出
        */
        dp[0][0] = -prices[0]; //买入
        dp[0][1] = 0;
        dp[0][2] = 0;
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]); // i-1天已经持有或者非冷冻期买入
            dp[i][1] = dp[i - 1][0] + prices[i];                    //卖出
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);             // 我们在第 ii 天结束之后不持有任何股票并且不处于冷冻期，说明当天没有进行任何操作
            profit = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        }
        return max(dp[n - 1][0], max(dp[n - 1][2], dp[n - 1][1]));
    }
};