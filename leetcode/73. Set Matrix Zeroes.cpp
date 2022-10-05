// 73. æÿ’Û÷√¡„
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
// ≥£¡øø’º‰
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool headRowNeedSet = false, headColNeedSet = false;
        for (int i = 0, j = 0; j < n || i < m; j++, i++)
        {
            if (j < n && !matrix[0][j])
                headRowNeedSet = true;
            if (i < m && !matrix[i][0])
                headColNeedSet = true;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                    matrix[i][0] = 0, matrix[0][j] = 0;
            }
        }

        // ÷√¡„≤Ÿ◊˜, ∑«◊Û≤‡…œ≤‡
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
        // …œ≤‡∫Õ◊Û≤‡÷√¡„
        if (headRowNeedSet)
        {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        if (headColNeedSet)
        {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};
