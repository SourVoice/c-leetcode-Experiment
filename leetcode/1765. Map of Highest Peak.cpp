// 1765. 地图中的最高点
// https://leetcode-cn.com/problems/map-of-the-highest-peak/
// Difficulty: Easy
// Topic: Array

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        vector<vector<int>> res;
        int m = isWater.size();
        if (m == 0)
            return res;
        int n = isWater[0].size();
        if (n == 0)
            return res;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (isWater[i][j] == 0)
                    continue;
                if (isWater[i][j] > isWater[i - 1][j] && isWater[i][j] > isWater[i + 1][j] && isWater[i][j] > isWater[i][j - 1] && isWater[i][j] > isWater[i][j + 1])
                    dp[i][j] = 1;
            }
        }
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (dp[i][j] == 1)
                {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};