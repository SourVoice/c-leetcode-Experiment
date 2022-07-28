// 343. 整数拆分
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0); //代表i的最大拆分乘积
        dp[0] = 1, dp[1] = 1, dp[2] = 1;
        int max_ = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(max(dp[i], dp[i - j] * j), (i - j) * j); //选取拆分后最大的乘积记为新的dp[i]
            }
        }
        return dp[n];
    }
};