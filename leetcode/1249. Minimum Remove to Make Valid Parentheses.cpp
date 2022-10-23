// 1249. �Ƴ���Ч������
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
// ջ, ģ��
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<pair<char, int>> sk;
        // ��¼�Ƿ�����λ��
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
        // �Ƿ������滻ɾ��
        while (!sk.empty())
        {
            s[sk.top().second] = ' ';
            sk.pop();
        }
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }
};