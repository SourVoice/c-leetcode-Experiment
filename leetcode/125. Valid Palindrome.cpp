// 125. 验证回文串
#include <bits/stdc++.h>
using namespace std;
// 双指针
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        int i = 0, j = n - 1;
        for (; i < j;)
        {
            if (!isvalid(s[i]))
            {
                i++;
            }
            else if (!isvalid(s[j]))
            {

                j--;
            }
            else if (tolower(s[i]) == tolower(s[j]))
            {
                if (i + 1 == j)
                    return true;
                i++, j--;
            }
            else
                return false;
        }
        return i == j;
    }
    bool isvalid(char &c)
    {
        return isdigit(c) || isalpha(c);
    }
};