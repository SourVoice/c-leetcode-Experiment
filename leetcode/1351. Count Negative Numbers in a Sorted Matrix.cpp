// 1351. ͳ����������еĸ���
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//�����½Ǳ���
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