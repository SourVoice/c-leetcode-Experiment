// 373. 查找和最小的 K 对数字

//优先队列
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;
class Soultion
{
public:
    bool flag = true;
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        if (n > m)
        {
            swap(nums1, nums2);
            swap(m, n);
            flag = false;
        }

        auto cmp = [&](const auto &a, const auto &b)
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < min(n, k); i++)
        {
            q.push({i, 0});
        }
        while (ans.size() < k and q.size())
        {
            auto [a, b] = q.top();
            q.pop();
            flag ? ans.push_back({nums1[a], nums2[b]}) : ans.push_back({nums2[b], nums1[a]});
            if (b + 1 < m)
                q.push({a, b + 1});
        }
        return ans;
    }
};
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        set<tuple<int, int, int>> st; //优先队列
        st.insert({nums1[0] + nums2[0], 0, 0});
        vector<vector<int>> ans;
        while (ans.size() < k && st.size())
        {
            auto [_, a, b] = *st.begin();
            st.erase(st.begin());
            ans.push_back({nums1[a], nums2[b]});
            if (a + 1 < len1)
                st.insert({nums1[a + 1] + nums2[b], a + 1, b});
            if (b + 1 < len2)
                st.insert({nums1[a] + nums2[b + 1], a, b + 1});
        }
        return ans;
    }
};
