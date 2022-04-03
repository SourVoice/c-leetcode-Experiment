// 1039. 多边形三角剖分的最低得分
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), 0)); // dp代表从i-j序列的最低分
        int n = values.size();
        for (int i = 2; i < n; i++)
        {
            for (int j = i - 2; j >= 0; j--)
            {
                for (int k = j + 1; k < i; k++)
                {
                    if (dp[i][j] == 0)
                    {
                        dp[i][j] = dp[i][k] + values[i] * values[j] * values[k] + dp[k][j];
                    }
                    else
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n - 1][0];
    }
};