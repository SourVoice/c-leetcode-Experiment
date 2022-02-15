// 1380. 矩阵中的幸运数
#include <vector>
#include <limits>
#include <limits.h>
#include <algorithm>
#include <tuple>
#include <iostream>

using namespace std;

//模拟
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        vector<tuple<int, int, int>> min_index;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            int col = 0;
            int row = 0;
            int min = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < min)
                {
                    min = matrix[i][j];
                    row = i;
                    col = j;
                }
            }
            min_index.push_back(make_tuple(row, col, min));
        }

        for (auto &elem : min_index)
        {
            std::apply([](auto &&...args)
                       { ((), ...); },
                       elem);
        }
        return ans;
    }
};

class Solution2
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> max_col(n, 0);
        vector<int> min_row(m, INT_MAX);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                min_row[i] = min(min_row[i], matrix[i][j]);
                max_col[j] = max(max_col[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (min_row[i] == max_col[j])
                {
                    ans.push_back(min_row[i]);
                }
            }
        }
        return ans;
    }
};

//数学:仅存在一个
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        vector<int> row_min;
        for (auto &row : matrix)
        {
            row_min.push_back(*min_element(row.begin(), row.end()));
        }
        ans.push_back(*max_element(row_min.begin(), row_min.end()));
        if ()
            return ans;
    }
};