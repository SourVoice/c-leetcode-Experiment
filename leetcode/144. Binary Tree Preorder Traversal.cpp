// 144. 二叉树的前序遍历
#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> sk;
        vector<int> ans;
        while (root || !sk.empty())
        {
            while (root)
            {
                ans.push_back(root->val);
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            root = root->right;
        }
        return ans;
    }
};