// 119. Pascal's Triangle II
#include <vector>
using namespace std;

// dp;¶¯Ì¬¹æ»®
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1, 0));
        vector<int> row;
        for (int i = 0; i <= rowIndex; i++)
        {
            row.clear();
            for (int j = 0; j <= i; j++)
            {
                if (i == j || j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                row.push_back(dp[i][j]);
            }
        }
        return row;
    }
};