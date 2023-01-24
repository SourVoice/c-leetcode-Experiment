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
// 模拟超时
class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        vector<int> vec(n, 1);
        for (int i = 0; i < n; i++)
            vec[i] = i;
        int kill = 0;
        while (n > 1)
        {
            kill = (kill + (m - 1)) % n;
            vec.erase(vec.begin() + kill);
            n--;
        }
        return vec[0];
    }
};
// 数学
class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        int x = 0;
        for (int i = 2; i <= n; i++)
        {
            x = (x + m) % i;
        }
        return x;
    }
};