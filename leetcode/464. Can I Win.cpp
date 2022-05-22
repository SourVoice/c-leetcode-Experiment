// 464. 我能赢吗
#include <vector>
#include <unordered_map>
using namespace std;

// 博弈论,记忆化搜索,dfs
class Solution
{
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        unordered_map<int, bool> mp;
        return dfs(maxChoosableInteger, 0, desiredTotal, 0, mp);
    }
    bool dfs(int maxCouldChoose, int currentTotal, int desiredTotal, int usedNumbers, unordered_map<int, bool> &mp)
    {
        if (mp.count(usedNumbers))
            return mp[usedNumbers];
        for (int i = 0; i < maxCouldChoose; i++)
        {
            if (!((usedNumbers >> i) & 1)) // 状态压缩
            {
                if (currentTotal + i + 1 >= desiredTotal)
                {
                    mp[usedNumbers] = true; // cache
                    break;
                }
                if (!dfs(maxCouldChoose, currentTotal + i + 1, desiredTotal, usedNumbers | (1 << i), mp)) // 对方选择输,
                {
                    mp[usedNumbers] = true;
                    break;
                }
                mp[usedNumbers] = false;
            }
            mp[usedNumbers] = false; // cache
        }
        return mp[usedNumbers];
    }
};