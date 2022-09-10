// 669. 修剪二叉搜索树
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
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
class Solution
{
    TreeNode *help(TreeNode *root, int low, int high)
    {
        if (!root)
            return nullptr;
        if (root->val < low)
            return help(root->right, low, high);
        if (root->val > high)
            return help(root->left, low, high);
        //处理正常节点
        root->left = help(root->left, low, high);
        root->right = help(root->right, low, high);
        return root;
    }

public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        return help(root, low, high);
    }
};