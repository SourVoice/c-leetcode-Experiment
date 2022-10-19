// 187. 重复的DNA序列
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
// 哈希表+集合
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
// 位运算存储状态
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        // 使用00, 01, 11, 10表示 A, G, T, C
        // 使用20个bit表示10个序列
        unordered_map<char, int> mp{{'A', 0}, {'G', 1}, {'T', 2}, {'C', 3}};
        vector<string> ans;
        bitset<1 << 20> s1, s2;
        int val = 0;
        // 取出前十个
        for (int i = 0; i < 10; i++)
            val = (val << 2) | mp[s[i]];
        s1.set(val);
        int mask = (1 << 20) - 1; // 20个1
        for (int i = 10; i < s.size(); i++)
        {
            val = ((val << 2) & mask) | mp[s[i]]; // 去掉左边第一个字符, 添加右边字符
            if (s2.test(val))                     // 记录第二次出现, 跳过
                continue;
            if (s1.test(val))
            {
                // 第二次出现
                ans.push_back(s.substr(i - 9, 10));
                s2.set(val);
            }
            else
                s1.set(val);
        }
        return ans;
    }
};