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
    int nthUglyNumber(int n)
    {
        long cur = 1;
        int cnt = 0;
        map<long, bool> mp; // ШЅжи
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(cur);
        while (1)
        {
            cur = pq.top();
            pq.pop();
            if (!mp.count(cur))
            {
                pq.push(2 * cur);
                pq.push(3 * cur);
                pq.push(5 * cur);
                mp[cur] = 1;
                cnt++;
                if (cnt == n)
                    break;
            }
        }
        return cur;
    }
};