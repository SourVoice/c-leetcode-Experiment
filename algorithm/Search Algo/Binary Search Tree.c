// Binary Search Tree and basic operations
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
// inorder traversal to get the increasing rank
void inorderTraverasl(struct TreeNode *root)
{
    if (!root)
        return;
    inorderTraverasl(root->left);
    printf("%d ", root->key);
    inorderTraverasl(root->right);
}
// return the min Node when a node has two children
struct TreeNode *minValNode(struct TreeNode *root)
{
    struct TreeNode *cur = root;

    while (cur && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}
// Given a binary search tree
// and a key, this function
// deletes the key and
// returns the new root
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
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

// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct TreeNode *root = NULL;
    root = insertElem(root, 50);
    root = insertElem(root, 30);
    root = insertElem(root, 20);
    root = insertElem(root, 40);
    root = insertElem(root, 70);
    root = insertElem(root, 60);
    root = insertElem(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorderTraverasl(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorderTraverasl(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorderTraverasl(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorderTraverasl(root);

    return 0;
}