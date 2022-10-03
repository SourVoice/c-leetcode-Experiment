// 1488. �����ˮ����
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
// ̰��;��ϣ��;���ֲ���
// ��ȷ����, ��ʱ
class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        map<int, int> mp; // ��¼�����һ�ε���������
        vector<int> ans(n, -1);
        set<int> dryDay;
        for (int i = 0; i < n; i++)
        {
            int lake = rains[i];
            if (lake == 0)
            {
                dryDay.insert(i);
                ans[i] = 1;
                continue;
            }
            if (mp.find(lake) != mp.end())
            {
                // ȡ ��mp[rains[i]] ��i ֮�����С
                // �� ��һ������mp[rains[i]]��
                auto it = lower_bound(begin(dryDay), end(dryDay), mp[lake]);
                if (it == dryDay.end())
                    return {};
                ans[*it] = lake;
                dryDay.erase(it);
            }
            mp[lake] = i;
        }
        return ans;
    }
};
// �ĵ�lower_bound
class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        map<int, int> mp; // ��¼�����һ�ε���������
        vector<int> ans(n, -1);
        set<int> dryDay;
        for (int i = 0; i < n; i++)
        {
            int lake = rains[i];
            if (lake == 0)
            {
                dryDay.insert(i);
                ans[i] = 1;
                continue;
            }
            if (mp.find(lake) != mp.end())
            {
                // ȡ ��mp[rains[i]] ��i ֮�����С
                // �� ��һ������mp[rains[i]]��
                auto it = dryDay.lower_bound(mp[lake]);
                if (it != dryDay.end())
                    ans[*it] = lake, dryDay.erase(it);
                else
                    return vector<int>();
            }
            mp[lake] = i;
        }
        return ans;
    }
};