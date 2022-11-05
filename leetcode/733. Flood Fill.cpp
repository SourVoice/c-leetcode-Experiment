// 733. ÕºœÒ‰÷»æ
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// dfs
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int color_core = image[sr][sc];
        if (color_core == color)
            return image;
        dfs(image, sr, sc, color_core, color);
        return image;
    }
    void dfs(vector<vector<int>> &image, int x, int y, int color, int newcolor)
    {
        if (image[x][y] == color)
        {
            image[x][y] = newcolor;
            for (auto &dir : dirs)
            {
                int newx = x + dir[0], newy = y + dir[1];
                if (newx >= 0 && newx < image.size() && newy >= 0 && newy < image[0].size())
                    dfs(image, newx, newy, color, newcolor);
            }
        }
    }

private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited;
};