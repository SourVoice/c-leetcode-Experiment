// 1249. 移除无效的括号
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
// 栈, 模拟
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<pair<char, int>> sk;
        // 记录非法符号位置
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                sk.push({'(', i});
            else if (s[i] == ')')
            {
                if (!sk.empty() && sk.top().first == '(')
                    sk.pop();
                else
                    sk.push({')', i});
            }
        }
        // 非法符合替换删除
        while (!sk.empty())
        {
            s[sk.top().second] = ' ';
            sk.pop();
        }
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }
};