// 1189. “气球” 的最大数量
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> cnt(26, 0);
        for (int i = 0; i < text.size(); i++)
        {
            cnt[text[i] - 'a']++;
        }
        int ans = text.size();
        return min(ans, min(cnt['o' - 'a'] / 2, min(cnt['b' - 'a'], min(cnt['a' - 'a'], min(cnt['n' - 'a'], cnt['l' - 'a'] / 2)))));
    }
};
