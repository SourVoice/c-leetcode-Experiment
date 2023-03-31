// 137. 只出现一次的数字 II
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
    int singleNumber(vector<int> &nums)
    {
        int a[32] = {0};
        for (auto num : nums)
        {
            for (int i = 0; i < 32; i++)
            {
                a[i] += (num >> (31 - i)) & 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            ret = (ret << 1) + a[i] % 3;
        }
        return ret;
    }
};
