#include <stdlib.h>
#include <stdio.h>
#include "HuffmanByMinHeap.h"
#ifndef BUILD_HUFFMAN_TREE_BY_HEAP
#define BUILD_HUFFMAN_TREE_BY_HEAP
//creat the MinHeap
//and update the MinHeap's Node
struct MinHeapNode *newMinHeapNode(char data, unsigned int frequency)
{
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));

    temp->left = NULL;
    temp->right = NULL;
    temp->freq = frequency;
    temp->data = data;
    return temp;
}
//initialize the MinHeap with capacity
struct MinHeap *initMinHeap(unsigned capacity)
{
    struct MinHeap *theMinHeap =
        (struct MinHeap *)malloc(sizeof(struct MinHeap));

    theMinHeap->size = 0;
    theMinHeap->capacity = capacity;

    theMinHeap->arr =
        (struct MinHeapNode **)malloc(sizeof(struct MinHeapNode *) * theMinHeap->capacity);
    return theMinHeap;
}
//swap the two MinHeapNode in the heap(元素下沉)
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

//最小堆算法
void minHeapify(struct MinHeap *theMinHeap, int x)
{
    int left = x * 2 + 1;  //node's lchild
    int right = x * 2 + 2; //node's rchile
    int smallest = x;      //default parent node

    if (left < theMinHeap->size &&
        theMinHeap->arr[left]->freq < theMinHeap->arr[smallest]->freq)
    {
        smallest = left;
    }
    if (right < theMinHeap->size &&
        theMinHeap->arr[right]->freq < theMinHeap->arr[smallest]->freq)
    {
        smallest = right;
    }
    if (smallest != x)
    {
        swapMinHeapNode(&theMinHeap->arr[smallest], &theMinHeap->arr[x]);
        minHeapify(theMinHeap, smallest); //继续维护
    }
}

//check heap's elements is one
int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

//judge is leaf
int isLeaf(struct MinHeapNode *root)
{
    return (!root->left) && (!root->right);
}
//extract(提取)the minimum(by freauency) MinHeapNode from MinHeap
//同时也是堆的删除操作
struct MinHeapNode *exactMin(struct MinHeap *theMinHeap)
{
    struct MinHeapNode *temp = theMinHeap->arr[0];              //exact the top
    theMinHeap->arr[0] = theMinHeap->arr[theMinHeap->size - 1]; //set last to top

    theMinHeap->size--;
    minHeapify(theMinHeap, 0); //维护最小堆

    return temp;
}
//insert elems to MinHeap
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
{
    minHeap->size++;
    int i = minHeap->size - 1; //自底向上进行插入,每次维护最小堆
    while (i && minHeapNode->freq < minHeap->arr[(i - 1) / 2]->freq)
    {
        minHeap->arr[i] = minHeap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->arr[i] = minHeapNode;
}
//build a heap
void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--) //build from the last's elem's parent't node
    {
        minHeapify(minHeap, i);
    }
}
//inject elems(输入元素)
struct MinHeap *setElemsMinHeap(char *data, int *freq, int size)
{
    struct MinHeap *minHeap = initMinHeap(size);
    for (int i = 0; i < size; i++)
        minHeap->arr[i] = newMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}
//build a huffmantree algorithm
struct MinHeapNode *buildHuffmanTree(char *data, int *freq, int size)
{
    struct MinHeapNode *left, *right, *mergeToTheTop;
    struct MinHeap *minHeap = setElemsMinHeap(data, freq, size);
    while (!isSizeOne(minHeap))
    {
        //step2:
        left = exactMin(minHeap);
        right = exactMin(minHeap);

        //step3:
        //取出两个freq最小的合并成一个,插入堆中,进行维护
        //小的在左
        mergeToTheTop = newMinHeapNode('#', left->freq + right->freq);
        mergeToTheTop->left = left;
        mergeToTheTop->right = right;
        insertMinHeap(minHeap, mergeToTheTop);
    }
    return exactMin(minHeap);
}
//set storeCodes from the HuffmanTree,
//store in storeCodes Array
void buildAndDisplayCodes(struct MinHeapNode *root, int *storeCodes, int top)
{
    if (root->left)
    {
        storeCodes[top] = 0;
        buildAndDisplayCodes(root->left, storeCodes, top + 1);
    }
    if (root->right)
    {
        storeCodes[top] = 1;
        buildAndDisplayCodes(root->right, storeCodes, top + 1);
    }
    if (isLeaf(root))
    {
        printf("%c ", root->data);
        for (int i = 0; i < top; i++)
        {
            printf("%d", storeCodes[i]);
        }
        printf("\n");
    }
}
//build a huffmantree
//then print its codes
struct MinHeapNode *HuffmanCodes(char *data, int *freq, int size)
{
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    int *storecodes = (int *)malloc(sizeof(int) * 16);
    int top = 0;
    buildAndDisplayCodes(root, storecodes, top);
    return root;
}
#endif