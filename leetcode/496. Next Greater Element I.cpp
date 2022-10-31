// 496. 下一个更大元素 I
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <stack>
using namespace std;
// 单调栈+哈希表
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); i++)
            mp[nums1[i]] = i;
        stack<int> sk;
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums2.size(); i++)
        {
            while (!sk.empty() && nums2[i] > nums2[sk.top()])
            {
                ans[mp[nums2[sk.top()]]] = nums2[i];
                sk.pop();
            }
            if (mp.count(nums2[i]))
                sk.push(i);
        }
        return ans;
    }
};