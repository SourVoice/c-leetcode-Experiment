// 1022. 从根到叶的二进制数之和
#include <vector>
#include <deque>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归;bfs;dfs
class Solution
{
public:
    void helper(TreeNode *root, vector<int> rec)
    {
        if (!root)
        {
            return;
        }
        rec.push_back(root->val);
        if (!root->left && !root->right)
        {
            int tmp = 0;
            for (int i = 0; i < rec.size(); i++)
            {
                tmp += rec[i] * pow(2.0, rec.size() - 1 - i);
            }
            ans += tmp;
            return;
        }
        helper(root->left, rec);
        helper(root->right, rec);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        vector<int> rec;
        // helper(root, rec);
        deque<TreeNode *> q;
        q.push_back(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop_front();
            if (node->left)
            {
                node->left->val += node->val * 2;
                q.push_back(node->left);
            }
            if (node->right)
            {
                node->right->val += node->val * 2;
                q.push_back(node->right);
            }
            if (!node->left && !node->right)
            {
                ans += node->val;
            }
        }
        return ans;
    }

private:
    int ans = 0;
};

//后序遍历
class Solution2
{
public:
    void helper(TreeNode *root, int sum)
    {
        if (!root)
            return;
        sum = sum * 2 + root->val;
        if (!root->left && !root->right)
        {
            ans += sum;
            return;
        }
        helper(root->left, sum);
        helper(root->right, sum);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        helper(root, 0);
        return ans;
    }

private:
    int ans = 0;
};

class Solution3
{
public:
    int sumRootToLeaf(TreeNode *root)
    {
        TreeNode *pre = nullptr;
        deque<TreeNode *> q;
        int ans = 0, sum = 0;
        while (root || !q.empty())
        {
            while (root) // -->
            {
                sum = sum * 2 + root->val;
                q.push_back(root);
                root = root->left;
            }
            root = q.back();
            // 分支遍历完或者右支未遍历
            if (!root->left && !root->right) //分支遍历完
            {
                ans += sum;
                sum /= 2; // 去刚加的一位
                pre = root;
                q.pop_back();
                root = nullptr;
            }
            else if (root->right == pre || root->right == nullptr) //右支已经遍历或者为空
            {
                pre = root;
                q.pop_back();
                sum /= 2; //这里除二是因为选择右支时又走了一次while(root) -->
                root = nullptr;
            }
            else
            {
                root = root->right;
            }
        }
        return ans;
    }
};