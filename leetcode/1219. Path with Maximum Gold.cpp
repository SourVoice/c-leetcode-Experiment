// 1219. 黄金矿工
#include <vector>
#include <functional>
using namespace std;

//回溯问题模板
class Solution
{
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int max_gold = 0;

    void helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, int ans)
    {
        ans += grid[i][j];
        max_gold = max(max_gold, ans);

        for (auto &d : dir)
        {
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] > 0)
            {
                if (!visited[x][y])
                {
                    visited[x][y] = true;
                    helper(x, y, grid, visited, ans);
                    visited[x][y] = false;
                }
            }
        }
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] > 0)
                {
                    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
                    visited[i][j] = true;
                    helper(i, j, grid, visited, 0);
                    visited[i][j] = false;
                }
            }
        }
        return max_gold;
    }
};

//回溯lambda写法
class Solution2
{
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int x, int y, int gold)
        {
            gold += grid[x][y];
            ans = max(ans, gold);
            int rec = grid[x][y];
            grid[x][y] = 0;

            for (auto &dir : dirs)
            {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0)
                {
                    dfs(nx, ny, gold);
                }
            }
            grid[x][y] = rec;
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(i, j, 0);
            }
        }

        return ans;
    }
};