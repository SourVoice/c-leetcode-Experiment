// 442. 数组中重复的数据
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 哈希表;暴力
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &num : nums)
        {
            mp[num]++;
        }
        vector<int> ret;
        for (auto &[_, __] : mp)
        {
            if (__ == 2)
                ret.push_back(_);
        }
        return ret;
    }
};

// 排序
class Solution2
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](const int a, const int b)
             { return a < b; });
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                ret.push_back(nums[i]);
        }
        return ret;
    }
};

//利用余数
class Solution3
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sign = (nums[i] - 1) % n;
            nums[sign] += n;
            if (nums[sign] > 2 * n)
                ret.push_back(sign + 1);
        }
        return ret;
    }
};