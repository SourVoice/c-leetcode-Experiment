// 1802. 有界数组中指定下标处的最大值
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <map>
using namespace std;
// 报废
class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        int l = 1, r = maxSum;
        auto minsum = [&](const int &target) -> int
        {
            int sum = 0;
            int suml = 0, sumr = 0;
            int len_l = index + 1;
            if (len_l < target)
                suml = len_l * (target + target - len_l + 1) / 2;
            else
            {
                int sum1 = (1 + target) * target / 2;
                int sum2 = len_l - target;
                suml = sum1 + sum2;
            }
            int len_r = n - index;
            if (len_r - 1 < target) // 右侧选择降序
            {
                sumr = (target + target - len_r + 1) * len_r / 2;
            }
            else
            {
                sumr = (target + 1) * target / 2 + len_r - target;
            }
            sum = sumr + suml - target;
            return sum;
        };
        while (l < r)
        {
            int mid = (l + r) / 2;
            int ret = minsum(mid);
            if (ret > maxSum)
                r = mid - 1;
            else
                l = mid;
        }
        return l;
    }
};
// 重写
class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        int l = 1, r = maxSum;
        auto minsum = [&](const int &target, const int &l) -> long
        {
            long sum = 0;
            long long tar = target;
            if (l <= tar)
                sum = l * (tar + tar - l + 1) / 2;
            else
            {
                int sum1 = (1 + tar) * tar / 2;
                int sum2 = l - tar;
                sum = sum1 + sum2;
            }
            return sum;
        };
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            long ret = minsum(mid, index + 1) + minsum(mid, n - index) - mid;
            if (ret > maxSum)
                r = mid - 1;
            else
            {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};
//  边界处理
class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        int l = 1, r = maxSum;
        auto minsum = [&](const int &target, const int &l) -> long
        {
            long sum = 0;
            long long tar = target;
            if (l < tar)
                sum = l * (tar + tar - l + 1) / 2;
            else
            {
                sum = (1 + tar) * tar / 2 + l - tar;
            }
            return sum;
        };
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            long ret = minsum(mid, index + 1) + minsum(mid, n - index) - mid;
            if (ret <= maxSum)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};