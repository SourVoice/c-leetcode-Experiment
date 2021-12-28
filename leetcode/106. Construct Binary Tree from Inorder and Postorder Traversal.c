#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a, b) a > b ? a : b
struct TreeNode *
helper(int *inorder, int *postorder, int len)
{
    if (!len)
        return NULL;
    char ch = postorder[len - 1];
    int i = 0;
    while ((inorder[i] != ch) && i < len)
        i++;
    int leftLen = i;            // leftLen from 0 to i
    int rightLen = len - i - 1; // rightLen from i to last
    struct TreeNode *Node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    Node->val = inorder[i];
    Node->left = helper(inorder, postorder, leftLen);
    Node->right = helper(inorder + i + 1, postorder + i + 1, rightLen);
    return Node;
}
struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
    struct TreeNode *Tree = helper(inorder, postorder, strlen(inorder));
    return Tree;
}