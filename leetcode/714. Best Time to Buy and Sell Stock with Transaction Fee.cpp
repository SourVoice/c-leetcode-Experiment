// 714. 买卖股票的最佳时机含手续费
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        /*
        dp[i][0]表示第i天不持有股票所得最多现金
        dp[i][1]表示第i天持有股票最多现金,
        */
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee); //前一天持有股票, 则卖出
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);       //前一天不持有,则购买
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};