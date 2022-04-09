// 118. 杨辉三角
#include <vector>
using namespace std;

// dp;动态规划
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> dp(numRows,vector<int>(numRows,1));
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> arr;
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                arr.push_back(dp[i][j]);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};