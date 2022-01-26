// 217. 存在重复元素

#include <set>
#include <vector>
#include <algorithm>
//哈希表
class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::set<int> st;
        for (auto &num : nums)
        {
            if (st.count(num))
            {
                return true;
            }
            st.insert(num);
        }
        return false;
    }
};
//简化
class Solution2
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        return std::set<int>(nums.begin(), nums.end()).size() != nums.size();
    }
};

//排序法
class Solution3
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end(), [&](const auto &a, const auto &b) -> bool
                  { return a > b; });
        auto begin = nums.begin();
        auto end = nums.end();
        while (begin < end - 1)
        {
            if (*begin == *(begin + 1))
                return true;
            begin++;
        }
        return false;
    }
};
