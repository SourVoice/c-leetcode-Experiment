// 1901. 寻找峰值 II
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 二分查找
// reference: 162. 寻找峰值
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int col = std::distance(begin(mat[mid]), max_element(begin(mat[mid]), end(mat[mid])));
            if (mid > 0 && mat[mid - 1][col] > mat[mid][col])
                high = mid - 1;
            else if (mid + 1 < m && mat[mid + 1][col] > mat[mid][col])
                low = mid + 1;
            else
                return vector<int>{mid, col};
        }
        return vector<int>{-1, -1};
    }
};