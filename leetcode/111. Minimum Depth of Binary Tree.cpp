// 111. 二叉树的最小深度
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
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        helper(root, 1);
        return minD;
    }
    int helper(TreeNode *root, int n)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
        {
            minD = min(minD, n);
        }
        return helper(root->left, n + 1) + helper(root->right, n + 1);
    }

private:
    int minD = INT_MAX;
};