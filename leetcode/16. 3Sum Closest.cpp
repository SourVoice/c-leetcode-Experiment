// 16. 最接近的三数之和
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//双指针
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int tmp_sum = nums[i] + nums[left] + nums[right];
                if (abs(tmp_sum - target) < abs(sum - target))
                    sum = tmp_sum;
                else if (tmp_sum < target)
                    left++;
                else
                    right--;
            }
        }
        return sum;
    }
};