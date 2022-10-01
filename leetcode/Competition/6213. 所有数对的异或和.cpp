
#include <vector>
#include <unordered_map>
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
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int n_1 = nums1.size(), n_2 = nums2.size();
        if (!(n_1 & 1) && !(n_2 & 1))
            return 0;
        if (!(n_1 & 1) && (n_2 & 1))
        {
            int ret = 0;
            for (auto &e : nums1)
                ret ^= e;
            return ret;
        }
        else if ((n_1 & 1) && !(n_2 & 1))
        {
            int ret = 0;
            for (auto &e : nums2)
                ret ^= e;
            return ret;
        }
        else if ((n_1 & 1) && (n_2 & 1))
        {
            int ret = 0;
            for (auto &e : nums2)
                ret ^= e;
            for (auto &e : nums1)
                ret ^= e;
            return ret;
        }
        return 0;
    }
};