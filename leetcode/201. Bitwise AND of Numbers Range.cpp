// 201. 数字范围按位与
#include <string>
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
// 位运算
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int offset = 0;
        while (left != right) // 找到该区间共同前缀, 其他部分全部置0即可
        {
            left >>= 1;
            right >>= 1;
            offset++;
        }
        return left << offset;
    }
};