// 911. ����ѡ��
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
// stl ���󷽷�
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
// Ԥ���� + ���ֲ���
class TopVotedCandidate
{
public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        map<int, int> mp; // ��Ϊʱ���ѡƱ���Ӧ, ���ǰ�ÿһ�̵�ѡƱ�����˱�ŷ��������
        int top = -1;
        mp[top] = -1;
        for (auto &p : persons)
        {
            mp[p]++;
            if (mp[p] >= mp[top])
            {
                top = p;
            }
            tops.emplace_back(top); // ��¼�˿�Ʊ�����ĺ�ѡ�˱��
        }
        this->times = times;
    }

    int q(int t)
    {
        auto it = upper_bound(times.begin(), times.end(), t); // ѡ����һ��������t����ʱ��
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