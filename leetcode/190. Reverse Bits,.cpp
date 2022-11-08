// 190. 颠倒二进制位
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
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint64_t ret = 0;
        for (int i = 0; i < 32; i++)
        {
            ret |= (n >> i) & 1;
            ret <<= 1;
        }
        return ret >> 1;
    }
};