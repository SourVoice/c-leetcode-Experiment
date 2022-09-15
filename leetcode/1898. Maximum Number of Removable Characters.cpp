// 1898. 可移除字符的最大数目
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution
{
public:
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int l = 1, r = removable.size();
        auto check = [&](string s, string p, vector<int> &removable, int k) -> bool
        {
            for (int i = 0; i < k; i++)
                s[removable[i]] = 0; //根据子序列定义, 我们可以设置一个无意义字符
            // if(k==1) cout<<s<<endl;
            int p_pos = 0, s_pos = 0;
            while (p_pos < p.size() && s_pos < s.size())
            {
                if (s[s_pos] == p[p_pos])
                    p_pos++;
                s_pos++;
            }
            return p_pos == p.size();
        };
        int ret = 0;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(s, p, removable, mid))
            {
                l = mid + 1;
                // if(mid==1) cout<<l<<" "<<r<<endl;
                ret = max(ret, mid);
            }
            else
                r = mid;
        }
        if (check(s, p, removable, l))
            return l;
        return ret;
    }
};
