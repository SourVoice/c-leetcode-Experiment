// 62. 不同路径

#include <vector>
using namespace std;

//组合数学
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long ans = 1;

        for (int x = n, y = 1; y < m; y++, x++)
        { //总共m+n-2步,从中任选m-1
            ans = ans * x / y;
        }
        return ans;
    }
};

//动态规划
class Soluiton2
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 1)); //代表从第一行到第m行,第一列到第n列的路径数
        for (int i = 2; i <= m; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//状态转移:到达i,j的路径由上面或者下面,这两个和就是到i,j的路径数
            }
        }
        long ans;
        ans = dp[m][n];
        return ans;
    }
};