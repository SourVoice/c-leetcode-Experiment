// 314场周赛
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 余数应用;动态规划
class Solution
{
public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int mod = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0))); // i, j处路径和余k的路径数目, 我们只关注路径和与k的余数
        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int v = 0; v < k; v++)
                {
                    if (i == 0 && j != 0)
                        dp[i][j][(v + grid[i][j] % k) % k] += (dp[i][j - 1][v]) % mod;
                    else if (j == 0 && i != 0)
                        dp[i][j][(v + grid[i][j] % k) % k] += (dp[i - 1][j][v]) % mod;
                    else if (j != 0 && i != 0)
                        dp[i][j][(v + grid[i][j] % k) % k] += (dp[i - 1][j][v] + dp[i][j - 1][v]) % mod;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};
