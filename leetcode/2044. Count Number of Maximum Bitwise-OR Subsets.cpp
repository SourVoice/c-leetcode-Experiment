// 2044. 统计按位或能得到最大值的子集数目

#include <vector>
#include <set>
#include <iostream>
#include <functional>
using namespace std;

//暴力超时
class Solution
{
public:
    void subsetsTill(vector<int> &subset, set<vector<int>> &res, vector<int> &A, int index)
    {
        if (res.find(subset) != res.end())
            return;
        else
        {
            res.insert(subset);
        }

        for (int i = index; i < A.size(); i++)
        {
            subset.push_back(A[i]);

            subsetsTill(subset, res, A, index + 1);

            subset.pop_back();
        }
        return;
    }

    set<vector<int>> calculate(vector<int> &A)
    {
        set<vector<int>> res;
        vector<int> subset;
        subsetsTill(subset, res, A, 0);
        return res;
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        int max = 0;
        for (auto num : nums)
        {
            max |= num;
        }
        set<vector<int>> subsets = calculate(nums);
        int cnt = 0;
        for (auto e : subsets)
        {
            int sum = 0;
            for (auto i = e.begin(); i != e.end(); ++i)
                std::cout << *i << ' ';
            cout << endl;
            for (auto i : e)
            {
                sum |= i;
            }
            if (sum == max)
                cnt++;
        }
        int ans = cnt;
        return ans;
    }
};

//二进制枚举
class Solution2
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int max = 0;
        for (auto num : nums)
        {
            max |= num;
        }
        int ans = 0;
        int n = nums.size();
        int times = (1 << n) - 1; //子集数
        for (int i = 0; i < times; i++)
        {
            int sum = 0;
            // 假设当前子集状态为 statestate，statestate 为一个仅考虑低 nn 位的二进制数，
            //当第 k 位为 1，代表 nums[k] 参与到当前的按位或运算，当第 k 位为 0，代表 nums[i] 不参与到当前的按位或运算。
            for (int j = 0; j < n; j++)
            {
                if ((i & (1 << j))) //第j位不为0
                {
                    sum |= nums[j];
                }
            }
            if (sum == max)
                ans++;
        }
        return ans;
    }
};

//状态压缩,最大值一定是全部与操纵
class Solution3
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        int max = 0;
        for (auto num : nums)
        {
            max |= num;
        }
        int times = (1 << n) - 1;
        int ans = 1;
        for (int i = 0; i < times; i++)
        {
            if (calculateOr(nums, i) == max)
                ans++;
        }
        return ans;
    }

    int calculateOr(vector<int> &nums, int index)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) //二进制枚举子集
        {
            if ((index & (1 << i)) != 0)
            {
                res |= nums[i];
            }
        }
        return res;
    }
};

// dfs
class Solution4
{

    int max = 0;
    int ans = 1;
    int n = 0;

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        n = nums.size();
        dfs(0, 0, nums);
        return ans;
    }
    void dfs(int No, int val, vector<int> &nums) // No 是当前搜索到的第几位,val是当前求和
    {
        if (No == n)
        {
            if (val == max)
                ans++;
            else if (val > max)
            {
                ans = 1;
                max = val;
            }
            return;
        }
        dfs(No + 1, val | nums[No], nums);
        dfs(No + 1, val, nums);
    }
};

// stl function dfs
class Solution5
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        int max = 0, ans = 0;
        function<void(int, int)> dfs = [&](int u, int val) -> void
        {
            if (u == n)
            {
                if (val == max)
                    ans++;
                else if (val > max)
                {
                    ans = 1;
                    max = val;
                }
            }
            dfs(u + 1, val | nums[u]);
            dfs(u + 1, val);
        };
        dfs(0, 0);
        return ans;
    }
};