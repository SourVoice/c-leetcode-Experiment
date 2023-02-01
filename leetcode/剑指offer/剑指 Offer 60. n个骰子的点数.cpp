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
    vector<double> dicesProbability(int n)
    {
        vector<double> dp(6, 1 / 6.0);
        for (int i = 2; i <= n; i++)
        {
            vector<double> tmp(5 * i + 1, 0);
            for (int j = 0; j < dp.size(); j++)
            {
                for (int k = 0; k < 6; k++)
                { // 新增骰子的点数
                    tmp[j + k] += dp[j] / 6.0;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};