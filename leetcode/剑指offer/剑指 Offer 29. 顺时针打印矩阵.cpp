#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <sstream>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        vector<int> ans;
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        while (1)
        {
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            if (++top > bottom)
                break;
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            if (--right < left)
                break;
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            if (--bottom < top)
                break;
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            if (++left > right)
                break;
        }
        return ans;
    }
};