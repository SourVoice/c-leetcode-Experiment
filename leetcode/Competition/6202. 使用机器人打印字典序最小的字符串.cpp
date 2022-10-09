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
// ̰��
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
        // ��¼s����iλ�ü��������С���ַ�
        minChar[s.size()] = 'z' + 1;
        for (int i = s.size() - 1; i >= 0; i--)
            minChar[i] = min(minChar[i + 1], s[i]);

        // �������ջ����s����һ���ַ��Ĵ�С��ϵ
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
