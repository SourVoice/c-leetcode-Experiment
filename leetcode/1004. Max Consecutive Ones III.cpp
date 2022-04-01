//1004. 最大连续1的个数 III
#include<vector>
#include<functional>
using namespace std;
//滑动窗口
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        function <int(vector<int> &, int, int)> helper = [&](vector<int> &nums, int k, int num)
        {
            int n = nums.size();
            int left=0 ,right = 0;
            int ans = 0, sum = 0;
            for (int right = 0; right < n;right++)
            {
                sum += nums[right] != num;
                while (sum > k)
                {
                    sum -= nums[left++] != num;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        };
        return helper(nums, k, 1);
    }
};