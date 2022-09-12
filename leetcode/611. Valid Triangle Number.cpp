// 611. 有效三角形的个数
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(begin(nums), end(nums), std::less<int>());
        int ret = 0;
        for (int i = n - 1; i >= 2; i--)
        {
            int j = 0, k = i - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] > nums[i])
                {
                    ret += k - j; // nums[k] & nums[i] & nums[j to k - j]都成立
                    k--;
                }
                else
                    j++;
            }
        }
        return ret;
    }
};