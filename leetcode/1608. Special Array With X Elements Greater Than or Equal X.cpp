// 1608. �������������ֵ
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// ����,brute force
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int special = n - i;
            if (nums[i] >= special)
            {
                if (i > 0 && nums[i - 1] < special)
                    return special;
                else if (i == 0)
                    return n;
            }
        }
        return -1;
    }
};
// ����
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (left + right) >> 1;
            int special = n - mid;
            int less = 0;
            if (mid > 0)
                less = nums[mid - 1];
            else
                less = -1;
            if (less < special && nums[mid] >= special)
                return special;
            else if (nums[mid] < special)
                left = mid + 1;
            else
                right = mid;
        }
        return -1;
    }
};