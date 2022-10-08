// 870. 优势洗牌
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
// 超时
class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        sort(begin(nums1), end(nums1));
        int n = nums1.size();
        vector<int> sequence(n, 0);
        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(begin(nums1), end(nums1), nums2[i]);
            if (it != nums1.end())
            {
                sequence[i] = *it;
                nums1.erase(it);
            }
            else
            {
                sequence[i] = nums1[0];
                nums1.erase(begin(nums1));
            }
        }
        return sequence;
    }
};
// 优化
class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        multiset st(begin(nums1), end(nums1));
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            auto it = st.upper_bound(nums2[i]);
            if (it != st.end())
            {
                nums2[i] = *it;
                st.erase(it);
            }
            else
            {
                nums2[i] = *begin(st);
                st.erase(begin(st));
            }
        }
        return nums2;
    }
};
