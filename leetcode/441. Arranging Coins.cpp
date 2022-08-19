// 441. 排列硬币
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//二分查找
class Solution
{
public:
    int arrangeCoins(int n)
    {
        long left = 1, right = n;
        int ans = 1;
        while (left < right)
        {
            long long mid = (left - right) / 2 + right;
            long long tmp = mid * (mid + 1) / 2;
            if (tmp > n)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
                if (tmp == n)
                    ans = mid;
            }
        }
        return left * (left + 1) / 2 > n ? left - 1 : left;
    }
};
//简易版
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int left = 1, right = n;
        while (left < right)
        {
            int mid = (right - left + 1) / 2 + left;
            if ((long long)mid * (mid + 1) <= (long long)2 * n)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
