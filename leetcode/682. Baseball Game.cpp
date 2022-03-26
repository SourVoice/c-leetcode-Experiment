// 682. ∞Ù«Ú±»»¸

#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> st;
        int n = ops.size();
        for (int i = 0; i < n; i++)
        {
            if (ops[i] == "C")
            {
                st.pop();
            }
            else if (ops[i] == "D")
            {
                st.push(st.top() * 2);
            }
            else if (ops[i] == "+")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            }
            else
            {
                st.push(stoi(ops[i]));
            }
        }
        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};