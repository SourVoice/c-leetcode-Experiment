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
    vector<int> constructArr(vector<int> &a)
    {
        int n = a.size();
        vector<int> left(n, 0);
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            left[i] = product;
            product *= a[i];
        }
        product = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            left[i] *= product;
            product *= a[i];
        }
        return left;
    }
};