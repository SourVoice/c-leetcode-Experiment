// 6180. ×îÐ¡Å¼±¶Êý
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
using namespace std;
class Solution
{
public:
    int smallestEvenMultiple(int n)
    {
        return !(n & 1) ? n : 2 * n;
    }
};