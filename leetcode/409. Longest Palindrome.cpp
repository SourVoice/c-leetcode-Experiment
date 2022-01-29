// 409. 最长回文串

// hash表
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int res = 0;
        unordered_map<char, int> m;
        for (auto c : s)
        {
            m[c]++;
        }
        for (auto it : m)
        {
            if (it.second % 2 == 0)
            {
                res += it.second;
            }
            else
            {
                res += it.second - 1;
            }
        }
        return res >= s.size() ? res : res + 1;
    }
};