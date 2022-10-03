// 1562. 查找大小为 M 的最新分组
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
// 超时
class Solution
{
public:
    int findLatestStep(vector<int> &arr, int m)
    {
        int n = arr.size();
        if (n == m)
            return m;
        string s = "";
        s.resize(n, '1');
        for (int i = n - 1; i >= 0; i--)
        {
            int k = arr[i] - 1;
            // left:
            int l = k - 1, llen = 0;
            while (l >= 0 && s[l] != '0')
                llen++, l--;
            // right
            int r = k + 1, rlen = 0;
            while (r <= n - 1 && s[r] != '0')
                rlen++, r++;
            if (rlen == m || llen == m)
                return i;
            s[k] = '0';
        }
        return -1;
    }
};

// 动态规划
class Solution
{
public:
    int findLatestStep(vector<int> &arr, int m)
    {
        int n = arr.size();
        if (n == m)
            return m;
        vector<int> len(n + 2, 0); // len[i]表示i两侧连续1数量
        int rec = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            int index = arr[i];
            int leftLen = len[index - 1];
            int rightLen = len[index + 1];
            if (leftLen == m || rightLen == m)
                rec = i;
            len[index - leftLen] = leftLen + rightLen + 1;  // index - leftLen处到另一端[index-leftLen, index + rightLen]的连续1数量
            len[index + rightLen] = leftLen + rightLen + 1; // index + rightLen处到另一端的连续1数量
        }
        return rec;
    }
};
// 哈希表;集合
// refernce: https://leetcode.cn/problems/find-latest-group-of-size-m/comments/ by  https://leetcode.cn/u/tukl_llu/
class Solution
{
public:
    int findLatestStep(vector<int> &arr, int m)
    {
        if (m == arr.size())
            return m;
        int left = 1;
        int right = arr.size();
        set<int> st; // set 默认按照升序排序, 方便我们找到更改元素左右两侧位置
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            st.insert(arr[i]);
            set<int>::iterator it = st.find(arr[i]);
            if (it == st.begin())
                left = 0;
            else
            {
                left = *(--it);
                it++;
            }
            if ((++it) == st.end())
            {
                right = arr.size() + 1;
            }
            else
            {
                right = *it;
            }
            if (abs(arr[i] - left - 1) == m || abs(right - arr[i] - 1) == m)
            {
                return i;
            }
        }
        return -1;
    }
};
// 下面为自己实现
class Solution
{
public:
    int findLatestStep(vector<int> &arr, int m)
    {
        int n = arr.size();
        if (m == n)
            return m;
        // 最上面方法(超时方法)的改进
        set<int> st; // set 默认按照升序排序, 方便我们找到更改元素左右两侧位置
        for (int i = n - 1; i >= 0; i--)
        {
            int index = arr[i] - 1;
            if (checkSideLen(st, index, n, m))
                return i;
        }
        return -1;
    }
    bool checkSideLen(set<int> &st, int index, int arrSize, int m)
    {
        st.insert(index);
        auto it = st.find(index);
        int leftLen = 0, rightLen = arrSize;
        if (it == st.begin())
            leftLen = index;
        else
            leftLen = index - *(--it) - 1, it++;
        if (++it == st.end())
            rightLen = arrSize - index - 1;
        else
            rightLen = *(it)-index - 1;
        return leftLen == m || rightLen == m;
    }
};
// TODO: 并查集