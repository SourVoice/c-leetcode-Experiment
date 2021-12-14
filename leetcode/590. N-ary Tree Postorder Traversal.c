#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    int numChildren;
    struct Node **children;
};
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postRescution(struct Node *root, int *returnSize, int *arr)
{
    if (!root)
        return;
    for (int i = 0; i < root->numChildren; i++)
    {
        postRescution(root->children[i], returnSize, arr);
        arr[(*returnSize)++] = root->children[i]->val;
    }
}

void size(struct Node *root, int *count)
{
    if (!root)
        return;
    for (int i = 0; i < root->numChildren; i++)
    {
        (*count)++;
        size(root->children[i], count);
    }
}

int *postorder(struct Node *root, int *returnSize)
{

    int treeSize = 1;
    size(root, &treeSize);
    *returnSize = 0;
    int *ans = (int *)malloc(sizeof(int) * treeSize);
    if (!root)
        return ans;
    memset(ans, 0, sizeof(int) * treeSize);
    postRescution(root, returnSize, ans);
    ans[(*returnSize)++] = root->val;
    return ans;
}

/*
迭代法,使用先序遍历后倒转顺序
void size(struct Node *root, int *count)
{
    if (!root)
        return;
    for (int i = 0; i < root->numChildren; i++)
    {
        (*count)++;
        size(root->children[i], count);
    }
}
void reverse(int *arr, int arrSize)
{
    for (int i = 0, j = arrSize - 1; i <= j; i++, j--)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
int *postorder(struct Node *root, int *returnSize)
{
    int treeSize = 1;
    size(root, &treeSize);
    int *ans = (int *)malloc(sizeof(int) * treeSize);
    *returnSize = 0;
    struct Node **stack = (struct Node **)malloc(sizeof(struct Node *) * treeSize);
    if (!root)
        return ans;
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        root = stack[top--];
        if (root)
            ans[(*returnSize)++] = root->val;
        for (int i = 0; i < root->numChildren; i++)
            stack[++top] = root->children[i];
    }
    reverse(ans, *returnSize);
    return ans;
}


*/