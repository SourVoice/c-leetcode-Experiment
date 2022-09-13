// 658. �ҵ� K ����ӽ���Ԫ��
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
using namespace std;
// ���ȶ���
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) -> bool
        { return a.second < b.second; }; // pair<index, diff>
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        vector<int> ret;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int diff = abs(arr[i] - x);
            if (ret.size() < k)
            {
                ret.push_back(i);
                q.push(make_pair(i, diff));
            }
            else if (ret.size() >= k && diff < q.top().second)
            {
                ret.erase(std::remove(begin(ret), end(ret), q.top().first), end(ret));
                ret.push_back(i);
                q.pop();
                q.push(make_pair(i, diff));
            }
        }
        for (auto &num : ret)
        {
            num = arr[num];
        }
        return ret;
    }
};
// ��β˫ָ�봰��
// https://leetcode.cn/problems/find-k-closest-elements/solution/zhao-dao-k-ge-zui-jie-jin-de-yuan-su-by-ekwtd/1721381
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        int l = 0, r = n - k;
        // ���ֲ������������λ��
        // x - arr[mid] ����, arr[mid+k] - x�ݼ�
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                l = mid + 1;
            else
                r = mid; // ��ֹ���ʱ���һ���ж�
        }
        return vector<int>(begin(arr) + l, begin(arr) + l + k);
    }
};
/*
�������Կ�����һ����СΪ k �����䣬ʹ������Ԫ���� x �ľ�������ֵ��С��
������ֵ��Ȼֻ���������˵��йأ���������˵�Ϊ i �Ļ�������Ҫ��max(x - arr[i], arr[i + k - 1] - x)��С��
Ȼ��ע�⵽x - arr[i]�ݼ���arr[i + k - 1] - x���������ߵĽ��������Сֵ���ö��ֿ����ҵ�������㡣
*/