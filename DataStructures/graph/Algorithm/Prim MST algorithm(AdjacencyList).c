/*Prim的最小生成树算法*/
//使用邻接表最小堆
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
typedef struct _AdjListNode
{
    int dest;
    int weight;
    struct _AdjListNode *next;
} AdjListNode;
typedef struct _AdjListHead // declaration of the AdjList'head
{
    AdjListNode *head;
} AdjListHead;

typedef struct _Graph // declaration of the graph
{
    int edgeNum;
    int vertexNum;
    AdjListHead *AdjList;
} Graph;
// creat a new AdjListNode and return it
AdjListNode *creatNewAdjListNode(int dest, int weight)
{
    AdjListNode *newAdjListNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newAdjListNode->dest = dest;
    newAdjListNode->weight = weight;
    newAdjListNode->next = NULL;
    return newAdjListNode;
}
// init the graph
Graph *initGraph(int V)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertexNum = V;
    newGraph->AdjList = (AdjListHead *)malloc(sizeof(AdjListHead) * V);
    for (int i = 0; i < V; i++)
    {
        newGraph->AdjList[i].head = NULL;
    }
    return newGraph;
}
// add an edge to graph
void addAnEdge(Graph *graph, int src, int dest, int weight)
{
    AdjListNode *newAdjListNode = creatNewAdjListNode(dest, weight);
    newAdjListNode->next = graph->AdjList[src].head;
    graph->AdjList[src].head = newAdjListNode;

    newAdjListNode = creatNewAdjListNode(src, weight);
    newAdjListNode->next = graph->AdjList[dest].head;
    graph->AdjList[dest].head = newAdjListNode;
}
typedef struct _MinHeapNode // decalation of MinHeapNode
{
    int key;      // the key of the vertex.NO
    int vertexNO; // the *.th of the vertex
} MinHeapNode;
typedef struct _MinHeap // decalation of MinHeap
{
    // maintain the size of the MinHeap(or record the count of the MinHeapNode)
    unsigned int size;

    //最小堆的容量
    unsigned int capacity;

    // used for update() func
    int *pos;
    MinHeapNode **arr;
} MinHeap;
// use graph.vertexNum to init the MinHeap
MinHeap *initMinHeap(int capacity)
{
    MinHeap *newMinHeap = (MinHeap *)malloc(sizeof(MinHeap));

    newMinHeap->size = 0;
    newMinHeap->capacity = capacity;
    newMinHeap->pos = (int *)malloc(sizeof(int) * capacity);

    newMinHeap->arr =
        (MinHeapNode **)malloc(sizeof(MinHeapNode *) * capacity);
    return newMinHeap;
}
// return a MinHeapNode* which is init by key and v_th
MinHeapNode *creatMinHeapNode(int key, int v)
{
    MinHeapNode *newMinHeapNode = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    newMinHeapNode->key = key;
    newMinHeapNode->vertexNO = v;
    return newMinHeapNode;
}
// swap two MinHeapNode
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}
// return 1 if empty
int isEmptyMinHeap(MinHeap *minHeap)
{
    return minHeap->size == 0;
}
void minHeapify(MinHeap *minHeap, int index)
{
    if (isEmptyMinHeap(minHeap))
        return;

    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->arr[left]->key < minHeap->arr[smallest]->key)
        smallest = left;
    if (right < minHeap->size && minHeap->arr[right]->key < minHeap->arr[smallest]->key)
        smallest = right;
    if (smallest != index)
    {
        // Swap positions
        minHeap->pos[minHeap->arr[smallest]->vertexNO] = index;
        minHeap->pos[minHeap->arr[index]->vertexNO] = smallest;

        swapMinHeapNode(&minHeap->arr[smallest], &minHeap->arr[index]);
        minHeapify(minHeap, smallest);
    }
}
// extract the min MinHeapNode from the MinHeap
MinHeapNode *extractMin(MinHeap *minHeap)
{
    MinHeapNode *temp = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];

    // update pos of the last MinHeapNode and the first MinHeapNode
    minHeap->pos[temp->vertexNO] = minHeap->size - 1;            // set the root of the MinHeap's pos to the last
    minHeap->pos[minHeap->arr[minHeap->size - 1]->vertexNO] = 0; // set the last node of the MinHeap's pos to the first

    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}
// update minHeap's keyvalue with key
void updateKey(MinHeap *minHeap, int v, int key)
{
    // we need to find v's index in minheap.arr
    int i = minHeap->pos[v];

    minHeap->arr[i]->key = key; // update the key of the v

    while (i && minHeap->arr[i]->key < minHeap->arr[(i - 1) / 2]->key)
    {
        minHeap->pos[minHeap->arr[(i - 1) / 2]->vertexNO] = i;
        minHeap->pos[v] = minHeap->pos[minHeap->arr[(i - 1) / 2]->vertexNO];

        swapMinHeapNode(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);
        // move to the parent node
        i = (i - 1) / 2;
    }
}
// return 1 if isInMinHeap
int isInMinHeap(MinHeap *minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size) // this is baed on the extractMin func
        return 1;
    return 0;
}

void printMST(int *MST, int V)
{
    for (int i = 1; i < V; i++)
    {
        printf("%d--%d\n", MST[i], i);
    }
}
// Prim's algorithm to build a Miminum Spanning Tree with AdjacencyList Data Structure
void PrimMST(Graph *graph)
{
    MinHeap *minHeap = initMinHeap(graph->vertexNum);
    int *MST = (int *)malloc(sizeof(int) * graph->vertexNum);
    int *key = (int *)malloc(sizeof(int) * graph->vertexNum);

    key[0] = 0;
    minHeap->arr[0] = creatMinHeapNode(key[0], 0);
    minHeap->pos[0] = 0;
    for (int i = 1; i < graph->vertexNum; i++)
    {
        key[i] = INT_MAX;
        MST[i] = -1;
        minHeap->arr[i] = creatMinHeapNode(key[i], i);
        minHeap->pos[i] = i;
    }
    minHeap->size = graph->vertexNum;

    while (!isEmptyMinHeap(minHeap))
    {
        MinHeapNode *u = extractMin(minHeap);

        for (AdjListNode *v = graph->AdjList[u->vertexNO].head; v != NULL; v = v->next)
        {
            // update u's adjlist vertex's key
            if (v->weight < key[v->dest] && isInMinHeap(minHeap, v->dest))
            {
                key[v->dest] = v->weight;
                MST[v->dest] = u->vertexNO;                // v's parent is u
                updateKey(minHeap, v->dest, key[v->dest]); // update v's keyvalue
            }
        }
    }
    printMST(MST, graph->vertexNum);
}
// drive the func above
int main()
{
    int V = 9;
    Graph *graph = initGraph(V);
    addAnEdge(graph, 0, 1, 4);
    addAnEdge(graph, 0, 7, 8);
    addAnEdge(graph, 1, 2, 8);
    addAnEdge(graph, 1, 7, 11);
    addAnEdge(graph, 2, 3, 7);
    addAnEdge(graph, 2, 8, 2);
    addAnEdge(graph, 2, 5, 4);
    addAnEdge(graph, 3, 4, 9);
    addAnEdge(graph, 3, 5, 14);
    addAnEdge(graph, 4, 5, 10);
    addAnEdge(graph, 5, 6, 2);
    addAnEdge(graph, 6, 7, 1);
    addAnEdge(graph, 6, 8, 6);
    addAnEdge(graph, 7, 8, 7);

    PrimMST(graph);
    return 0;
}
/*
0 - 1
5 - 2
2 - 3
3 - 4
6 - 5
7 - 6
0 - 7
2 - 8
*/