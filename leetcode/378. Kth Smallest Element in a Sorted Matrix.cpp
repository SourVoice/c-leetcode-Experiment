// 378. 有序矩阵中第 K 小的元素
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
// 暴力
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        vector<int> vec;
        for (auto &raw : matrix)
        {
            for (auto &e : raw)
                vec.push_back(e);
        }
        sort(begin(vec), end(vec));
        return vec[k - 1];
    }
};
// 二分查找
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        auto count = [&](const int &guess) -> int
        {
            int cnt = 0;
            int j = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                while (j < n && matrix[i][j] <= guess)
                    j++, cnt += i + 1;
            }
            return cnt;
        };
        while (l < r)
        {
            cout << l << " " << r << endl;
            int mid = (l + r) / 2;
            if (mid < 0)
                mid -= 1;
            int cnt = count(mid);
            cout << cnt << endl;
            if (cnt < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};