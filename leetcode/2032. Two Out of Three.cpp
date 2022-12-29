// 2032. ���������������г��ֵ�ֵ
#include <string>
#include <functional>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
// stl����
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        set<int> st1, st2, st3;
        for (auto num : nums1)
            st1.emplace(num);
        for (auto num : nums2)
            st2.emplace(num);
        for (auto num : nums3)
            st3.emplace(num);
        vector<int> intersection_12, intersection_13, intersection_23;
        set_intersection(begin(st1), end(st1), begin(st2), end(st2), back_inserter(intersection_12));
        set_intersection(begin(st1), end(st1), begin(st3), end(st3), back_inserter(intersection_13));
        set_intersection(begin(st3), end(st3), begin(st2), end(st2), back_inserter(intersection_23));
        vector<int> union_1;
        vector<int> ret;
        set_union(begin(intersection_12), end(intersection_12), begin(intersection_13), end(intersection_13), back_inserter(union_1));
        set_union(begin(union_1), end(union_1), begin(intersection_23), end(intersection_23), back_inserter(ret));
        return ret;
    }
};
// ״̬ѹ��; ѹ����128λ
// ���ݷ�ΧΪ0-100
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        auto getSum = [](auto &&v)
        { return accumulate(v.begin(), v.end(), __int128{}, [](auto a, auto b)
                            { return a | (__int128(1) << b); }); }; // gcc 4.8+��֧��__int128����, ����Ҫ����������λд������
        auto s1 = getSum(nums1), s2 = getSum(nums2), s3 = getSum(nums3);
        auto s = (s1 & s2) | (s1 & s3) | (s2 & s3);
        nums1.clear();
        for (int i = 1; s >>= 1; i++)
        {
            if (s & 1)
                nums1.push_back(i);
        }
        return nums1;
    }
};
// ��ϣ����

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        // ʹ�ù�ϣ���¼�������ĸ�������, ���ö������еĵ���λ
        unordered_map<int, int> mp;
        for (auto &i : nums1)
        {
            mp[i] = 1;
        }
        for (auto &i : nums2)
        {
            mp[i] |= 2;
        }
        for (auto &i : nums3)
        {
            mp[i] |= 4;
        }
        vector<int> ret;
        for (auto [k, v] : mp)
        {
            if (v & (v - 1)) // �ж϶�������1�������Ƿ����1
                ret.push_back(k);
        }
        return ret;
    }
};