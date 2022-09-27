// 981. 基于时间的键值存储
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <map>
using namespace std;
class TimeMap
{
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        auto it = upper_bound(begin(mp[key]), end(mp[key]), timestamp, [&](const int val, const auto &a)
                              { return val < a.second; });
        return it == mp[key].begin() ? "" : (*(it - 1)).first;
    }

private:
    map<string, vector<pair<string, int>>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */