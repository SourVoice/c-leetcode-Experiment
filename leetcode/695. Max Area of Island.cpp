// 695. 岛屿的最大面积
#include <string>
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
// 深度优先搜索;dfs
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    int square = 1;
                    visited[i][j] = 1;
                    dfs(grid, visited, i, j, square);
                    ret = max(ret, square);
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y, int &square)
    {
        for (auto &dir : dirs)
        {
            int n_x = x + dir[0], n_y = y + dir[1];
            if (n_x >= 0 && n_x < grid.size() && n_y >= 0 && n_y < grid[0].size())
            {
                if (grid[n_x][n_y] == 1 && !visited[n_x][n_y])
                {
                    visited[n_x][n_y] = 1;
                    square++;
                    dfs(grid, visited, n_x, n_y, square);
                }
            }
        }
    }

private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};