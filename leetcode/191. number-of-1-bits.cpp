// 191. 位1的个数
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
// 位运算
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        auto count1 = [&](uint32_t &num) -> uint32_t
        {
            uint32_t n = num;
            n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
            n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
            n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
            return n;
        };
        return count1(n);
    }
};
// 暴力
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
            n &= (n - 1), count++;
        return count;
    }
};
