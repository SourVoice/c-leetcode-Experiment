//面试题 04.06. Successor LCCI
#include <stack>
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//中序遍历, 保存前一个遍历的节点
class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *res = nullptr;
        TreeNode *prev = nullptr;
        inorderTraversal(root, res, p, prev);
        return res;
    }
    TreeNode *inorderTraversal(TreeNode *root, TreeNode *&res, TreeNode *p, TreeNode *&prev)
    {
        if (!root || !prev || !res)
            return nullptr;
        inorderTraversal(root->left, res, p, prev);
        if (prev == p) // if last visited is p, then this is the successor
            res = root;
        prev = root;
        inorderTraversal(root->right, res, p, prev);
    }
};

//中序遍历, 迭代
class Solution2
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *res = nullptr;
        TreeNode *prev = nullptr;
        stack<TreeNode *> s;
        while (!s.empty() || root)
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (prev == p)
                res = root;
            prev = root;
            root = root->right;
        }
        return res;
    }
};

// 利用二叉搜索树的性质
class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *ans = nullptr;
        TreeNode *node = root;
        if (p->right)
        {
            ans = p->right;
            while (ans->left)
                ans = ans->left;
            return ans;
        }
        while (node)
        {
            if (node->val > p->val)
            {
                ans = node;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return ans;
    }
};