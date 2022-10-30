#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// สýัง
class Solution
{
public:
    typedef long long ll;
    long long makeIntegerBeautiful(long long n, int target)
    {
        auto sum = [](ll x) -> ll
        {
            int ret = 0;
            while (x)
            {
                ret += x % 10;
                x = x / 10;
            }
            return ret;
        };
        ll tmp = n;
        ll carry = 1;
        while (1)
        {
            if (sum(n) > target)
            {
                n = n / carry;
                n++;
                n *= carry;
                carry *= 10;
            }
            else if (sum(n) <= target)
                return n - tmp;
        }
        return 0;
    }
};