// 746. 使用最小花费爬楼梯
#include <vector>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 2, 0);
        dp[0] = 0, dp[1] = 0;
        for (int i = 2; i <= n + 1; i++)
        {
            dp[i] = cost[i - 2] + fmin(dp[i - 1], dp[i - 2]);
        }
        return fmin(dp[n], dp[n + 1]);
    }
};

class Soluton2
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
    }
};