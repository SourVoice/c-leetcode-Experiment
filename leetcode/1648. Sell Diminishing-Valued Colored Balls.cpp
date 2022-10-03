// 1648. 销售价值减少的颜色球
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
// 二分查找
class Solution
{
public:
    int maxProfit(vector<int> &inventory, int orders)
    {
        int mod = 1e9 + 7;
        sort(begin(inventory), end(inventory), greater<int>());
        int l = 1, r = inventory[0];
        while (l < r)
        {
            int mid = (l + r) / 2;
            int sellNum = 0;
            for (auto &e : inventory)
            {
                if (e > mid)
                    sellNum += e - mid;
                if (sellNum > orders)
                    break;
            }
            if (sellNum > orders)
                l = mid + 1;
            else
                r = mid;
        }
        unsigned long profit = 0, cnt = 0;
        // 先不取l线处的值
        unsigned long tmpl = l + 1;
        for (auto &e : inventory)
        {
            if (e >= tmpl)
            {
                profit += (tmpl + e) * (e - tmpl + 1) / 2 % mod;
                cnt += (e - tmpl + 1);
            }
        }
        // l线处的卖出由剩余的决定
        if (cnt < orders)
            profit += (orders - cnt) * l % mod;

        return profit % mod;
    }
};