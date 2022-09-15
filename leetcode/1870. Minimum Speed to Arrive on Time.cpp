// 1870. 准时到达的列车最小时速
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    int minSpeedOnTime(vector<int> &dists, double hour)
    {
        int l = 1, r = 1e7;
        auto countHour = [&](const vector<int> &dists, int speed) -> double
        {
            double h = 0;
            for (int i = 0; i < dists.size() - 1; ++i)
            {
                h += (dists[i] - 1) / speed + 1;
            }
            h += dists.back() / static_cast<double>(speed);
            return h;
        };
        int ret = -1;
        ;
        while (l <= r)
        {
            int mid = ((r - l) >> 1) + l;
            if (countHour(dists, mid) <= hour)
            {
                r = mid - 1;
                ret = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ret;
    }
};
