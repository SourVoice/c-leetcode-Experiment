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
    int add(int a, int b)
    {
        int sumWithoutCarry = 0;
        unsigned int carry = 0;
        while (b)
        {
            sumWithoutCarry = a ^ b;
            carry = static_cast<unsigned int>(a & b) << 1; // ·ÀÖ¹ÓÐ·ûºÅÒç³ö
            b = carry;
            a = sumWithoutCarry;
        }
        return sumWithoutCarry;
    }
};
// ??
class Solution
{
public:
    int add(int a, int b)
    {
        if (b == 0)
            return a;
        return add(a ^ b, (uint32_t)(a & b) << 1);
    }
};