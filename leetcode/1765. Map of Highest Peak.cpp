// 1765. 地图中的最高点
// https://leetcode-cn.com/problems/map-of-the-highest-peak/
// Difficulty: Easy
// Topic: Array

#include <vector>
#include <queue>
using namespace std;

// dp：错误的
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
class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int col = isWater[0].size();
        int row = isWater.size();
        queue<pair<int, int>> q;

        vector<vector<int>> res(row, vector<int>(col, -1));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (isWater[i][j] == 1)
                {
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x - 1 >= 0 && res[x - 1][y] == -1)
            {
                res[x - 1][y] = res[x][y] + 1;
                q.push({x - 1, y});
            }
            if (x + 1 < row && res[x + 1][y] == -1)
            {
                res[x + 1][y] = res[x][y] + 1;
                q.push({x + 1, y});
            }
            if (y - 1 >= 0 && res[x][y - 1] == -1)
            {
                res[x][y - 1] = res[x][y] + 1;
                q.push({x, y - 1});
            }
            if (y + 1 < col && res[x][y + 1] == -1)
            {
                res[x][y + 1] = res[x][y] + 1;
                q.push({x, y + 1});
            }
        }
        return res;
    }
};