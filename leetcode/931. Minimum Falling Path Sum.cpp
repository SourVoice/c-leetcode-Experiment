// 931. �½�·����С��
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//��̬�滮,��
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0)); // ����ӵ�һ�е���i�е���С��
        dp[0] = matrix[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                }
                else if (j == m - 1)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
                }
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};