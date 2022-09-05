// 633. 平方数之和
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
// 二分
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c == 3)
            return false;
        if (c <= 4)
            return true;
        for (long i = 0; static_cast<long>(i * i) < c; i++)
        {
            int left = 0, right = sqrt(c + 1);
            while (left <= right)
            {
                {
                    int mid = (left + right) / 2;
                    long long res = mid * mid;
                    if (res == c - i * i)
                    {
                        return true;
                    }
                    else if (res < c - i * i)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
        }
        return false;
    }
};