// 961. 在长度 2N 的数组中找出重复 N 次的元素
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &num : nums)
        {
            if (mp.count(num))
                return num;
            mp[num]++;
        }
        return 0;
    }
};