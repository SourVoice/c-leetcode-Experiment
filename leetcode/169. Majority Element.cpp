// 169. 多数元素
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

//哈希表
class Solution2
{
public:
    int maxValueInMap(map<int, int> &mp)
    {
        std::map<int, int>::iterator best = std::max_element(mp.begin(), mp.end(),
                                                             [](const std::pair<char, int> &a, const std::pair<char, int> &b) -> bool
                                                             { return a.second < b.second; });
        std::cout << best->first << " , " << best->second << "\n";
        return best->first;
    }
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }
        return maxValueInMap(mp);
    }
};

//摩尔投票法，遇到相同的数，就投一票，遇到不同的数，就减一票，最后还存在票的数就是众数
class Solution3
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majority = 0, count = 0;

        for (auto num : nums)
        {
            if (!count)
                majority = num;
            if (num == majority)
                count++;
            else
                count--;
        }
        return majority;
    }
};