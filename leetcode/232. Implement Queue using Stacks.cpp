// 232. 用栈实现队列
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
class MyQueue
{
public:
    MyQueue()
    {
    }

    // push 时全部转移到s2, pop全部转移至s1
    void push(int x)
    {
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }

    int pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int Top = s2.top();
        s2.pop();
        return Top;
    }

    int peek()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int Top = s2.top();
        return Top;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
