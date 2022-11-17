// 130. 被围绕的区域
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
// 深度优先搜索;dfs
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        this->m = m, this->n = n;
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                board[0][i] = '-';
                dfs(board, 0, i, 1);
            }
            if (board[m - 1][i] == 'O')
            {
                board[m - 1][i] = '-';
                dfs(board, m - 1, i, 1);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                board[i][0] = '-';
                dfs(board, i, 0, 1);
            }
            if (board[i][n - 1] == 'O')
            {
                board[i][n - 1] = '-';
                dfs(board, i, n - 1, 1);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                    dfs(board, i, j, 2);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == '-')
            {
                board[0][i] = 'O';
                dfs(board, 0, i, 3);
            }
            if (board[m - 1][i] == '-')
            {
                board[m - 1][i] = 'O';
                dfs(board, m - 1, i, 3);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == '-')
            {
                board[i][0] = 'O';
                dfs(board, i, 0, 3);
            }
            if (board[i][n - 1] == '-')
            {
                board[i][n - 1] = 'O';
                dfs(board, i, n - 1, 3);
            }
        }
    }
    void dfs(vector<vector<char>> &board, int x, int y, int trans)
    {
        for (auto &dir : dirs)
        {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (board[nx][ny] == 'O' && trans == 1)
                {
                    board[nx][ny] = '-';
                    dfs(board, nx, ny, 1);
                }
                else if (board[nx][ny] == 'O' && trans == 2)
                {
                    board[nx][ny] = 'X';
                    dfs(board, nx, ny, 3);
                }
                else if (board[nx][ny] == '-' && trans == 3)
                {
                    board[nx][ny] = 'O';
                    dfs(board, nx, ny, 3);
                }
            }
        }
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
};