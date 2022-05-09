// 942. 增减字符串匹配
#include <vector>
#include <set>
#include <string>
using namespace std;

//双向增减,贪心
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        set<int> st;
        for (int i = 0; i <= n; i++)
        {
            st.emplace(i);
        }
        int numI = 0, numD = n; // if the s[0] is 'I', then
        vector<int> perm(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I')
                perm[i] = numI++;
            else
                perm[i] = numD--;
        }
        if (s[n - 1] == 'I')
            perm[n] = numI;
        else
            perm[n] = numD;
        return perm;
    }
};