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
    int singleNumber(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto &&num : nums)
            mp[num]++;
        for (auto &&[e, time] : mp)
            if (time == 1)
                return e;
        return -1;
    }
};
// TODO: Œª‘ÀÀ„