// 222. 完全二叉树的节点个数
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while (left)
            left = left->left, leftDepth++;
        while (right)
            right = right->right, rightDepth++;
        if (leftDepth == rightDepth)
            return (2 << leftDepth) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};