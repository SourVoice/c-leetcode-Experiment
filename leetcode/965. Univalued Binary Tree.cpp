// 965. µ¥Öµ¶þ²æÊ÷
#include <stack>
#include <iostream>
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
public:
    bool isUnivalTree(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return true;
        int val = root->val;
        stack<TreeNode *> s;
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (root->val != val)
                return false;
            root = root->right;
        }
        return true;
    }
};

//µÝ¹é
class Solution
{
private:
    int _val;

public:
    bool isUnivalTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        _val = root->val;
        return helper(root);
    }
    bool helper(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (root->val != _val)
            return false;
        return helper(root->left) && helper(root->right);
    }
};