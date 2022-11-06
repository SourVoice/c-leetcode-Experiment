// 542. 01 矩阵
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
// 错误
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    int cnt = 0;
                    minv = INT_MAX;
                    dfs(mat, visited, i, j, cnt);
                    ret[i][j] = minv;
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>> &mat, vector<vector<int>> &visited, int x, int y, int cnt)
    {
        if (mat[x][y] == 0)
        {
            minv = 0;
            return;
        }
        for (auto &dir : dirs)
        {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < mat.size() && ny >= 0 && ny < mat[0].size())
            {
                visited[x][y] = 1;
                minv = min(minv, cnt);
                dfs(mat, visited, nx, ny, cnt++);
            }
        }
        visited[x][y] = 0;
    }

private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minv = INT_MAX;
};
// 广度优先搜索;bfs
// https://leetcode.cn/problems/01-matrix/solutions/202012/01ju-zhen-by-leetcode-solution/
// by https://leetcode.cn/u/java-634/
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        deque<pair<int, int>> dq;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j])
                    mat[i][j] = 1e4;
                else
                    dq.emplace_back(make_pair(i, j));
            }
        }
        int cnt = 0;
        while (!dq.empty())
        {
            cnt++;
            int size = dq.size();
            for (int i = 0; i < size; i++)
            {
                auto &&[x, y] = dq.front();
                for (auto &dir : dirs)
                {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && mat[nx][ny] == 1e4)
                    {
                        mat[nx][ny] = cnt;
                        dq.emplace_back(make_pair(nx, ny));
                    }
                }
                dq.pop_front();
            }
        }
        return mat;
    }

private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};