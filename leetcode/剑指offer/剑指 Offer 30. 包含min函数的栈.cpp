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
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        sk.push(x);
        if (prioritySk.empty() || x <= prioritySk.top()) // 由于栈的特性, 更小的元素一定在栈下部, 不用担心新入的元素需要重新比较.
        {
            prioritySk.push(x);
        }
    }

    void pop()
    {
        if (sk.top() == prioritySk.top())
            prioritySk.pop();
        sk.pop();
    }

    int top()
    {
        return sk.top();
    }

    int min()
    {
        if (prioritySk.empty())
            return 0;
        return prioritySk.top();
    }

private:
    stack<int> sk, prioritySk;
    int minVal = 0;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */