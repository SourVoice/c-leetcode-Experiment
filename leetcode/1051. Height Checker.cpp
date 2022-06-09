// 1051. ¸ß¶È¼ì²éÆ÷
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> t = heights;
        sort(t.begin(), t.end());
        int ans = 0;
        for (auto it = heights.begin(); it != heights.end(); it++)
        {
            if (*it != t[it - heights.begin()])
                ans++;
        }
        return ans;
    }
};