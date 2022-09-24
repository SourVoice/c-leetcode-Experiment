// 88. 合并两个有序数组
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
// 双指针
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> nums1_t(begin(nums1), begin(nums1) + m);
        nums1.clear();
        int i = 0, j = 0;
        while (i < nums1_t.size() && j < nums2.size())
        {
            if (nums1_t[i] < nums2[j])
            {
                nums1.push_back(nums1_t[i]);
                i++;
            }
            else if (nums1_t[i] > nums2[j])
            {
                nums1.push_back(nums2[j]);
                j++;
            }
            else
            {
                nums1.push_back(nums1_t[i]);
                nums1.push_back(nums2[j]);
                i++, j++;
            }
        }
        while (i < nums1_t.size())
            nums1.push_back(nums1_t[i++]);
        while (j < nums2.size())
            nums1.push_back(nums2[j++]);
    }
};
// 法二: 不断将两个中较大的放在后面即可
// 双指针
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0)
        {
            if (i >= 0 && (j < 0 || nums1[i] > nums2[j]))
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};
// 更简单的条件
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0)
        {
            if (i < 0 || nums2[j] > nums1[i])
                nums1[k--] = nums2[j--];
            else
                nums1[k--] = nums1[i--];
        }
    }
};
