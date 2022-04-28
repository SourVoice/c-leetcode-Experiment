// 905. 按奇偶排序数组
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> odd; //存储奇数
        vector<int> even;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & 1)
            {
                odd.push_back(nums[i]);
            }
            else
            {
                even.push_back(nums[i]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < even.size(); i++)
        {
            ans.push_back(even[i]);
        }
        for (int i = 0; i < odd.size(); i++)
        {
            ans.push_back(odd[i]);
        }
        return ans;
    }
};

class Solution2
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            while (left < right && !(nums[left] & 1)) // till touch a odd number
            {
                left++;
            }
            while (left < right && (nums[right] & 1)) // till touch a even number
            {
                right--;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};
