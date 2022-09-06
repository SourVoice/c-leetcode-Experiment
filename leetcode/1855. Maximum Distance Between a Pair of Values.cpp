// 1855. 下标对中的最大距离
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
//超时
class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int n_1 = nums1.size(), n_2 = nums2.size();
        int ans = 0;
        for (int i = 0; i < n_1; i++)
        {
            int num_1 = nums1[i];
            while (find_if(begin(nums2) + i + ans, end(nums2),
                           [&](const int &a)
                           { return a >= num_1; }) != nums2.end())
                ans++;
        }
        return ans;
    }
};
// 双指针
class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int n_1 = nums1.size(), n_2 = nums2.size();
        int j = 0;
        for (int i = 0; i < n_1; i++)
        {
            int num_1 = nums1[i];
            while (i + j < n_2 && nums2[i + j] >= num_1)
                j++; //保证了第二关指针与第一个指针之间的差恒增大
        }
        return j ? --j : 0;
    }
};
// 二分查找
class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int n_1 = nums1.size(), n_2 = nums2.size();
        int diff = 0;
        for (int i = 0; i < n_1; i++)
        {
            int left = i + diff, right = n_2 - 1;
            int num_1 = nums1[i];
            while (left <= right)
            {
                int mid = (left - right) / 2 + right;
                int mid_num = nums2[mid];
                if (mid_num >= num_1) // 原数组是递减的, 所以需要左边缩减
                    left = mid + 1;
                else if (mid_num < num_1)
                    right = mid - 1;
            }
            diff = max(left - i - 1, diff);
        }
        return diff;
    }
};