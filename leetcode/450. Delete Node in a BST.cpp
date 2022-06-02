// 450. 删除二叉搜索树中的节点

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

// 递归
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val == key)
        {
            if (root->left == root->right)
                return nullptr;
            if (root->left && root->right == nullptr)
                return root->left;
            if (root->right && root->left == nullptr)
                return root->right;
            if (root->left && root->right)
            {
                TreeNode *cur = root->right;
                while (cur->left)
                    cur = cur->left;
                root->right = deleteNode(root->right, cur->val);
                cur->left = root->left;
                cur->right = root->right;
                return cur;
            }
        }
        return root;
    }
};

//迭代
class Solution2
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
    }
};