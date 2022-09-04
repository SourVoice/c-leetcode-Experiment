// 1582. 二进制矩阵中的特殊位
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> rec;
        for (int i = 0; i < m; ++i)
        {
            if (accumulate(mat[i].begin(), mat[i].end(), 0) == 1)
            {
                rec.push_back(make_pair(i, find(mat[i].begin(), mat[i].end(), 1) - mat[i].begin()));
            }
        }
        for (auto &pair : rec)
        {
            int sum_col = 0, j = pair.second;
            for (int i = 0; i < m; ++i)
            {
                sum_col += mat[i][j];
            }
            if (sum_col == 1)
                ans += 1;
        }
        return ans;
    }
};