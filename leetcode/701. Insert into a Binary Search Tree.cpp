// 701. 二叉搜索树中的插入操作
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
// 递归
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        helper(root, val);
        return root;
    }
    TreeNode *helper(TreeNode *&root, int val) // 传引用否则不能更改原二叉树
    {
        if (!root)
        {
            TreeNode *node = new TreeNode;
            node->left = nullptr;
            node->right = nullptr;
            node->val = val;
            root = node;
            return node;
        }
        if (root->val > val)
            return helper(root->left, val);
        return helper(root->right, val);
    }
};
// TODO: 非递归, 迭代
