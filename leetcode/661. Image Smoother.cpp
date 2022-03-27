// 661. Í¼Æ¬Æ½»¬Æ÷

#include <vector>
using namespace std;

// dfs Ä£Äâ
class Solution
{
private:
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int m;
    int n;

public:
    int dfs(vector<vector<int>> &image, int i, int j, int m, int n)
    {
        int temp = image[i][j];
        int count = 1;
        for (auto dir : dirs)
        {
            if (i + dir[0] >= 0 && i + dir[0] < m && j + dir[1] >= 0 && j + dir[1] < n)
            {
                temp += image[i + dir[0]][j + dir[1]];
                count++;
            }
        }
        return temp / count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        m = img.size();
        n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = dfs(img, i, j, m, n);
            }
        }
        return ans;
    }
};