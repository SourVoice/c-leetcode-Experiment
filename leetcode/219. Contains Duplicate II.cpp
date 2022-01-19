// 219. 存在重复元素 II
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//滑动窗口
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> st;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (i > k)
            {
                st.erase(nums[i - k - 1]);
            }
            if (st.count(nums[i]))
            {
                return true;
            }
            st.emplace(nums[i]);
        }
        return false;
    }
};
//哈希表
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            int num = nums[i];
            if (mp.count(nums[i]) && i - mp[num] < k)
            {
                return true;
            }
            mp.emplace(num, i);
            mp.insert(num, i);
        }
        return false;
    }
};