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
class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int l = 0, r = numbers.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (numbers[mid] < numbers[r])
                r = mid; // 防止边界正好为最小
            else if (numbers[mid] > numbers[r])
                l = mid + 1;
            else // 去重
                r--;
        }
        return numbers[l];
    }
};