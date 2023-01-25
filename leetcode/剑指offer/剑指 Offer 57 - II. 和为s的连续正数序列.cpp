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
    vector<vector<int>> findContinuousSequence(int target)
    {
        int l = 1, r = 2;
        vector<vector<int>> ans;
        while (l < r)
        {
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target)
            {
                vector<int> vec;
                for (int i = l; i <= r; i++)
                    vec.push_back(i);
                ans.push_back(vec);
                l++;
            }
            else if (sum > target)
                l++;
            else
                r++;
        }
    }
};