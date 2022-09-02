// 687. 最长同值路径
#include <stack>
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
    int helper(TreeNode *root, int &maxLen)
    {
        if (!root)
            return 0;
        int left = helper(root->left, maxLen);
        int right = helper(root->right, maxLen);
        if (!root->left || root->left->val != root->val)
        {
            left = 0;
        }
        if (!root->right || root->right->val != root->val)
        {
            right = 0;
        }
        maxLen = std::max(maxLen, left + right);
        return max(left, right) + 1;
    }

    int longestUnivaluePath(TreeNode *root)
    {
        int pathLen = 0;
        helper(root, pathLen);
        return pathLen;
    }
};