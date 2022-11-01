// 215. �����еĵ�K�����Ԫ��
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <deque>
#include <queue>
using namespace std;
// ���ȶ���
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int, vector<int>, decltype(greater<int>())> pq;
        int cnt = 0;
        for (auto &num : nums)
            pq.push(num);
        for (int i = k; i < n; i++)
            pq.pop();
        return pq.top();
    }
};