
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
    string minNumber(vector<int> &nums)
    {
        vector<string> vec;
        for (auto &num : nums)
            vec.push_back(to_string(num));
        sort(begin(vec), end(vec), [](const auto &a, const auto &b)
             { return a + b < b + a; });
        string ret;
        for (auto &e : vec)
            ret.append(e);
        return ret;
    }
};