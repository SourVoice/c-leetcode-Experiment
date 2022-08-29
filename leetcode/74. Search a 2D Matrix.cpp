// 74. 搜索二维矩阵
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// 二分查找
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int row = m - 1, col = 0;
        for (; row >= 0 && col < n;)
        {
            int num = matrix[row][col];
            if (num < target)
                col++;
            else if (num > target)
                row--;
            else
                return true;
        }
        return false;
    }
};