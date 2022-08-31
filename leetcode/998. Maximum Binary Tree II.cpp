// 998. 最大二叉树 II
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
// 递归
class Solution
{
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (!root)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if (val > root->val)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        else
        {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
        return nullptr;
    }
};
// 模拟
class Solution
{
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        while (cur)
        {
            if (val > cur->val)
            {
                if (prev == nullptr) //一开始根节点就小于val
                    return new TreeNode(val, root, nullptr);
                TreeNode *node = new TreeNode(val, cur, nullptr);
                prev->right = node;
                return root;
            }
            else
            {
                prev = cur;
                cur = cur->right;
            }
        }
        prev->right = new TreeNode(val, nullptr, nullptr);
        return root;
    }
};