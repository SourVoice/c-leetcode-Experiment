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
    int translateNum(int num)
    {
        string numstr = to_string(num);
        int n = numstr.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;
        int sum = 0;
        for (int i = 2; i <= n; i++)
        {
            int tmpnum = stoi(numstr.substr(i - 2, 2));
            if (numstr[i - 2] != '0' && tmpnum < 26 && tmpnum >= 10)
                dp[i] += dp[i - 2];
            dp[i] += dp[i - 1];
        }
        return dp[n];
    }
};