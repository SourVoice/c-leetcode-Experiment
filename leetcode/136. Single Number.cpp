// 136. 只出现一次的数字
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
        int ret = 0;
        for (auto &num : nums)
            ret ^= num;
        return ret;
    }
};