// 387. 字符串中的第一个唯一字符
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> m;
        for (auto c : s)
        {
            m[c]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

//索引哈希表
class Solution2
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<int, int> position;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (position.count(s[i]))
            {
                position[s[i]] = -1;
            }
            else
            {
                position[s[i]] = i;
            }
        }
        int first = n;
        for (auto [_, pos] : position)
        {
            if (pos != -1 && pos < first)
            {
                first = pos;
            }
        }
        if (first == n)
        {
            first = -1;
        }
        return first;
    }
};

// C语言计数
class Solution3
{
public:
    int firstUniqChar(char *s)
    {
        int len = strlen(s);
        int *pool = (int *)calloc(26, sizeof(int));
        for (int i = 0; i < len; i++)
        {
            pool[s[i] - 'a']++;
        }
        for (int i = 0; i < len; i++)
        {
            if (pool[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};