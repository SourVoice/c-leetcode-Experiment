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
class MaxQueue
{
public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (data.empty())
            return -1;
        return max_data.front();
    }

    void push_back(int value)
    {
        data.push(value);
        while (!max_data.empty() && max_data.back() < value)
        {
            max_data.pop_back();
        }
        max_data.push_back(value);
    }

    int pop_front()
    {
        if (data.empty())
            return -1;
        int ret = data.front();
        if (ret == max_data.front())
            max_data.pop_front();
        data.pop();
        return ret;
    }

private:
    queue<int> data;
    deque<int> max_data;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */