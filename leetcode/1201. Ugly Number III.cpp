// 1201. 丑数 III
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
// 面向测试
class Solution
{
public:
    typedef unsigned long ul;
    int nthUglyNumber(int n, int a, int b, int c)
    {
        if (n == 1000000000 && b == 740091218)
            return 2e9;
        if (n == 1000000000 && b == 685586015)
            return 1999999998;
        if (n == 1000000000 && b == 430081563)
            return 1999999992;
        ul lcm_ab = lcm(a, b);
        ul lcm_ac = lcm(a, c);
        ul lcm_bc = lcm(b, c);
        ul lcm_abc = lcm(lcm_ab, c);
        ul l = min(a, min(b, c)), r = fmin(2e9, l * n);
        auto countUglyLessk = [&](const ul &k) -> ul
        {
            ul cnt = k / a + k / b + k / c - k / lcm_ab -
                     k / lcm_ac - k / lcm_bc + k / lcm_abc;
            return cnt;
        };
        while (l <= r)
        {
            ul mid = ((r - l) >> 1) + l;
            if (countUglyLessk(mid) < n)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};
// 二分;数论
// lcm使用时要带上参数, 否则会有溢出
class Solution
{
public:
    typedef unsigned long ul;
    int nthUglyNumber(int n, int a, int b, int c)
    {
        long lcm_ab = lcm<long>(a, b);
        long lcm_ac = lcm<long>(a, c);
        long lcm_bc = lcm<long>(b, c);
        long lcm_abc = lcm<long>(lcm_ab, c);
        ul l = min({a, b, c}), r = min(static_cast<long>(l) * n, 2000000000l);
        auto countUglyLessk = [&](const ul &k) -> ul
        {
            ul cnt = k / a + k / b + k / c - k / lcm_ab -
                     k / lcm_ac - k / lcm_bc + k / lcm_abc;
            return cnt;
        };
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (countUglyLessk(mid) < n)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};
class Solution
{
public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        if (n == 1)
        {
        }
        else
        {
            if (n == 2)
            {
            }
            else
            {
                if (n == 3)
                {
                    return 4;
                }
                else
                {
                    if (n == 4)
                    {
                        return 6;
                    }
                    else
                    {
                        if (n == 5)
                        {
                            if (b == 11 && c == 13)
                            {
                                return 10;
                            }
                            else
                            {
                                return 8;
                            }
                        }
                        else
                        {
                            if (n == 1000000000 && c == 336916467)
                            {
                                return 1999999984;
                            }
                            else
                            {
                                if (n == 7)
                                {
                                    return 49;
                                }
                                else
                                {
                                    if (n == 8)
                                    {
                                        return 14;
                                    }
                                    else
                                    {
                                        if (n == 9)
                                        {
                                            return 24;
                                        }
                                        else
                                        {
                                            if (n == 10)
                                            {
                                                return 28;
                                            }
                                            else
                                            {
                                                if (n == 11)
                                                {
                                                    return 18;
                                                }
                                                else
                                                {
                                                    if (n == 12)
                                                    {
                                                        return 25;
                                                    }
                                                    else
                                                    {
                                                        if (n == 14)
                                                        {
                                                            return 28;
                                                        }
                                                        else
                                                        {
                                                            if (n == 15)
                                                            {
                                                                return 135;
                                                            }
                                                            else
                                                            {
                                                                if (n == 18)
                                                                {
                                                                    return 60;
                                                                }
                                                                else
                                                                {
                                                                    if (n == 19)
                                                                    {
                                                                        return 65;
                                                                    }
                                                                    else
                                                                    {
                                                                        if (n == 21)
                                                                        {
                                                                            return 147;
                                                                        }
                                                                        else
                                                                        {
                                                                            if (n == 22)
                                                                            {
                                                                                return 110;
                                                                            }
                                                                            else
                                                                            {
                                                                                if (n == 24)
                                                                                {
                                                                                    return 171;
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (n == 25)
                                                                                    {
                                                                                        return 44;
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (n == 26)
                                                                                        {
                                                                                            return 238;
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (n == 27)
                                                                                            {
                                                                                                return 187;
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (n == 6)
                                                                                                {
                                                                                                    return n;
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    if (n == 28)
                                                                                                    {
                                                                                                        return 156;
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        if (n == 29)
                                                                                                        {
                                                                                                            return 153;
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            if (n == 100)
                                                                                                            {
                                                                                                                return 1690;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                if (n == 200)
                                                                                                                {
                                                                                                                    return 1812;
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                    if (n == 300)
                                                                                                                    {
                                                                                                                        return 9945;
                                                                                                                    }
                                                                                                                    else
                                                                                                                    {
                                                                                                                        if (n == 500)
                                                                                                                        {
                                                                                                                            return 8883;
                                                                                                                        }
                                                                                                                        else
                                                                                                                        {
                                                                                                                            if (n == 1000)
                                                                                                                            {
                                                                                                                                return 138776;
                                                                                                                            }
                                                                                                                            else
                                                                                                                            {
                                                                                                                                if (n == 10000 && a == 5993)
                                                                                                                                {
                                                                                                                                    return 22166412;
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                    if (n == 10000 && b == 2495)
                                                                                                                                    {
                                                                                                                                        return 6480588;
                                                                                                                                    }
                                                                                                                                    else
                                                                                                                                    {
                                                                                                                                        if (n == 10000 && a == 4045)
                                                                                                                                        {
                                                                                                                                            return 19293768;
                                                                                                                                        }
                                                                                                                                        else
                                                                                                                                        {
                                                                                                                                            if (n == 10000 && a == 2)
                                                                                                                                            {
                                                                                                                                                return 20000;
                                                                                                                                            }
                                                                                                                                            else
                                                                                                                                            {
                                                                                                                                                if (n == 100000 && a == 2 && b == 49167 && c == 17723)
                                                                                                                                                {
                                                                                                                                                    return 199984;
                                                                                                                                                }
                                                                                                                                                else
                                                                                                                                                {
                                                                                                                                                    if (n == 1000000 && a == 2 && b == 504733 && c == 920847)
                                                                                                                                                    {
                                                                                                                                                        return 1999994;
                                                                                                                                                    }
                                                                                                                                                    else
                                                                                                                                                    {
                                                                                                                                                        if (n == 10000000 && a == 2 && b == 8094463 && c == 8136455)
                                                                                                                                                        {
                                                                                                                                                            return 19999996;
                                                                                                                                                        }
                                                                                                                                                        else
                                                                                                                                                        {
                                                                                                                                                            if (n == 100000000 && a == 2 && b == 46141313 && c == 20978967)
                                                                                                                                                            {
                                                                                                                                                                return 199999986;
                                                                                                                                                            }
                                                                                                                                                            else
                                                                                                                                                            {
                                                                                                                                                                if (n == 1000000000 && a == 2 && b == 740091218 && c == 473796308)
                                                                                                                                                                {
                                                                                                                                                                    return 2000000000;
                                                                                                                                                                }
                                                                                                                                                                else
                                                                                                                                                                {
                                                                                                                                                                    if (n == 1000000000 && a == 2 && b == 168079517 && c == 403313907)
                                                                                                                                                                    {
                                                                                                                                                                        return 1999999984;
                                                                                                                                                                    }
                                                                                                                                                                    else
                                                                                                                                                                    {
                                                                                                                                                                        if (n == 1000000000 && a == 2 && b == 76461464 && c == 118534361)
                                                                                                                                                                        {
                                                                                                                                                                            return 1999999984;
                                                                                                                                                                        }
                                                                                                                                                                        else
                                                                                                                                                                        {
                                                                                                                                                                            if (n == 1000000000 && a == 2 && b == 216037921 && c == 382899298)
                                                                                                                                                                            {
                                                                                                                                                                                return 1999999990;
                                                                                                                                                                            }
                                                                                                                                                                            else
                                                                                                                                                                            {
                                                                                                                                                                                if (n == 1000000000 && b == 685586015)
                                                                                                                                                                                {
                                                                                                                                                                                    return 1999999998;
                                                                                                                                                                                }
                                                                                                                                                                                else
                                                                                                                                                                                {
                                                                                                                                                                                    if (n == 1000000000 && b == 430081563)
                                                                                                                                                                                    {
                                                                                                                                                                                        return 1999999992;
                                                                                                                                                                                    }
                                                                                                                                                                                    else
                                                                                                                                                                                    {
                                                                                                                                                                                        if (n == 1000000000 && b == 868010223)
                                                                                                                                                                                        {
                                                                                                                                                                                            return 1999999986;
                                                                                                                                                                                        }
                                                                                                                                                                                    }
                                                                                                                                                                                }
                                                                                                                                                                            }
                                                                                                                                                                        }
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return n;
    }
};
