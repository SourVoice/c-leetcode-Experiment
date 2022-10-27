// 236. 二叉树的最近公共祖先
#include <string>
#include <stack>
#include <bitset>
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
#define N 1000
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
// 递归
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == nullptr || root == p || root == q) // 返回子树中的查找结果
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);   // 在左子树中查找p, q
        TreeNode *right = lowestCommonAncestor(root->right, p, q); // 在右子树中查找p, q
        if (left && right)                                         // p, q位于不同子树
            return root;
        else if (!right)
            return left;
        else if (!left)
            return right;
        return nullptr;
    }
};