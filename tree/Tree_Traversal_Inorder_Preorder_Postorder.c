#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
};
struct node *newNode(int val) //init a newnode of the tree
{
    struct node *Node = (struct node *)malloc(sizeof(struct node));
    Node->val = val;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}
int size(struct node *root) //get size of the tree
{
    if (!root)
        return 0;
    return size(root->left) + size(root->right) + 1;
}
void LayerOrder(struct node *root) //�������
{
    int treeSize = size(root);
    int *a = malloc(sizeof(int) * treeSize);
    int *strpos = a;
    int *strend = a + treeSize;
    if (root->left)
    {
        a[*strpos] = root->left->val;
    }
    else if (root->right)
    {
    }
}
//======================================recursion�ݹ鷨===================================================
void printInOrder(struct node *root)
{
    if (!root)
        return;
    printInOrder(root->left);
    printf("%d ", root->val);
    printInOrder(root->right);
}
void printPreOrder(struct node *root)
{
    if (!root)
        return;
    printf("%d ", root->val);
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void printPostOrder(struct node *root)
{
    if (!root)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->val);
}
//======================================interative������==============================================
void printPreOrderInterative(struct node *root)
{
    int treesize = size(root);
    struct node **stack = (struct node **)malloc(sizeof(struct node *) * treesize);
    int top = 0;
    while (root != NULL || top != 0)
    {
        while (root != NULL)
        {
            printf("%d ", root->val);
            stack[top++] = root;
            root = root->left;
        }
        root = stack[--top];
        root = root->right;
    }
}

void printInOrderInterative(struct node *root)
{
    int treesize = size(root);
    struct node **stack = (struct node **)malloc(sizeof(struct node *) * treesize);
    int top = 0;
    while (root != NULL || top != 0)
    {
        while (root != NULL)
        {
            stack[top++] = root;
            root = root->left;
        }
        root = stack[--top];
        printf("%d ", root->val);
        root = root->right;
    }
}

void printPostOrderInterative(struct node *root)
{
    int treesize = size(root);
    struct node **stack = (struct node **)malloc(sizeof(struct node *) * treesize);
    struct node **prev;
    int top = 0;
    while (root != NULL || top != 0)
    {
        while (root != NULL)
        {
            stack[top++] = root; //push 1   push 2  push 4
            root = root->left;   //root->val = 2    root->val = 4   root = NULL
        }
        root = stack[--top];                             //root->val = 4
        if (root->right == NULL || root->right == &prev) //root->right=NULLʱ��Ȼ��ӡ||ͨ��prev���ж��������Ƿ񱻱�����,root->right==prev�����ڵ�������������ʹ�,������з���,ֱ�Ӵ�ӡ���ڵ�
        {
            prev = &root; //prev = 4
            printf("%d ", root->val);
            root = NULL; //�����ظ���������������ѭ��
        }
        else //������Ϊ�����ʹ�
        {
            stack[top++] = root;
            root = root->right;
        }
    }
}
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);

    //recursion way
    printf("\nTrabersal a Binary Tree in Recursion Way\n");

    printf("\nPreorder traversal of binary tree is \n");
    printPreOrder(root);

    printf("\nInorder traversal of binary tree is \n");
    printInOrder(root);

    printf("\nPostorder traversal of binary tree is \n");
    printPostOrder(root);

    //interative way
    printf("\nTrabersal a Binary Tree in Interative Way\n");

    printf("\nPreorder traverasl of binary tree is \n");
    printPreOrderInterative(root);

    printf("\nInorder traversal of binary tree is \n");
    printInOrderInterative(root);

    printf("\nPostorder traversal of binary tree is \n");
    printPostOrderInterative(root);
    return 0;
}
/*
         1
       /  \
       2   3
      / \ 
     4   5
        / \
       6   7
����֪��������������������
pre:A   B   D   E   G   H   C   F
    r   
        r
            r
                r
in :D   B   G   E   H   A   C   F
                        r
    |       ��      |       | �� |
        r
   [��]     [   ��  ]
*/