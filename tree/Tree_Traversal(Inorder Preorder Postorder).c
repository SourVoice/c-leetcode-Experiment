#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
};
struct node *newNode(int val)
{
    struct node *Node = (struct node *)malloc(sizeof(struct node));
    Node->val = val;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}
void printInOrder(struct node *tree)
{
    if (!tree)
        return;
    printPostOrder(tree->left);
    printf("%d ", tree->val);
    printPostOrder(tree->right);
}
void printPreOrder(struct node *tree)
{
    if (!tree)
        return;
    printf("%d", tree->val);
    printPreOrder(tree->left);
    printPreOrder(tree->right);
}
void printPostOrder(struct node *tree)
{
    if (!tree)
        return;
    printPostOrder(tree->left);
    printPostOrder(tree->right);
    printf("%d ", tree->val);
}
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);

    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);

    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);

    return 0;
}