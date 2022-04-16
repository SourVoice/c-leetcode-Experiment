// 914. ���Ʒ���
#include <vector>
#include <unordered_map>
using namespace std;

//����һ����������ͬ���ֲ�һ������ͬһ��
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