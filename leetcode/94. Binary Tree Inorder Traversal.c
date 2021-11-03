/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void inorder(struct TreeNode *root, int *returnSize, int *a) /*中序遍历二叉树*/
{
    if (!root)
        return;
    inorder(root->left, returnSize, a);

    a[(*returnSize)++] = root->val;
    inorder(root->right, returnSize, a);
}
int size(struct TreeNode *root) /*求二叉树数据个数*/
{
    if (!root)
        return 0;
    return size(root->left) + size(root->right) + 1;
}
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int treesize = size(root);
    int *a = (int *)malloc(treesize * sizeof(int));
    memset(a, 0, treesize * sizeof(int));
    *returnSize = 0;
    inorder(root, returnSize, a);
    return a;
}
struct TreeNode *newNode(int val)
{

    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int main()
{
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int *a;
    int *returnSize;
    inorderTraversal(root, returnSize);
}