//最小堆排序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _MinHeapNode
{
    int val;
    struct _MinHeapNode *left;
    struct _MinHeapNode *right;
} MinHeapNode;

typedef struct _MinHeap
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
MinHeapNode *creatNewMinHeapNode(int data)
{
    MinHeapNode *newMinHeapNode = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    newMinHeapNode->val = data;
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
    if (left < minHeap->size && minHeap->arr[left]->val < minHeap->arr[smallest]->val)
    {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->arr[right]->val < minHeap->arr[smallest]->val)
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
//注入元素
void injectElemments(MinHeap *minHeap, char *data, int capacity)
{
    MinHeap *minHeap = initMinHeap(capacity);
    for (int i = 0; i < capacity - 1; i++)
        minHeap->arr[i] = creatNewMinHeapNode(data);
    minHeap->size = capacity;
    buildMinHeap(minHeap);
    return minHeap;
}
int isFull(MinHeap *minHeap)
{
    return minHeap->size == minHeap->capacity;
}
int isLeaf(MinHeapNode *minHeapNode)
{
    return (!minHeapNode->left) && (!minHeapNode->left);
}
void display(MinHeap *minHeap)
{
    for (int i = 0; i < minHeap->size; i++)
    {
        if (isLeaf(minHeap->arr[i]))
        {
            printf("%c ", minHeap->arr[i]->val);
            printf("\n");
        }
    }
}

// //提取最小元素
// MinHeapNode *exactMin(MinHeap *minHeap)
// {
//     MinHeapNode *temp = minHeap->arr[0];
//     minHeap->arr[0] = minHeap->arr[minHeap->size - 1];

//     minHeap->size--;
//     MinHeapify(minHeap, 0);

//     return temp;
// }
int main()
{
    int *arr = (int *)malloc(sizeof(int) * 100000);
    int arrSize = 0;
    while (scanf("%d", &arr[arrSize++]))
    {
    }
    int *temp = (int *)malloc(sizeof(int) * arrSize);
    temp = strcpy(temp, arr);
    return 0;
}