// 79. µ¥´ÊËÑË÷
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        if (word.size() > m * n)
            return false;
        if (m == 1 && n == 1)
            return board[0][0] == word[0];
        this->m = m, this->n = n;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(board, visited, word, i, j, 0);
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, string &word, int x, int y, int pos)
    {
        if (pos == word.size())
        {
            ans = true;
            return;
        }
        for (auto &dir : dirs)
        {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (!visited[nx][ny] && word[pos] == board[nx][ny])
                {
                    visited[nx][ny] = 1;
                    dfs(board, visited, word, nx, ny, pos + 1);
                    visited[nx][ny] = 0;
                }
            }
        }
    }

private:
    int m, n;
    bool ans = false;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};