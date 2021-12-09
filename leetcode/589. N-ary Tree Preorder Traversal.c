/*
 * @lc app=leetcode.cn id=589 lang=c
 *
 * [589] N ???????
 */

// @lc code=start
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
void *preRescusion(struct Node *root, int *returnSize, int *a)
{
    if (!root)
        return;
    a[(*returnSize)++] = root->val;
    for (int i = 0; i < root->numChildren; i++)
    {
        preRescusion(root->children[i], returnSize, a);
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
int *preorder(struct Node *root, int *returnSize)
{
    int TreeSize = 1;
    size(root, &TreeSize);
    printf("%d", TreeSize);
    *returnSize = 0;
    int *a = (int *)malloc(sizeof(int) * TreeSize);
    preRescusion(root, returnSize, a);
    return a;
}
// @lc code=end
