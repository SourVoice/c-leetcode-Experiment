// 429. N ²æÊ÷µÄ²ãÐò±éÀú
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// dfs
class Solution
{
private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> levelOrder(Node *root)
    {
        dfs(root, 0);
        return ans;
    }
    void dfs(Node *root, int level)
    {
        if (root == NULL)
            return;
        if (ans.size() < level + 1)
            ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        for (auto e : root->children)
            dfs(e, level + 1);
    }
};

class Solution2
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == NULL)
            return {};
        queue<Node *> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto e : node->children)
                    q.push(e);
            }
            ans.push_back(level);
        }
        return ans;
    }
};