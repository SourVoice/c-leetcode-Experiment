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
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        vector<int> ret;
        priority_queue<int, vector<int>, decltype(greater<int>())> pq;
        for (auto &num : arr)
            pq.push(num);
        for (int i = 1; i <= k; i++)
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};