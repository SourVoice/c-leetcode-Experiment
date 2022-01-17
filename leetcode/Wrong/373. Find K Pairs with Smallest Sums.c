// 373. 查找和最小的 K 对数字

#include <stdio.h>
#include <stdlib.h>
typedef struct ELEMENT
{
    int sum;
    int a;
    int b;
} Elem;

typedef struct _MINHEAPNODE
{
    Elem data;
    struct _MINHEAPNODE *left;
    struct _MINHEAPNODE *right;
} MinHeapNode;
typedef struct _MINEHEAP
{
    unsigned int size;
    unsigned int capacity;
    MinHeapNode **arr;
} MinHeap;

MinHeap *initMinHeap(unsigned int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->arr = (MinHeapNode **)malloc(sizeof(MinHeapNode *) * capacity);
    return minHeap;
}
MinHeapNode *creatNewMinHeapNode(Elem data)
{
    MinHeapNode *newMinHeapNode = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    newMinHeapNode->data = data;
    newMinHeapNode->right = NULL;
    newMinHeapNode->left = NULL;

    return newMinHeapNode;
}
//交换两个元素
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}
//维护最小堆函数
void minHeapify(MinHeap *minHeap, int x)
{
    int smallest = x;
    int left = 2 * x;
    int right = 2 * x + 1;
    if (left < minHeap->size && minHeap->arr[left]->data.sum < minHeap->arr[smallest]->data.sum)
    {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->arr[right]->data.sum < minHeap->arr[smallest]->data.sum)
    {
        smallest = right;
    }
    if (smallest != x)
    {
        swapMinHeapNode(&minHeap->arr[smallest], &minHeap->arr[x]);
        minHeapify(minHeap, smallest); //继续维护
    }
}
// build a heap
void buildMinHeap(MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--) // build from the last's elem's parent't node
    {
        minHeapify(minHeap, i);
    }
}
MinHeapNode *extractMin(MinHeap *minHeap)
{
    MinHeapNode *temp = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];

    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}
// insert elems to MinHeap
void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode)
{
    minHeap->size++;
    int i = minHeap->size - 1; //自底向上进行插入,每次维护最小堆
    while (i && minHeapNode->data.sum < minHeap->arr[(i - 1) / 2]->data.sum)
    {
        minHeap->arr[i] = minHeap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->arr[i] = minHeapNode;
}
int isEmptyMinHeap(MinHeap *minHeap)
{
    return minHeap->size == 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int **returnColumnSizes)
{
    if (k > nums1Size * nums2Size)
        k = nums1Size * nums2Size;
    MinHeap *minHeap;
    minHeap = initMinHeap(100000);
    Elem data = {nums1[0] + nums2[0], 0, 0};
    MinHeapNode *newMinHeapNode = creatNewMinHeapNode(data);
    insertMinHeap(minHeap, newMinHeapNode);
    int **ans = (int **)malloc(sizeof(int *) * k);
    for (int i = 0; i < k; i++)
        ans[i] = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < k && !isEmptyMinHeap(minHeap); i++)
    {
        MinHeapNode *temp = extractMin(minHeap);
        int a = temp->data.a;
        int b = temp->data.b;
        // printf("here\n");
        ans[i][0] = nums1[a];
        ans[i][1] = nums2[b];
        // printf("%d %d\n", ans[i][0], ans[i][1]);
        Elem data1, data2;
        if (a + 1 < nums1Size)
        {
            data1.sum = nums1[a + 1] + nums2[b];
            data1.a = a + 1;
            data1.b = b;
            MinHeapNode *newMinHeapNode = creatNewMinHeapNode(data1);
            insertMinHeap(minHeap, newMinHeapNode);
        }
        if (b + 1 < nums2Size)
        {
            data2.sum = nums1[a] + nums2[b + 1];
            data2.a = a;
            data2.b = b + 1;
            if (data1.a == data2.a && data1.b == data2.b && data1.sum == data2.sum)
                continue;
            MinHeapNode *newMinHeapNode = creatNewMinHeapNode(data2);
            insertMinHeap(minHeap, newMinHeapNode);
        }
    }
    printf("\nhere\n");
    *returnSize = k;
    *returnColumnSizes = malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++)
    {
        (*returnColumnSizes)[i] = 2;
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return ans;
}