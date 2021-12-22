#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int key;
    struct TreeNode *left, *right;
};
// search key in Binary Search Tree from Root
struct TreeNode *searchTree(struct TreeNode *root, int key)
{
    if (!root || root->key == key)
        return root;
    if (key < root->key)
        return searchTree(root->left, key);
    else
        return searchTree(root->right, key);
}
// creat a newNode for the Binary Search Tree with key
// and return it
struct TreeNode *addNewNode(int key)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode *insertElem(struct TreeNode *node, int key)
{
    // find a
    if (!node)
        return addNewNode(key);
    if (key < node->key)
        node->left = insertElem(node->left, key);
    else if (key > node->key)
        node->right = insertElem(node->right, key);

    return node;
}
int TreeHeight(struct TreeNode *root)
{

    if (!root)
        return -1;
    int leftHeight = TreeHeight(root->left);
    int righHeight = TreeHeight(root->right);
    if (leftHeight > righHeight)
        return leftHeight + 1;
    else
        return righHeight + 1;
}
void inorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}