// 911. 在线选举
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
// stl 错误方法
class TopVotedCandidate
{
public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        map<int, int> votes;
        for (int i = 0; i < persons.size(); i++)
        {
            votes[persons[i]]++;
            mp[times[i]][persons[i]] = votes[persons[i]];
        }
    }

    int q(int t)
    {
        auto it = mp.upper_bound(t);
        it--;
        map<int, int> p2v = it->second;
        auto i = max_element(p2v.begin(), p2v.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
                             { return a.second < b.second; });
        return i->first;
    }

private:
    map<int, map<int, int>> mp; // key: time, val:(key:person, val:votes)
};
// 预处理 + 二分查找
class TopVotedCandidate
{
public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        map<int, int> mp; // 因为时间和选票相对应, 我们把每一刻的选票最多的人编号放在最后面
        int top = -1;
        mp[top] = -1;
        for (auto &p : persons)
        {
            mp[p]++;
            if (mp[p] >= mp[top])
            {
                top = p;
            }
            tops.emplace_back(top); // 记录此刻票数最多的候选人编号
        }
        this->times = times;
    }

    int q(int t)
    {
        auto it = upper_bound(times.begin(), times.end(), t); // 选出第一个不大于t出的时间
        --it;
        return tops[distance(begin(times), it)];
    }

private:
    vector<int> tops;
    vector<int> times;
};
/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */