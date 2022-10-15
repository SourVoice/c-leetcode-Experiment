// 59. ÂÝÐý¾ØÕó II
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
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        int top = 0;
        int left = 0;
        int right = n;
        int down = n;

        vector<vector<int>> ans(n, vector<int>(n));
        int limit = n * n;
        int i = 1;
        for (; i <= limit;)
        {
            for (int j = left; j < right && i <= limit; j++)
                ans[top][j] = i++;
            top++;

            if (i > limit)
                break;
            for (int j = top; j < down && i <= limit; j++)
                ans[j][right - 1] = i++;
            right--;

            if (i > limit)
                break;
            for (int j = right - 1; j >= left && i <= limit; j--)
                ans[down - 1][j] = i++;
            down--;

            if (i > limit)
                break;
            for (int j = down - 1; j >= top && i <= limit; j--)
                ans[j][left] = i++;
            left++;
        }
        return ans;
    }
};