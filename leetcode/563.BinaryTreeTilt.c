/*563. ���������¶�
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
/*����Ϊ��ȷ�汾*/
//������ȷ��res���ں�����������
//Ҫע�����,�����resȫ�ֱ������ں����ڶ����,��leetcode��online judge����ʹ��,��ò�Ҫ��leetcode��ʹ��ȫ�ֱ���
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