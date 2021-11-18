/*563. 二叉树的坡度
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *creatNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = val;
    return newNode;
}

int res;
int sum(struct TreeNode *root)
{
    if (!root)
        return 0;
    int left = sum(root->left);
    int right = sum(root->right);
    res += abs(left - right);
    return left + right + root->val;
}

int findTilt(struct TreeNode *root)
{
    res = 0;
    sum(root);
    return res;
}

int main()
{
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root = creatNode(4);
    root->left = creatNode(2);
    root->right = creatNode(9);
    root->left->left = creatNode(3);
    root->left->right = creatNode(5);
    root->right->right = creatNode(7);
    int ans = findTilt(root);
    printf("%d", ans);
    return 0;
}
/*上面为正确版本*/
//上面正确的res是在函数外声明的
//要注意的是,下面的res全局变量是在函数内定义的,在leetcode的online judge不能使用,最好不要在leetcode中使用全局变量
//https://poanchen.github.io/blog/2019/09/13/why-using-a-global-variable-to-solve-Leetcode-problem-can-be-a-bad-idea
/*
// int res = 0;
// int sum(struct TreeNode *root)
// {
//     if (!root)
//         return 0;
//     int left = sum(root->left);
//     int right = sum(root->right);
//     res += abs(left - right);
//     return left + right + root->val;
// }

// int findTilt(struct TreeNode *root)
// {
//     int ans = 0;
//     sum(root);
//     return ans;
// }
*/