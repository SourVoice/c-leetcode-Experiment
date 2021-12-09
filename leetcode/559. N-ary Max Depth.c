/*
 * @lc app=leetcode.cn id=559 lang=c
 *
 * [559] N 叉树的最大深度
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
void rescutionForDepth(struct Node *root, int depth, int *returnDepth)
{
    if (!root)
    {

        return;
    }
    *returnDepth = *returnDepth > depth ? *returnDepth : depth;
    for (int i = 0; i < root->numChildren; i++)
    {
        rescutionForDepth(root->children[i], depth + 1, returnDepth);
    }
}

int maxDepth(struct Node *root)
{
    if (!root)
        return 0;
    int *returnDpeth = (int *)malloc(sizeof(int));
    *returnDpeth = 1;

    rescutionForDepth(root, 1, returnDpeth);
    return *returnDpeth;
}
// @lc code=end
