#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <sstream>
using namespace std;
class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        int zerocnt = 0;
        sort(begin(nums), end(nums));
        int diff = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zerocnt++;
            else
            {
                if (i < nums.size() - 1)
                {
                    if (nums[i + 1] == nums[i])
                        return false;
                    diff += nums[i + 1] - nums[i] - 1;
                }
            }
        }
        return zerocnt >= diff;
    }
};
// 优化(数学)
class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int joker = 0; // 记录鬼牌数量，也就是最小牌的下标
        for (int i = 0; i < 4; ++i)
        {
            if (nums[i] == 0)
                joker++;
            else if (nums[i] == nums[i + 1])
                return false;
        }
        return nums[4] - nums[joker] < 5;
    }
};