// 169. ����Ԫ��
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

//��ϣ��
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

//Ħ��ͶƱ����������ͬ��������ͶһƱ��������ͬ�������ͼ�һƱ����󻹴���Ʊ������������
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