// 350. 两个数组的交集 II
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

// stl练习法
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (auto &i : nums1)
        {
            mp1[i]++;
        }
        for (auto &i : nums2)
        {
            mp2[i]++;
        }
        sort(nums1.begin(), nums1.end(), [&](const int &a, const int &b)
             { return a > b; });
        sort(nums2.begin(), nums2.end(), [&](const int &a, const int &b)
             { return a > b; });
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        vector<int> intersection;
        set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(),
                         insert_iterator<vector<int>>(intersection, intersection.begin()));
        vector<int> ans;
        for (auto &elem : intersection)
        {
            int count = min(mp1[elem], mp2[elem]);
            for (int i = 0; i < count; i++)
            {
                ans.push_back(elem);
            }
        }
        return ans;
    }
};

//更简单的遍历
class Solution2
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        unordered_map<int, int> mp;
        for (auto &num : nums1)
        {
            mp[num]++;
        }
        vector<int> ans;

        for (auto &num : nums2)
        {
            if (mp.count(num))
            {
                ans.push_back(num);
                mp[num]--;
                if (mp[num] == 0)
                    mp.erase(num);
            }
        }
        return ans;
    }
};