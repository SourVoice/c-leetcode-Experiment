/*559. N 叉树的最大深度*/
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
struct Node
{
    int val;
    int numChildren;
    struct Node **children;
};
void rescutionForDepth(struct Node *root, int depth, int *returnDepth)
{
    if (!root)
    {
        *returnDepth = *returnDepth > depth ? *returnDepth : depth;
        return;
    }
    for (int i = 0; i < root->numChildren; i++)
    {
        rescutionForDepth(root->children[i], depth + 1, returnDepth);
    }
}

int maxDepth(struct Node *root)
{
    int *returnDpeth = (int *)malloc(sizeof(int));
    *returnDpeth = 0;
    int depth = 0;
    rescutionForDepth(root, depth, returnDpeth);
    return *returnDpeth;
}