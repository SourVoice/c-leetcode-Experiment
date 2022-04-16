// 914. 卡牌分组
#include <vector>
#include <unordered_map>
using namespace std;

//避免一个误区，相同数字不一定放在同一组
class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> mp;
        for (auto i : deck)
            mp[i]++;
        int g = mp.begin()->second;
        for (auto e : mp)
        {
            if (e.second == 1)
                return false;
            g = __gcd(g, e.second);
        }
        return g >= 2;
    }
};