// 1020. 飞地的数量
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
private:
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col])
            return;
        visited[row][col] = true;
        for (auto &dir : dirs)
        {
            dfs(grid, visited, row + dir[0], col + dir[1]);
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
        // begin from edge and mark all the connected land as visited
        for (int i = 0; i < grid.size(); i++)
        {
            dfs(grid, visited, i, 0);
            dfs(grid, visited, i, grid[0].size() - 1);
        }
        for (int j = 0; j < grid[0].size(); j++)
        {
            dfs(grid, visited, 0, j);
            dfs(grid, visited, grid.size() - 1, j);
        }

        // count the number of land
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == false)
                    ans++;
            }
        }
        return ans;
    }
};