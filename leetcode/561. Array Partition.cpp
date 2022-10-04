// 561. Êý×é²ð·Ö
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
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        int ret = 0;
        for (int i = 0; i < nums.size();)
        {
            !(i & 1) ? ret += nums[i++] : i++;
        }
        return ret;
    }
};