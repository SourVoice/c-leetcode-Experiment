// 952. 按公因数计算最大组件大小
#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <map>
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
#include <sstream>
using namespace std;
// 并查集
class Unionfind
{
public:
    Unionfind(int capacity) : n(capacity), fathers(capacity, n), rank(capacity, 0)
    {
        iota(begin(fathers), end(fathers), 0);
        // iota(begin(rank), end(rank), 1);
    }
    int find(int u)
    {
        return u == fathers[u] ? u : fathers[u] = find(fathers[u]);
    }
    void join(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return;

        if (rank[rootU] == rank[rootV])
        {
            fathers[rootU] = rootV;
            // 此时以 rootV 为根结点的树的高度仅加了 1
            rank[rootV]++;
        }
        else if (rank[rootU] < rank[rootV])
        {
            fathers[rootU] = rootV;
            // 此时以 rootV 为根结点的树的高度不变
        }
        else
        {
            // 同理，此时以 rootU 为根结点的树的高度不变
            fathers[rootV] = rootU;
        }
    }

private:
    vector<int> fathers;
    // 以 i 为根结点的子树的高度（引入了路径压缩以后该定义并不准确）
    vector<int> rank;
    int n;
};
class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
        int n = nums.size();
        int max_e = *max_element(begin(nums), end(nums));
        Unionfind uf(max_e + 1);
        // 添加所有因数
        for (int i = 0; i < n; i++)
        {
            for (int j = 2; j * j <= nums[i]; j++)
            {
                if (nums[i] % j == 0)
                {
                    uf.join(nums[i], j);
                    uf.join(nums[i], nums[i] / j);
                }
            }
        }
        vector<int> ans(max_e + 1); // 因数为key
        for (auto &num : nums)
        {
            int fa = uf.find(num);
            ans[fa]++;
        }
        return *max_element(begin(ans), end(ans));
    }
};