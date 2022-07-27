// 279. 完全平方数
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        vector<int> nums(n + 1, 0);
        for (int i = 1; i * i <= n; i++)
        {
            nums[i] = i * i;
        }
        for (int i = 1; i <= n; i++)
        {
            int min_need = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i - nums[j]] + 1, min_need);
                min_need = min(dp[i], min_need);
            }
        }
        return dp[n];
    }
};