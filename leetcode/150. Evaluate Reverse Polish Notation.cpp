#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        const map<string, function<int(int, int)>> mp{
            {"+", [](const int &a, const int &b)
             { return a + b; }},
            {"-", [](const int &a, const int &b)
             { return a - b; }},
            {"*", [](const int &a, const int &b)
             { return a * b; }},
            {"/", [](const int &a, const int &b)
             { return a / b; }},
        };
        stack<int> sk;
        int left = 0, right = 0;
        for (auto &token : tokens)
        {
            if (isalnum(token.back()))
            {
                sk.push(stoi(token));
                continue;
            }
            right = sk.top();
            sk.pop();
            left = sk.top();
            sk.pop();
            sk.push(mp.find(token)->second(left, right));
        }
        return sk.top();
    }
};