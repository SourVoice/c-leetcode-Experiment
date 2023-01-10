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
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        int buy = prices[0];
        int maxprofit = 0;
        for (int i = 0; i < n; i++)
        {
            buy = min(buy, prices[i]);
            maxprofit = max(maxprofit, prices[i] - buy);
        }
        return maxprofit;
    }
};