// 47. ȫ���� II
#include <string>
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
using namespace std;
// ����;�ݹ�;���ϼ�¼
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> gen;
        vector<int> visited(n, 0);
        sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size(); i++)
            dfs(nums, visited, ans, gen, i);
        return ans;
    }
    void dfs(vector<int> &nums, vector<int> &visited, vector<vector<int>> &ans, vector<int> &gen, int j)
    {
        if (gen.size() == nums.size())
        {
            if (!st.count(gen))
            {
                ans.push_back(gen);
                st.emplace(gen);
                return;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                gen.push_back(nums[i]);
                visited[i] = 1;
                dfs(nums, visited, ans, gen, i + 1);
                gen.pop_back();
                visited[i] = 0;
            }
        }
    }

private:
    set<vector<int>> st;
};
// �Ż�
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> gen;
        vector<int> visited(n, 0);
        sort(begin(nums), end(nums));
        dfs(nums, visited, ans, gen);
        return ans;
    }
    void dfs(vector<int> &nums, vector<int> &visited, vector<vector<int>> &ans, vector<int> &gen)
    {
        if (gen.size() == nums.size())
        {
            ans.push_back(gen);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) // ʵ��ͬ���֦, ��nums[i - 1]��ͷ��Ԫ�ص������Ѿ��
                continue;
            if (!visited[i])
            {
                gen.push_back(nums[i]);
                visited[i] = 1;
                dfs(nums, visited, ans, gen);
                gen.pop_back();
                visited[i] = 0;
            }
        }
    }

private:
    set<vector<int>> st;
};