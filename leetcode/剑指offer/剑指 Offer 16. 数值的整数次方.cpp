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
#include <sstream>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0 || x == 1)
            return 1;
        if (n < 0)
            return 1 / powhelper(x, abs(n));
        return powhelper(x, n);
    }
    double powhelper(double x, uint32_t n)
    {
        if (n == 1)
            return x;
        if (n & 1)
        { // Ææ´ÎÃÝ
            double tmp = powhelper(x, n / 2);
            return tmp * tmp * x;
        }
        else
        { // Å¼´ÎÃÝ
            double tmp = powhelper(x, n / 2);
            return tmp * tmp;
        }
    }
};