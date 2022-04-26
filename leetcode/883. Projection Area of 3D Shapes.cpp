// 883. 三维形体投影面积
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int top_down_view = 0;
        int front_back_view = 0;
        int left_right_view = 0;
        for (auto &row : grid)
        {
            for (auto e : row)
            {
                top_down_view += e > 0 ? 1 : 0;
            }

            front_back_view += *max_element(row.begin(), row.end());
        }
        for (int j = 0; j < n; j++)
        {
            int max_x = 0;
            for (int i = 0; i < m; i++)
            {
                max_x = max(max_x, grid[i][j]);
            }
            left_right_view += max_x;
        }
        cout << top_down_view << " " << front_back_view << " " << left_right_view << endl;
        return top_down_view + front_back_view + left_right_view;
    }
};