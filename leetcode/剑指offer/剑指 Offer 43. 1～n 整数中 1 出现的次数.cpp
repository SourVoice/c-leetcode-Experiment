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
    int countDigitOne(int n)
    {
        long base = 1;
        int ret = 0;
        while (base <= n)
        {
            int lowb = n % base;  // 低位
            int highb = n / base; // 高位部分
            int curb = highb % 10;
            highb /= 10;
            if (curb > 1)
                ret += ((highb + 1) * base);
            else if (curb == 1)
                ret += (highb * base + lowb + 1);
            else if (curb == 0)
                ret += highb * base;
            base *= 10;
        }
        return ret;
    }
};