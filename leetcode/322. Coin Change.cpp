// 322. 零钱兑换
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<long> dp(amount + 1, INT_MAX); // dp[i]表示amount为i时的最小硬币数
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= coins[j])
                    dp[i] = min(dp[i], min(dp[i] + 1, dp[i - coins[j]] + 1));
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// dfs;深度优先搜索;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        count.resize(amount + 1);
        return dfs(coins, amount);
    }
    int dfs(vector<int> &coins, int rem)
    {
        if (rem < 0)
            return -1;
        if (rem == 0)
            return 0;
        if (count[rem - 1] != 0)
            return count[rem - 1]; //退出条件
        int min_count = INT_MAX;
        for (auto coin : coins)
        {
            int ret = dfs(coins, rem - coin);
            if (ret >= 0 && ret < min_count)
            {
                min_count = ret + 1;
            }
        }
        count[rem - 1] = min_count == INT_MAX ? -1 : min_count;
        return count[rem - 1];
    }

private:
    vector<int> count;
};