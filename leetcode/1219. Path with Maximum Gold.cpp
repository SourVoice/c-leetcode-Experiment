// 1219. 黄金矿工
#include <vector>
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