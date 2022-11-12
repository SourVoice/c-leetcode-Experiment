// 844. 比较含退格的字符串
#include <vector>
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
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> sk1, sk2;
        int i = 0, j = 0;
        while (i < s.size() && j < t.size())
        {
            if (isalpha(s[i]))
                sk1.push(s[i]);
            else
            {
                if (!sk1.empty())
                    sk1.pop();
            }
            if (isalpha(t[j]))
                sk2.push(t[j]);
            else
            {
                if (!sk2.empty())
                    sk2.pop();
            }
            i++, j++;
        }
        while (i < s.size())
        {
            if (isalpha(s[i]))
                sk1.push(s[i]);
            else
            {
                if (!sk1.empty())
                    sk1.pop();
            }
            i++;
        }
        while (j < t.size())
        {
            if (isalpha(t[j]))
                sk2.push(t[j]);
            else
            {
                if (!sk2.empty())
                    sk2.pop();
            }
            j++;
        }
        string s_l, t_l;
        while (!sk1.empty())
        {
            s_l.push_back(sk1.top());
            sk1.pop();
        }
        while (!sk2.empty())
        {
            t_l.push_back(sk2.top());
            sk2.pop();
        }
        return t_l == s_l;
    }
};
// 双指针
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        auto helper = [&](string &str) -> void
        {
            int i = 0, j = 0;
            while (i < str.size())
            {
                if (str[i] == '#')
                {
                    if (j > 0)
                        j--;
                }
                else
                    str[j++] = str[i];
                i++;
            }
            str.resize(j);
        };
        helper(s);
        helper(t);
        cout << s << endl;
        cout << t << endl;
        return s == t;
    }
};