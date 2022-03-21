// 606. 根据二叉树创建字符串
#include <string>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
class Solution
{
    string ans;

public:
    string tree2str(TreeNode *root)
    {
        if (root)
        {
            ans += to_string(root->val);
            if (root->left || root->right)
            {
                ans += "(";
                tree2str(root->left);
                ans += ")";
            }
            if (root->right)
            {
                ans += "(";
                tree2str(root->right);
                ans += ")";
            }
        }
    }
};

class Solution2
{
    string ans;

public:
    string tree2str(TreeNode *root)
    {
        stack<TreeNode *> st;

        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            while (node)
            {
                ans += to_string(node->val);
                if (node->left)
                    ans += "(";
                node = node->left;
                st.push(node);
            }
            st.pop();
            node = st.top();
            ans += ")";
            if (node->right)
            {
                st.push(node->right);
            }
        }
        return ans;
    }
};
