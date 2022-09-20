// 1712. 将数组分成三个子数组的方案数
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
// 前缀和+二分查找
class Solution
{
public:
    typedef long long ll;
    int waysToSplit(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sum_prefix(n, 0);
        sum_prefix[0] = nums[0];
        ll ans = 0;
        int mod = 1e9 + 7;
        for (int i = 1; i < n; i++)
        {
            sum_prefix[i] = nums[i] + sum_prefix[i - 1];
        }
        int part = sum_prefix[n - 1] / 3;
        int left = 0, right = 0;
        for (int i = 0; i < n && sum_prefix[i] <= part; i++)
        {
            // left:
            int l_1 = i + 1, h_1 = n - 1;
            while (l_1 < h_1)
            {
                int mid = (l_1 + h_1) / 2;
                if (sum_prefix[i] > sum_prefix[mid] / 2)
                    l_1 = mid + 1;
                else if (sum_prefix[i] <= sum_prefix[mid] / 2)
                    h_1 = mid;
            }
            left = l_1;
            int l_2 = left, h_2 = n - 1;
            while (l_2 < h_2)
            {
                int mid = (l_2 + h_2) / 2;
                if ((sum_prefix[mid] - sum_prefix[i]) <= (sum_prefix[n - 1] - sum_prefix[i]) / 2)
                    l_2 = mid + 1;
                else if ((sum_prefix[mid] - sum_prefix[i]) > (sum_prefix[n - 1] - sum_prefix[i]) / 2)
                    h_2 = mid;
            }
            right = l_2;
            ans += right - left > 0 ? right - left : 0;
        }
        return ans % mod;
    }
};