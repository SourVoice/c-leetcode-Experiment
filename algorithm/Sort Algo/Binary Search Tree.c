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
struct TreeNode *deletNode(struct TreeNode *root, int key)
{
    if (!root)
        return root;
    if (key < root->key)
        return deletNode(root->left, key);
    else if (key > root->key)
        return deletNode(root->right, key);
    else
    {
        if (root->left == NULL) // isLeaf Node
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) // isLeaf Node
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct TreeNode *temp = minValueNode(root->right);

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
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}