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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq; // priority_queue 当存储pair的默认排序方式: 默认排序方式是先以first排序再以second排序
        for (int i = 0; i < k; i++)
            pq.emplace(nums[i], i);
        vector<int> ret{pq.top().first};
        for (int i = k; i < nums.size(); i++)
        {
            pq.emplace(nums[i], i);
            while (pq.top().second <= i - k)
            {
                pq.pop();
            }
            ret.push_back(pq.top().first);
        }
        return ret;
    }
};