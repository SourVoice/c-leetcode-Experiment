// √Ê ‘Ã‚ 01.08. ¡„æÿ’Û
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> rec;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                    rec.push_back({i, j});
            }
        }
        for (auto &e : rec)
        {
            for (auto &n : matrix[e.first])
                n = 0;
            for (auto &row : matrix)
                row[e.second] = 0;
        }
    }
};