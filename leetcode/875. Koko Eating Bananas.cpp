// 875. °®³ÔÏã½¶µÄçæçæ
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int max = *max_element(piles.begin(), piles.end());
        int l = 1, r = max, k = INT_MAX;
        while (l <= r)
        {
            int mid = (r - l) / 2 + l;
            if (countEatTimes(piles, h, mid) <= h)
            {
                k = fmin(k, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return k;
    }
    int countEatTimes(vector<int> piles, int time, int speed)
    {
        int count = 0;
        for (auto e : piles)
        {
            count += e / speed;
            if (e % speed != 0)
                count++;
        }
        return count;
    }
};