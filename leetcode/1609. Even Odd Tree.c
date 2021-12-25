#include <stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void getDepth(struct TreeNode *root, int depth, int *returnDepth)
{
    if (!root)
    {
        *returnDepth = *returnDepth > depth ? *returnDepth : depth;
        return;
    }
    getDepth(root->left, depth + 1, returnDepth);
    getDepth(root->right, depth + 1, returnDepth);
}
int getTreeSize(struct TreeNode *root)
{
    if (!root)
        return 0;
    return getTreeSize(root->left) + getTreeSize(root->right) + 1;
}
bool checkArr(int *arr, int levelDepth, int arrSize)
{
    if (levelDepth & 1) // is even level
    {
        for (int i = 0; i < arrSize; i++)
            if ((arr[i] & 1) || (i + 1 < arrSize && arr[i] <= arr[i + 1])) // arr[i] is not an odd
                return false;
    }
    else // is odd level
    {
        for (int i = 0; i < arrSize; i++)
            if (!(arr[i] & 1) || (i + 1 < arrSize && arr[i] >= arr[i + 1])) // arr[i] is not an even
                return false;
    }
    return true;
}
bool isEvenOddTree(struct TreeNode *root)
{
    int depth = 0;
    int *returnDepth = (int *)malloc(sizeof(int));
    *returnDepth = 0;
    getDepth(root, depth, returnDepth);

    int treeSize = getTreeSize(root);
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * treeSize);
    int levelElemNum;
    int *levelArr;

    struct TreeNode *first = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    first = NULL;

    int front = 0;
    int rear = 0;
    if (root)
        queue[rear++] = root;
    levelElemNum++;

    while (front != rear)
    {
        levelElemNum = treeSize == 1 ? 1 : (rear - front + treeSize) % treeSize;
        levelArr = (int *)malloc(sizeof(int) * levelElemNum);
        int arrTop = 0;
        for (int i = 0; i < levelElemNum; i++)
        {
            first = queue[front++];
            levelArr[arrTop++] = first->val;
            if (first->left)
                queue[rear++] = first->left;
            if (first->right)
                queue[rear++] = first->right;
        }
        if (!checkArr(levelArr, depth++, levelElemNum))
            return false;
    }
    return true;
}