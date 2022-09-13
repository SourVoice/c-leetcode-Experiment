// 658. 找到 K 个最接近的元素
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
// 优先队列
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
// 首尾双指针窗口
// https://leetcode.cn/problems/find-k-closest-elements/solution/zhao-dao-k-ge-zui-jie-jin-de-yuan-su-by-ekwtd/1721381
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        int l = 0, r = n - k;
        // 二分查找区间最左侧位置
        // x - arr[mid] 递增, arr[mid+k] - x递减
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                l = mid + 1;
            else
                r = mid; // 防止相等时错过一次判断
        }
        return vector<int>(begin(arr) + l, begin(arr) + l + k);
    }
};
/*
这道题可以看作求一个大小为 k 的区间，使区间内元素与 x 的距离的最大值最小，
这个最大值显然只与区间两端点有关，设区间左端点为 i 的话，就是要让max(x - arr[i], arr[i + k - 1] - x)最小。
然后注意到x - arr[i]递减，arr[i + k - 1] - x递增，两者的交点就是最小值，用二分可以找到这个交点。
*/