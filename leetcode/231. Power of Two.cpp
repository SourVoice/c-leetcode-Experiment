// 231. 2 的幂
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
// 循环
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int cnt = 0;
        if (n < 0)
            return false;
        for (int i = 0; i < 32; i++)
        {
            if ((n >> i) & 1)
                cnt++;
            if (cnt > 1)
                return false;
        }
        return cnt;
    }
};
// 使用trick
// 二的幂减一必全为1, 且少一位
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};