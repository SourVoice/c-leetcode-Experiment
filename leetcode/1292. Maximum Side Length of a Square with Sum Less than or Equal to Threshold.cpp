// 1292. 元素和小于等于阈值的正方形的最大边长
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
// 前缀和
class Solution
{
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int m = mat.size(), n = mat[0].size();
        // 计算在以i,j为左下角的矩阵区域内的和
        vector<vector<int>> sumij(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                sumij[i][j] = mat[i - 1][j - 1] + sumij[i][j - 1] + sumij[i - 1][j] - sumij[i - 1][j - 1];
        int winSize = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                for (int k = winSize + 1; k <= i && k <= j; k++)
                {
                    int squareSum = sumij[i][j] - sumij[i - k][j] - sumij[i][j - k] + sumij[i - k][j - k];
                    if (squareSum <= threshold)
                        winSize = k;
                }
        return winSize;
    }
};
// TODO: 动态规划