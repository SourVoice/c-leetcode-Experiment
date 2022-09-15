// 1818. ¾ø¶Ô²îÖµºÍ
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution
{
public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int mod = 1e9 + 7;
        long sumDist = 0;
        vector<int> num = nums1;
        for (int i = 0; i < n; i++)
            sumDist += abs(nums1[i] - nums2[i]);
        sort(begin(num), end(num));
        long sum = sumDist;
        for (int i = 0; i < n; i++)
        {
            int dist = abs(nums1[i] - nums2[i]);
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = ((r - l) >> 1) + l;
                if (num[mid] > nums2[i])
                    r = mid;
                else
                    l = mid + 1;
                dist = min(dist, abs(num[mid] - nums2[i]));
            }
            dist = min(dist, abs(num[l] - nums2[i]));
            sumDist = min(sumDist, sum - abs(nums1[i] - nums2[i]) + dist);
        }
        return sumDist % mod;
    }
};