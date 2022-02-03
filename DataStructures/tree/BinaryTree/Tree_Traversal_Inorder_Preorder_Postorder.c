#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
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
//======================================recursion递归法===================================================
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
//======================================interative迭代法==============================================
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
    struct node *prev;
    int top = 0;
    while (root != NULL || top != 0)
    {
        while (root != NULL)
        {
            stack[top++] = root; //push 1           push 2          push 4     ;-;
            root = root->left;   //root->val = 2    root->val = 4   root = NULL;-;
        }
        root = stack[--top];                            //root->val = 4        ;root->val = 2
        if (root->right == NULL || root->right == prev) //root->right=NULL时必然打印||通过prev来判断右子树是否被遍历过,root->right==prev代表父节点的右子树被访问过,无需进行访问,直接打印父节点
        {                                               //root->right = NULL   ;-
            prev = root;                                //prev->val = 4
            printf("%d ", root->val);                   //print val
            root = NULL;                                //root = NULL
        }                                               //避免重复遍历左数进入死循环
        else                                            //右子树为被访问过
        {
            stack[top++] = root;
            root = root->right;
        }
    }
}
void getDepth(struct node *root, int depth, int *returnDepth)
{
    if (!root)
    {
        *returnDepth = *returnDepth < depth ? depth : *returnDepth;
        return;
    }
    getDepth(root->left, depth + 1, returnDepth);
    getDepth(root->right, depth + 1, returnDepth);
}
void printLevelOrderInterative(struct node *root)
{
    int *returnDepth = (int *)malloc(sizeof(int));
    *returnDepth = 0;
    int depth = 0;
    getDepth(root, depth, returnDepth);
    int **res = (int **)malloc(sizeof(int *) * (*returnDepth));   //record each level's val
    int *levelSize = (int *)malloc(sizeof(int) * (*returnDepth)); //record each level's size by index

    SqQueue *queue = initQueue();
    if (root)
        insertQueue(queue, root);
    while (!isEmpty(queue))
    {
        int n = queueLength(queue); //在进入下一层前计算距离
        res[depth] = (int *)malloc(sizeof(int) * n);
        levelSize[depth] = n;
        for (int i = 0; i < n; i++)
        {
            struct node *tmpNode = frontQueue(queue);
            deQueue(queue);
            // printf("%d ", tmpNode->val);
            res[depth][i] = tmpNode->val;
            if (tmpNode->left)
            {
                insertQueue(queue, tmpNode->left);
            }
            if (tmpNode->right)
            {
                insertQueue(queue, tmpNode->right);
            }
        }
        // printf("\n");
        depth++;
    }
    // print res in level order
    for (int i = 0; i < (*returnDepth); i++)
    {
        for (int j = 0; j < levelSize[i]; j++)
        {
            printf("%d ", res[i][j]);
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

    //level order to trabersal
    printf("\nLevelorder traversal of binary tree is \n");
    printLevelOrderInterative(root);
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
由已知先序遍历和中序构造二叉树
pre:A   B   D   E   G   H   C   F
    r   
        r
            r
                r
in :D   B   G   E   H   A   C   F
                        r
    |       右      |       | 左 |
        r
   [右]     [   左  ]
*/