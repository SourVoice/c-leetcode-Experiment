// 349. 两个数组的交集

#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end(), [](const int &a, const int &b)
             { return a < b; });

        sort(nums2.begin(), nums2.end(), [](const int &a, const int &b)
             { return a < b; });
        set<int> s1;
        set<int> s2;
        for (auto i : nums1)
        {
            s1.insert(i);
        }
        for (auto i : nums2)
        {
            s2.insert(i);
        }
        vector<int> res;
        vector<int>::iterator it;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(res));
        return res;
    }
};