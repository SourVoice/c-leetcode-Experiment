// 29. 两数相除
#include <string>
#include <functional>
#include <deque>
#include <vector>
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
using namespace std;
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int64_t d = dividend;
        int64_t dd = divisor;

        if (d == INT_MIN && dd == -1)
            return INT_MAX;
        if (dd == 1)
            return d;
        if (dd == -1)
            return -d;

        d = abs(d);
        dd = abs(dd);
        int count = 0;
        if (dd == 2)
        {
            d = d >> 1;
            count = d;
        }
        else
        {
            while (d >= dd)
            {
                int countx = 1;
                int64_t divisorx = dd;
                while (d > divisorx << 1) // 模拟减法
                {
                    divisorx = divisorx << 1; // 一次减法
                    countx = countx << 1;
                }
                count += countx;
                d -= divisorx;
                cout << d;
            }
        }
        bool neg = (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) ? 1 : 0;
        return neg ? -count : count;
    }
};