// 739. Ã¿ÈÕÎÂ¶È
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> sk; // stack of index
        vector<int> ret(n, 0);
        sk.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            auto cur = temperatures[i];
            while (!sk.empty() && temperatures[sk.top()] <= temperatures[i])
                sk.pop();
            if (!sk.empty())
                ret[i] = sk.top() - i;
            sk.push(i);
        }
        return ret;
    }
};