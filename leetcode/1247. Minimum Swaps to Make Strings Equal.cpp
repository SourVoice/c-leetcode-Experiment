// 1247. 交换字符使得字符串相同
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
// 贪心, 数学
class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int len = s1.size();
        int cntx = 0, cnty = 0;
        for (int i = 0; i < len; i++)
        {
            if (s1[i] == 'x' && s2[i] == 'y')
                cntx++;
            if (s1[i] == 'y' && s2[i] == 'x')
                cnty++;
        }
        if ((cntx + cnty) & 1) // 奇数时不能够匹配
            return -1;
        // x, y都为奇数时, 各自减一后将偶数匹配(x - 1)/2 + (y - 1) / 2, 多出的部分为xy, yx, 进行两次交换(+2即可)
        return (cntx + 1) / 2 + (cnty + 1) / 2;
    }
};