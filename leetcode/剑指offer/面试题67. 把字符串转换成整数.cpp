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
    int strToInt(string str)
    {
        int n = str.size();
        int i = 0;

        // 去掉头部空格
        while (i < n)
        {
            if (str[i] == ' ')
                i++;
            else
                break;
        }

        bool neg = false;

        // 负号时按正数做, 最后乘-1即可
        if (str[i] == '-')
            neg = true, i++;
        else if (str[i] == '+')
            i++;

        // 取出我们需要转化的部分
        //
        char *strtmp = (char *)malloc(sizeof(char) * 1000);
        int strpos = 0;

        // 忽略头部0
        while (i < n)
        {
            if (str[i] != '0')
                break;
            else
                i++;
        }

        while (i < n)
        {
            if (str[i] <= '9' && str[i] >= '0')
            {
                strtmp[strpos++] = str[i];
            }
            else
                break;
            i++;
        }

        long long res = 0;

        // 溢出标志
        bool ovf = false;
        int p = 0;

        for (int i = strpos - 1; i >= 0; i--)
        {
            // converting the values to int and then multiplying by
            // corrent power of 10 so as to get that value at correct position
            int val = strtmp[i] - '0';
            res += val * pow(10, p);
            p++;

            // in case the overflow occurs, we immediately stop and make ovf = true
            if ((p > 10) || res > INT_MAX)
            {
                ovf = true;
                break;
            }
        }

        // in case there is overflow, we return the values accordingly
        if (ovf)
        {
            if (neg)
                return INT_MIN;
            else
                return INT_MAX;
        }

        // else if neg = true return -res else res
        if (neg)
            return -res;
        else
            return res;
    }
};