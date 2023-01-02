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
class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        sk1.push(value);
    }

    int deleteHead()
    {
        while (!sk2.empty())
        {
            int ret = sk2.top();
            sk2.pop();
            return ret;
        }
        while (!sk1.empty())
        {
            int sk1top = sk1.top();
            sk1.pop();
            sk2.push(sk1top);
        }
        if (sk2.empty())
            return -1;
        int ret = sk2.top();
        sk2.pop();
        return ret;
    }

private:
    stack<int> sk1, sk2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */