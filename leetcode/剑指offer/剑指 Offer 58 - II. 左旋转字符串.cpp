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
using namespace std;
class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        reverse(begin(s) + n, end(s));
        reverse(begin(s), begin(s) + n);
        reverse(begin(s), end(s));
        return s;
    }
};