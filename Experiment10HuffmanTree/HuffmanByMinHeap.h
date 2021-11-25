#ifndef HUFFMAN_By_MINHEAP
#define HUFFMAN_By_MINHEAP
//最小堆元素的结构
struct MinHeapNode
{
    char data;         //characters need to be code
    unsigned int freq; //freqency of data;

    struct MinHeapNode *left;
    struct MinHeapNode *right;
};

//最小堆(用最小堆构造森林)
struct MinHeap
{
    //maintain the size of the MinHeap(or record the count fo the MinHeapNode)
    unsigned int size;

    //最小堆的容量
    unsigned int capacity;

    //point to the MinHeapNodes which in MinHeap
    struct MinHeapNode **arr;
};

#endif
