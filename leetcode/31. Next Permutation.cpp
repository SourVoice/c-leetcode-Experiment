// 31. 下一个排列
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        while (j >= 0 && nums[i] >= nums[j])
            j--;
        if (j < 0)
            return;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};