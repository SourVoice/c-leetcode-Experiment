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