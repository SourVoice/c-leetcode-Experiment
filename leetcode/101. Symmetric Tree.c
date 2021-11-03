/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define bool int
#define false 0
#define true 1

bool mirror(struct TreeNode *p, struct TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
    {
        return false;
    }
    if (p->val == q->val)
        return mirror(p->left, q->right) && mirror(p->right, q->left);
    return false;
}

bool isSymmetric(struct TreeNode *root)
{
    return mirror(root, root);
}