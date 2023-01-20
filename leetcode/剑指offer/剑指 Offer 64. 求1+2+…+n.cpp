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
    int sumNums(int n)
    {
        if (n == 1)
            return 1;
        return n + sumNums(n - 1);
    }
};
// 不使用if语句:
class Solution
{
public:
    int sumNums(int n)
    {
        n != 1 && (n += sumNums(n - 1));
        return n;
    }
};
// 利用编译器
class Solution
{
public:
    int sumNums(int n)
    {
        bool arr[n][n + 1]; // bool占据一个字节
        return sizeof(arr) >> 1;
    }
};
