// 89. ¸ñÀ×±àÂë

#include <vector>
#include <functional>
using namespace std;
// dfs + »ØËİ labmdaĞ´·¨
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        function<void(vector<int> &, int, int, int)> help = [&](vector<int> &ans, int last, int index, int n)
        {
            if (index >= n)
                return;
            for (int i = index; i < n; i++)
            {
                int next = last ^ (1 << i);
                ans.push_back(next);
                help(ans, next, i + 1, n);
            }
        };

        vector<int> ans;
        ans.push_back(0);
        help(ans, 0, 0, n);
        return ans;
    }
};