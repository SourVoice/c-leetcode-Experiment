// 155. ×îÐ¡Õ»
#include <string>
#include <stack>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (sk.empty())
            minVal = val;
        sk.push({val, minVal = min(val, minVal)});
    }

    void pop()
    {
        sk.pop();
        if (!sk.empty())
            minVal = sk.top().second;
    }

    int top()
    {
        return sk.top().first;
    }

    int getMin()
    {
        return sk.top().second;
    }

private:
    stack<pair<int, int>> sk;
    int minVal = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */