// 952. ��������������������С
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
// ���鼯
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
            // ��ʱ�� rootV Ϊ���������ĸ߶Ƚ����� 1
            rank[rootV]++;
        }
        else if (rank[rootU] < rank[rootV])
        {
            fathers[rootU] = rootV;
            // ��ʱ�� rootV Ϊ���������ĸ߶Ȳ���
        }
        else
        {
            // ͬ����ʱ�� rootU Ϊ���������ĸ߶Ȳ���
            fathers[rootV] = rootU;
        }
    }

private:
    vector<int> fathers;
    // �� i Ϊ�����������ĸ߶ȣ�������·��ѹ���Ժ�ö��岢��׼ȷ��
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
        // �����������
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
        vector<int> ans(max_e + 1); // ����Ϊkey
        for (auto &num : nums)
        {
            int fa = uf.find(num);
            ans[fa]++;
        }
        return *max_element(begin(ans), end(ans));
    }
};