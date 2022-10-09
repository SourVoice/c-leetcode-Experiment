#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 贪心
// reference:
// @leetcode user: TsReaper
class Solution
{
public:
    string robotWithString(string s)
    {
        stack<char> t;
        string print = "";
        vector<char> minChar(s.size() + 1);
        // 记录s串中i位置及其后面最小的字符
        minChar[s.size()] = 'z' + 1;
        for (int i = s.size() - 1; i >= 0; i--)
            minChar[i] = min(minChar[i + 1], s[i]);

        // 持续检查栈顶和s中下一个字符的大小关系
        for (int i = 0; i < s.size(); i++)
        {
            t.push(s[i]);
            while (!t.empty() && t.top() <= minChar[i + 1])
            {
                print.push_back(t.top());
                t.pop();
            }
        }
        while (!t.empty())
        {
            print.push_back(t.top());
            t.pop();
        }
        return print;
    }
};
