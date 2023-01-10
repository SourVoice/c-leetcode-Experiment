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
    int fib(int n)
    {
        if (n == 0)
            return 0;
        int d0 = 0, d1 = 1;
        int d2 = 0;
        int i = 0;
        while (i < n - 1)
        {
            i++;
            d2 = d0 + d1;
            d0 = d1 % 1000000007;
            d1 = d2 % 1000000007;
        }
        return d1 % (1000000007);
    }
};