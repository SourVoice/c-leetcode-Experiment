// 20. 有效的括号
#include <vector>
#include <assert.h>
#include <unordered_map>
#include <stdbool.h>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <stack>
using namespace std;
// 栈模拟
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> bracket;
        for (auto &e : s)
        {
            if (!bracket.empty() && (e == ')' || e == ']' || e == '}'))
            {
                if (bracket.top() == e - 1 || bracket.top() == e - 2)
                {
                    bracket.pop();
                    goto PUSH;
                }
                return false;
            }
            bracket.push(e);
        PUSH:
            continue;
        }
        return bracket.empty();
    }
};
