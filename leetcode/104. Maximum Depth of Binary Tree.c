#include <math.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
µÝ¹é
void getDepth(struct TreeNode *root, int depth, int *returnDepth)
{
    if (!root)
    {
        *returnDepth = *returnDepth > depth ? *returnDepth : depth;
        return 0;
    }
    getDepth(root->left, depth + 1, returnDepth);
    getDepth(root->right, depth + 1, returnDepth);
}
int maxDepth(struct TreeNode *root)
{

    int depth = 0;
    int *returnDepth = (int *)malloc(sizeof(int));
    *returnDepth = 0;
    getDepth(root, depth, returnDepth);
    return *returnDepth;
}
*/
/*
¸üÓÅµÝ¹é
int maxDepth(struct TreeNode *root)
{
    if (!root)
        return 0;
    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}
*/
// BFS
int maxDepth(struct TreeNode *root)
{
    if (!root)
        return 0;
    struct TreeNode *queue[10001];
    int depth = 0;
    int front = 0;
    int rear = 0;

    queue[rear++] = root;
    while (front < rear)
    {
        int queueLen = rear - front;
        for (int i = 0; i < queueLen; i++)
        {
            struct TreeNode *temp = queue[front++];
            if (temp->left)
                queue[rear++] = temp->left;

            if (temp->right)
                queue[rear++] = temp->right;
        }
        depth++;
    }
    return depth;
}