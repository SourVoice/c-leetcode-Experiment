// 48. 旋转图像
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
// 上下翻转在对角反转
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
                swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};