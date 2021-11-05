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
#include <math.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void inorderRecursion(struct TreeNode *root, int *returnSize, int *a) /*中序遍历二叉树(递归法)*/
{
    if (!root)
        return;
    inorderRecursion(root->left, returnSize, a);
    a[(*returnSize)++] = root->val;
    inorderRecursion(root->right, returnSize, a);
}
int size(struct TreeNode *root) //求二叉树数据个数
{
    if (!root)
        return 0;
    return size(root->left) + size(root->right) + 1;
}
int *inorderTraversal(struct TreeNode *root, int *returnSize) //遍厤内容返回a數組
{
    int treesize = size(root);
    int *a = (int *)malloc(treesize * sizeof(int));
    memset(a, 0, treesize * sizeof(int));
    *returnSize = 0;
    inorderRecursion(root, returnSize, a);
    return a;
}
int *inorderTraversal_Recursive(struct TreeNode *root, int *returnSize) //迭代法遍歷,返回到數組
{
    int treesize = size(root);
    int *a = (int *)malloc(treesize * sizeof(int));
    memset(a, 0, treesize * sizeof(int));
    *returnSize = 0;

    struct TreeNode **stack = (struct TreeNode **)malloc(treesize * sizeof(struct TreeNode *));
    int top = 0;
    while (root != NULL || top != 0)
    {
        while (root != NULL) //模拟递归入栈过程
        {
            stack[top++] = root;
            root = root->left;
        }
        root = stack[--top];
        a[(*returnSize)++] = root->val;
        root = root->right;
    }
    return a;
}
struct TreeNode *newNode(int val)
{

    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int main()
{

    //init the tree
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int *a;
    int *returnSize;
    a = inorderTraversal(root, returnSize);
}