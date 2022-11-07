// 994. 腐烂的橘子
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
// 广度优先搜索;bfs
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int cntFresh = 0; // 新鲜橘子
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    cntFresh++;
            }
        }
        int cycle = 0;
        while (!q.empty() && cntFresh > 0)
        {
            cycle++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto &&[x, y] = q.front();
                for (auto &dir : dirs)
                {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    {
                        cntFresh--;
                        grid[nx][ny] = 2;
                        q.push(make_pair(nx, ny));
                    }
                }
                q.pop();
            }
        }
        return cntFresh ? -1 : cycle;
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};