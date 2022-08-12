// 69. x 的平方根
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
    int mySqrt(int x)
    {
        int left = 0, right = x;
        while (left < right)
        {
            int mid = (left - right) / 2 + right;
            // 如果 mid * mid 小于或等于 x，说明mid可能是最后一个平方小于x的数, 或者恰好是x
            if (x / mid >= mid)
                left = mid;
            else if (x / mid < mid)
                right = mid - 1;
        }
        return left;
    }
};