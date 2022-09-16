// 1482. 制作 m 束花所需的最少天数
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 二分查找
class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (n < m * k)
            return -1;
        int l = 1, r = *max_element(begin(bloomDay), end(bloomDay));
        auto countFlowersBundle = [&](const vector<int> &bloomDay, int day, int k) -> int
        {
            vector<int> res(n, 0);
            for (int i = 0; i < n; i++)
            {
                if (bloomDay[i] <= day)
                    res[i] = 1;
            }
            int bundle = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (res[i] == 1)
                {
                    cnt++;
                    if (cnt == k)
                    {
                        cnt = 0;
                        bundle++;
                    }
                }
                else
                    cnt = 0;
            }
            return bundle;
        };
        int ret = -1;
        while (l < r)
        {
            int mid = ((r - l) >> 1) + l;
            if (countFlowersBundle(bloomDay, mid, k) < m)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};