#ifndef HUFFMAN_By_MINHEAP
#define HUFFMAN_By_MINHEAP
//��С��Ԫ�صĽṹ
struct MinHeapNode
{
    char data;         //characters need to be code
    unsigned int freq; //freqency of data;

    struct MinHeapNode *left;
    struct MinHeapNode *right;
};

//��С��(����С�ѹ���ɭ��)
struct MinHeap
{
    //maintain the size of the MinHeap(or record the count fo the MinHeapNode)
    unsigned int size;

    //��С�ѵ�����
    unsigned int capacity;

    //point to the MinHeapNodes which in MinHeap
    struct MinHeapNode **arr;
};

#endif
