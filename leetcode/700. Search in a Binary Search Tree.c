/*BFSÖÐËÑË÷*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//in rescution way
struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (!root)
        return NULL;
    if (root->val == val)
        return root;
    return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
}
//in iterator way
int getTreeSize(struct TreeNode *root)
{
    if (!root)
        return 0;
    return getTreeSize(root->right) + getTreeSize(root->left) + 1;
}

struct TreeNode *searchBST(struct TreeNode *root, int val) //narmal way
{
    int treeSize = getTreeSize(root);
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * treeSize);
    int top = 0;
    while (top != 0 || root)
    {
        while (root)
        {
            if (root->val == val)
                return root;
            stack[top++] = root->left;
            root = root->left;
        }
        root = stack[--top];
        root = root->right;
    }
    return NULL;
}