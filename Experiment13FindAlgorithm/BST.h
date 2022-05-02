#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int key;
    struct TreeNode *left, *right;
};

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
struct TreeNode *creatBST(int *data, int numsSize)
{
    struct TreeNode *root;
    for (int i = 0; i < numsSize; i++)
        root = insertElem(root, data[i]);
    return root;
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
void inorderTraverasl(struct TreeNode *root)
{
    if (!root)
        return;
    inorderTraverasl(root->left);
    printf("%d ", root->key);
    inorderTraverasl(root->right);
}
// return the min Node
struct TreeNode *minValNode(struct TreeNode *root)
{
    struct TreeNode *cur = root;

    while (cur && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

// delet by key
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    if (!root)
        return root;
    if (key < root->key)
        return deleteNode(root->left, key);
    else if (key > root->key)
        return deleteNode(root->right, key);
    else
    {
        if (root->left == NULL) // isLeaf Node
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) // isLeaf Node
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct TreeNode *temp = minValNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
// search key in Binary Search Tree from Root
struct TreeNode *searchTree(struct TreeNode *root, int key)
{
    if (!root || root->key == key)
    {
        if (root->key == key)
        {
            int height = TreeHeight(root);
            printf("%d\n", height);
        }
        return root;
    }
    if (key < root->key)
    {
        printf("L");
        return searchTree(root->left, key);
    }
    else
    {
        printf("R");
        return searchTree(root->right, key);
    }
}