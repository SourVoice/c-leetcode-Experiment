// 2049. 统计最高分的节点数目

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void helper(vector<int> &parents, int node)
    {
        if (parents[node] == -1)
            return;
        if (parents[node] == node)
            return;
        else
            helper(parents, parents[node]);
    }

    int countHighestScoreNodes(vector<int> &parents)
    {
        vector<int> sizes;
        int n = parents.size();
        int max_parent = *max_element(parents.begin(), parents.end());

        unordered_map<int, TreeNode *> nodes;

        for (int i = 0; i < n; i++)
        {
            TreeNode *node = new TreeNode();
            node->val = i;
            node->left = nullptr;
            node->right = nullptr;
            nodes[i] = node;
        }

        for (int i = 0; i < n; i++)
        {
            if (parents[i] == -1)
                continue;
            else if (parents[i])
            {
            }
        }
    }

private:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
    };
};

class Solution2
{
public:
    int countHighestScoreNodes(vector<int> &parents)
    {
        int n = parents.size();
        this->childern = vector<vector<int>>(n);
        for (int i = 0; i < n; i++)
        {
            int parent = parents[i]; // i的父节点
            if (parent != -1)
                childern[parent].push_back(i);
        }
        dfs(0);
        return count;
    }
    int dfs(int n)
    {
        int score = 1;
        int size = n - 1;
        for (auto elem : childern[n])
        {
            int t = dfs(elem);
            score *= t;
            size -= t;
        }
        if (n != 0)
        {
            score *= size;
        }

        if (score == maxScore)
        {
            count++;
        }
        else if (score > maxScore)
        {
            maxScore = score;
            count = 1;
        }

        return n - size;
    }

private:
    vector<vector<int>> childern;
    int count = 0;
    int maxScore = INT_MIN;
};