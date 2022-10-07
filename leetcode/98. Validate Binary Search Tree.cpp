// 98. 验证二叉搜索树
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
// 递归, 中序遍历, 中序二叉搜索树一定是增序
class Solution
{
    long pre = LONG_MIN;

public:
    bool isValidBST(TreeNode *root)
    {
        return helper(root);
    }
    bool helper(TreeNode *root)
    {
        if (!root)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (root->val <= pre)
            return false;
        pre = root->val;
        if (!isValidBST(root->right))
            return false;
        return true;
    }
};
