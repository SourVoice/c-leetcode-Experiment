// 187. �ظ���DNA����
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <bitset>
using namespace std;
// ��ϣ��+����
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> mp;
        set<string> cnt;
        vector<string> ans;
        for (int i = 0; i < s.size(); i++)
        {
            string str = s.substr(i, 10);
            mp[str]++;
            if (mp[str] > 1)
            {
                if (!cnt.count(str))
                    cnt.emplace(str), ans.push_back(str);
            }
        }
        return ans;
    }
};
// λ����洢״̬
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        // ʹ��00, 01, 11, 10��ʾ A, G, T, C
        // ʹ��20��bit��ʾ10������
        unordered_map<char, int> mp{{'A', 0}, {'G', 1}, {'T', 2}, {'C', 3}};
        vector<string> ans;
        bitset<1 << 20> s1, s2;
        int val = 0;
        // ȡ��ǰʮ��
        for (int i = 0; i < 10; i++)
            val = (val << 2) | mp[s[i]];
        s1.set(val);
        int mask = (1 << 20) - 1; // 20��1
        for (int i = 10; i < s.size(); i++)
        {
            val = ((val << 2) & mask) | mp[s[i]]; // ȥ����ߵ�һ���ַ�, ����ұ��ַ�
            if (s2.test(val))                     // ��¼�ڶ��γ���, ����
                continue;
            if (s1.test(val))
            {
                // �ڶ��γ���
                ans.push_back(s.substr(i - 9, 10));
                s2.set(val);
            }
            else
                s1.set(val);
        }
        return ans;
    }
};