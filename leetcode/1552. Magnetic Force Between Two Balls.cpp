// 1552. 两球之间的磁力
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(begin(position), end(position));
        int max_ = position[position.size() - 1];
        int min_ = position[0];
        int l = 1, r = max_ - min_; // 最小磁力和最大磁力作为边界
        auto magneticForce = [&](const vector<int> &position, int force, int m) -> int
        {
            int pre_pos = position[0];
            m--;
            for (int i = 1; i < position.size(); i++)
            {
                if (position[i] - pre_pos >= force)
                {
                    m--;
                    pre_pos = position[i];
                }
            }
            return m;
        };
        int ret = INT_MIN;
        int mid;
        while (l <= r)
        {
            mid = ((r - l) >> 1) + l;
            if (magneticForce(position, mid, m) > 0)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
                ret = max(mid, ret);
            }
        }
        return ret;
    }
};