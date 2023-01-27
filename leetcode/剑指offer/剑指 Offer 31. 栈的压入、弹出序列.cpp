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
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> sk;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            sk.push(pushed[i]);
            while (!sk.empty() && sk.top() == popped[j])
            {
                sk.pop();
                j++;
            }
        }
        return sk.empty();
    }
};