// 1351. 统计有序矩阵中的负数
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//从左下角遍历
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for (int i = n - 1, j = 0; i >= 0; i--)
        {
            for (; j < m; j++)
            {
                if (grid[i][j] < 0)
                    break;
            }
            count += m - j;
        }
        return count;
    }
};