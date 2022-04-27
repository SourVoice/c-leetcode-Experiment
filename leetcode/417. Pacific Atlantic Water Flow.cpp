// 417. 太平洋大西洋水流问题
#include <vector>
#include <functional>
using namespace std;

// error
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<pair<int, int>>> record;
        visited = vector<vector<bool>>(heights.size(), vector<bool>(heights[0].size(), false));

        function<void(vector<vector<int>>, int, int)> dfs = [&](vector<vector<int>> heights, int i, int j)
        {
            if (i <= 0 || i >= heights.size() - 1 || j <= 0 || j >= heights[0].size() - 1)
            {
                if (i < 0 || j < 0)
                {
                    record[i][j].first++;
                }
                if (i >= heights.size() - 1 || j >= heights[0].size() - 1)
                {
                    record[i][j].second++;
                }
                return;
            }
            for (auto dir : dirs)
            {
                int x = i + dir[0];
                int y = j + dir[1];
                if (heights[x][y] < heights[i][j])
                {
                    if (x > 0 && y > 0 && x < heights.size() - 1 && y < heights[0].size() - 1)
                    {
                        dfs(heights, x, y);
                    }
                }
            }
        };
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {
                dfs(heights, i, j);
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {
                if (record[i][j].first >= 1 && record[i][j].second >= 1)
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited;
};

//反向搜索
class Solution
{
public:
    void dfs(vector<vector<int>> heights, int i, int j, vector<vector<bool>> &ocean)
    {
        if (ocean[i][j])
            return;
        ocean[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j])
            {
                dfs(heights, x, y, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        this->m = heights.size();
        this->n = heights[0].size();
        // function<void(vector<vector<int>>, int, int, vector<vector<bool>> &)>         // from pacific to atlantic
        vector<vector<bool>> pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs(heights, i, 0, pacific);
        }
        for (int j = 1; j < n; j++)
        {
            dfs(heights, 0, j, pacific);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(heights, i, n - 1, atlantic);
        }
        for (int j = 0; j < n - 1; j++)
        {
            dfs(heights, m - 1, j, atlantic);
        }

        // compute the answer
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
};