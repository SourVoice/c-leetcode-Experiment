#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;
//���仮��, ̰��
//��С���ȶ���
class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        auto cmp = [](const int &a, const int &b) -> bool
        {
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp); //���ȶ��д洢ÿһ�������ʱ��
        int cnt = 0;
        for (auto &vec : intervals)
        {
            if (!q.empty() && q.top() < vec[0])
                q.pop();
            else
                cnt++;
            q.push(vec[1]);
        }
        return cnt;
    }
};