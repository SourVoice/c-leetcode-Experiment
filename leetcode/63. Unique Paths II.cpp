// 63. 不同路径 II
#include <vector>
using namespace std;


//动态规划
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int row = 1; row < m; row++)
        {
            if (dp[row -1][0] != 0 && obstacleGrid[row][0] != 1)//保证了第一列遇到障碍物后面的也不能走
                dp[row][0] = 1;
        }
        for (int col = 1; col < n; col++)
        {
            if (dp[0][col - 1] != 0 && obstacleGrid[0][col] != 1)
                dp[0][col] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};