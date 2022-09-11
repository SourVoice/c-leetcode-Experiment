#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto &num : nums)
        {
            if (!(num & 1))
                mp[num]++;
        }
        if (mp.empty())
            return -1;
        int ret = -1, min_n = INT_MAX;
        for (auto &[num, cnt] : mp)
        {
            if (ret < cnt)
                ret = cnt, min_n = num;
            else if (cnt == ret)
            {
                min_n = min(min_n, num);
            }
        }
        return min_n;
    }
};