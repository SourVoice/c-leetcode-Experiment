#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <map>
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
    int majorityElement(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        return nums[nums.size() - 1];
    }
};
// Ä¦¶ûÍ¶Æ±:
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int vote = 0;
        int majority = 0;
        for (auto &&num : nums)
        {
            if (!vote)
                majority = num;
            if (num == majority)
                vote++;
            else
                vote--;
        }
        return majority;
    }
};