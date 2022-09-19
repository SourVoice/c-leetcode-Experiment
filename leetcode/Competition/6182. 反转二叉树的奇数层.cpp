// 6182. 反转二叉树的奇数层
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
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
    void helper(TreeNode *left, TreeNode *right, int depth)
    {
        if (!left || !right)
            return;
        if (depth & 1)
        {
            swap(left->val, right->val);
        }
        helper(left->left, right->right, depth + 1);
        helper(left->right, right->left, depth + 1);
    }
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        helper(root->left, root->right, 1);
        return root;
    }
};