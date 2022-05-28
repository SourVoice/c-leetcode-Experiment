// 1021. É¾³ı×îÍâ²ãµÄÀ¨ºÅ
#include <string>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = s.size();
        int i = 0;
        string tmp = "";
        string ans;
        int cnt = 0;
        while (i < n)
        {
            if (s[i] == '(')
            {
                cnt++;
                tmp += s[i];
            }
            else
            {
                cnt--;
                tmp += s[i];
            }
            if (cnt == 0)
            {
                ans += tmp.substr(1, tmp.size() - 2);
                tmp.clear();
            }
            i++;
        }
        return ans;
    }
};