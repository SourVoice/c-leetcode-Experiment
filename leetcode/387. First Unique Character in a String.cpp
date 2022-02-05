// 387. �ַ����еĵ�һ��Ψһ�ַ�
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

// C���Լ���
class Solution2
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