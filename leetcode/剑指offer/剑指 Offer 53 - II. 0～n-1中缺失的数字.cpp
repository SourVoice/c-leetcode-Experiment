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
using namespace std;
// ¶þ·Ö²éÕÒ
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == mid)
                l = mid + 1;
            else if (nums[mid] > mid)
                r = mid - 1;
        }
        return l;
    }
};