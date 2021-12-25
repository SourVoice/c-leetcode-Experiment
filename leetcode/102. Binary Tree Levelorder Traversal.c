/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct
{
    struct TreeNode **base;
    int front;
    int rear;
} Queue;
#define MAXSIZE 10000
Queue *initQueue();
int lengthQueue(Queue *queue);
void insertQueue(Queue *queue, struct TreeNode *obj);
void deQueue(Queue *queue);
struct TreeNode *frontQueue(Queue *queue);
int isEmpty(Queue *queue);
int isFull(Queue *queue);

void getDepth(struct TreeNode *root, int depth, int *returnDepth)
{
    if (!root)
    {
        *returnDepth = *returnDepth < depth ? depth : *returnDepth;
        return;
    }
    getDepth(root->left, depth + 1, returnDepth);
    getDepth(root->right, depth + 1, returnDepth);
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    int depth = 0;
    int *returnDepth = (int *)malloc(sizeof(int));
    *returnDepth = 0;
    getDepth(root, depth, returnDepth);
    *returnSize = *returnDepth;
    int **res = (int **)malloc(sizeof(int *) * (*returnDepth));
    int *levelSize = (int *)malloc(sizeof(int) * (*returnDepth));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnDepth));

    Queue *queue = initQueue();
    if (root)
        insertQueue(queue, root);
    while (!isEmpty(queue))
    {
        int n = lengthQueue(queue);
        res[depth] = (int *)malloc(sizeof(int) * n);
        (*returnColumnSizes)[depth] = n;
        for (int i = 0; i < n; i++)
        {
            struct TreeNode *tmpNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            tmpNode = frontQueue(queue);
            deQueue(queue);
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
        depth++;
    }
    return res;
}
Queue *initQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->base = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAXSIZE);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}
int lengthQueue(Queue *queue)
{
    return (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
}
void insertQueue(Queue *queue, struct TreeNode *obj)
{
    if (isFull(queue))
        return;
    queue->base[queue->rear] = obj;
    queue->rear = (queue->rear + 1) % MAXSIZE;
}
void deQueue(Queue *queue)
{
    if (isEmpty(queue))
        return;
    queue->front = (queue->front + 1) % MAXSIZE;
}
struct TreeNode *frontQueue(Queue *queue)
{
    return queue->base[queue->front];
}
int isEmpty(Queue *queue)
{
    return queue->rear == queue->front;
}
int isFull(Queue *queue)
{
    return (queue->rear + 1) % MAXSIZE == queue->front;
}
// 贴一个递归实现层序遍历的代码
/*
void helper(struct TreeNode* root, int** result, int* ColumnSizes, int i, int* maxh) {
    if (root != NULL) {
        result[i][ColumnSizes[i]] = root->val;
        ColumnSizes[i]++;
        if(i+1>*maxh)
            *maxh = i+1;
        helper(root->left, result, ColumnSizes, i + 1, maxh);
        helper(root->right, result, ColumnSizes, i + 1, maxh);
    }
}
int** levelOrder(struct TreeNode* root,
                 int* returnSize,
                 int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * MaxSize);
    int i;
    for (i = 0; i < MaxSize; i++)
        result[i] = (int*)malloc(sizeof(int) * MaxSize);
    *returnColumnSizes = (int*)calloc(MaxSize, sizeof(int));
    *returnSize = 0;
    if(root==NULL)
        return NULL;
    helper(root, result, *returnColumnSizes, 0, returnSize);
    return result;
}
作者：one_ice
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/c-di-gui-die-dai-by-shi-huang-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/