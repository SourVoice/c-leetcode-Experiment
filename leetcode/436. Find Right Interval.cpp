// 436. Ѱ��������
#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// ��ϣ��
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        map<int, int> mp; // must use map instead of unordered_map
        for (int i = 0; i < intervals.size(); i++)
        {
            mp[intervals[i][0]] = i;
        }
        vector<int> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            auto it = mp.lower_bound(intervals[i][1]); //����map�е�һ�����ڻ����key�ĵ�����ָ��
            if (it == mp.end())
                ans.push_back(-1);
            else
                ans.push_back(it->second);
        }
        return ans;
    }
};

// ˫ָ��