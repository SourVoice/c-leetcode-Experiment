// 856. ���ŵķ���
#include <string>
#include <stack>
using namespace std;
// ջģ��
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        st.push(0);
        for (auto &e : s)
        {
            if (e == '(')
                st.push(0);
            else
            {
                int curVal = st.top();
                st.pop();
                int lastVal = st.top();
                st.pop();
                st.push(lastVal + (curVal == 0 ? 1 : curVal * 2));
            }
        }
        return st.top();
    }
};
// TODO: �ݹ�
