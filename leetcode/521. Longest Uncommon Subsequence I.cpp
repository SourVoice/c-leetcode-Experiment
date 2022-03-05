// 521. 最长特殊序列 Ⅰ

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a == b)
            return -1;
        return max(a.length(), b.length());
    }
};