// 811. 子域名访问计数
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <numeric>
#include <list>
#include <string>
using namespace std;
// stl, 字符串处理
class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, unsigned long> mp;
        for (auto &e : cpdomains)
        {
            auto it_blank = find(e.begin(), e.end(), ' ');
            int times = stoi(e.substr(0, it_blank - e.begin()));
            string domain = e.substr(it_blank - e.begin() + 1, e.end() - it_blank);
            mp[domain] += times;
            int pos = 0;
            while ((pos = domain.find(".")) != string::npos)
            {
                domain.erase(0, pos + 1);
                mp[domain] += times;
            }
        }

        vector<string> ans;
        for (auto &[domain, times] : mp)
            ans.emplace_back(to_string(times) + " " + domain);
        return ans;
    }
};
// sstream
class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, unsigned long> mp;
        for (auto &e : cpdomains)
        {
            stringstream ss(e);
            string t, domain;
            ss >> t >> domain;
            int times = stoi(t);
            mp[domain] += times;
            int pos = 0;
            while ((pos = domain.find(".")) != string::npos)
                domain.erase(0, pos + 1), mp[domain] += times;
        }
        vector<string> ans;
        for (auto &[domain, times] : mp)
            ans.emplace_back(to_string(times) + " " + domain);
        return ans;
    }
};
