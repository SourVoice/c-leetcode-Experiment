// 771. 宝石与石头
#include <unordered_map>
#include <string>
using namespace std;

//哈希表
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> mp;
        for (auto &ch : jewels)
            mp[ch]++;
        int ans = 0;
        for (auto &ch : stones)
            if (mp.count(ch))
                ans++;
        return ans;
    }
};

//数组
class Solution2
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        vector<char> pool(100, 0);
        for (auto &ch : jewels)
            pool[ch - 'A']++;
        int ans = 0;
        for (auto &ch : stones)
            if (pool[ch - 'A'])
                ans++;
        return ans;
    }
};
