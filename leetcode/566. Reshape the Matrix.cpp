// 566. 重塑矩阵
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size(), n = mat[0].size();
        if (r * c != m * n)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < m * n; i++) // 利用列数填充矩阵
            ans[i / c][i % c] = mat[i / n][i % n];
        return ans;
    }
};