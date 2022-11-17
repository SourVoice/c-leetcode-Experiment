// 1091. 二进制矩阵中的最短路径
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
// 广度优先搜索
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1)
            return -1;
        if (n == 1)
            return 1;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        visited[0][0] = 1;
        q.push({0, 0});
        int cycle = 1;
        while (!q.empty())
        {
            cycle++;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++)
            {
                auto &&[x, y] = q.front();
                for (auto &dir : dirs)
                {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                    {
                        if (grid[nx][ny] == 0 && !visited[nx][ny])
                        {
                            q.push({nx, ny});
                            visited[nx][ny] = 1;
                            if (nx == n - 1 && ny == n - 1)
                                return cycle;
                        }
                    }
                }
                q.pop();
            }
        }
        return -1;
    }

private:
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
};