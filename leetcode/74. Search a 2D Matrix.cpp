// 74. ������ά����
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// ���ֲ���
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
// �ȶ��ж���,������������
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [&](const int &val, const vector<int> &mat)
                               { return val < mat[0]; });
        if (row == matrix.begin())
            return false;
        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};