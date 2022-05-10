// 95. 不同的二叉搜索树 II
#include <vector>

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

//回溯;递归
class Solution
{
public:
    vector<TreeNode *> helper(int left, int right)
    {
        if (left > right)
        {
            return {nullptr};
        }
        vector<TreeNode *> ret;
        for (int i = left; i <= right; i++)
        {
            vector<TreeNode *> leftNodes = helper(left, i - 1);   // get all left nodes from left to i-1
            vector<TreeNode *> rightNodes = helper(i + 1, right); // get all right nodes from i+1 to right
            //利用BST特性,BST的左右子树均为BST
            for (auto leftNode : leftNodes) // the BST's number is leftNode.size() * rightNode.size()
            {
                for (auto rightNode : rightNodes)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }

private:
    vector<TreeNode *> ret;
};