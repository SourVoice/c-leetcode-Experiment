// 946. —È÷§’ª–Ú¡–
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            st.push(pushed[i]);
            while (!st.empty() && popped[j] == st.top())
            {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};