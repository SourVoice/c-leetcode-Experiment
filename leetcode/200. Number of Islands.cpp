// 200. µ∫”Ï ˝¡ø
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
using namespace std;
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    visited[i][j] = 1;
                    dfs(grid, visited, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int x, int y)
    {
        for (auto &dir : dirs)
        {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size())
            {
                if (grid[nx][ny] == '1' && !visited[nx][ny])
                {
                    visited[nx][ny] = 1;
                    dfs(grid, visited, nx, ny);
                }
            }
        }
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};