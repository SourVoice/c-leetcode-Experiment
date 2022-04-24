// 338. 比特位计数
#include <vector>
using namespace std;

//动态规划,数学
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        vector<int> dp(n + 1, 0);
        if (n == 0)
            return {0};
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i & 1) // odd, if i is odd, it's 1's num is more than its (i >> 1)
            {
                dp[i] = dp[i / 2] + 1;
            }
            else
            {
                dp[i] = dp[i / 2];
            }
        }
        return dp;
    }
};