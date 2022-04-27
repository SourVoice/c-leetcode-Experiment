// 392. ÅÐ¶Ï×ÓÐòÁÐ
#include <string>
using namespace std;

//Ë«Ö¸Õë
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int idx_s = 0, idx_t = 0;
        while (s[idx_s] && t[idx_t])
        {
            if (s[idx_s] == t[idx_t])
            {
                idx_s++;
            }
            idx_t++;
        }
        return s[idx_s] == '\0';
    }
};