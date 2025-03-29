/*Dijkstra's algorithm to build Shortest Path Tree*/
//使用Dijkstra's algorithm建立最短路径树
// with AdjacencyList
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct _AdjListNode
{
    int v;
    int weight;
    struct _AdjListNode *next;
} AdjListNode;

typedef struct _AdjList
{
    AdjListNode *head;
} AdjList;
typedef struct _Graph
{
    int vertexNum;
    AdjList *arr;
} Graph;

Graph *initGraph(int V)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertexNum = V;
    newGraph->arr = (AdjList *)malloc(sizeof(AdjList) * V);
    for (int i = 0; i < V; i++)
    {
        newGraph->arr[i].head = NULL;
    }
    return newGraph;
}
AdjListNode *creatNewAdjListNode(int v, int weight)
{
    AdjListNode *newAdjListNode = (AdjListNode *)malloc(sizeof(AdjListNode));

    newAdjListNode->v = v;
    newAdjListNode->weight = weight;
    newAdjListNode->next = NULL;
    return newAdjListNode;
}
void addAnEdge(Graph *graph, int src, int dest, int weight)
{
    AdjListNode *AnewAdjListNode = creatNewAdjListNode(src, weight);
    AnewAdjListNode->next = graph->arr[dest].head;
    graph->arr[dest].head = AnewAdjListNode;

    AnewAdjListNode = creatNewAdjListNode(dest, weight);
    AnewAdjListNode->next = graph->arr[src].head;
    graph->arr[src].head = AnewAdjListNode;
}
typedef struct _MinHeapNode
{
    int v;
    int dist;
} MinHeapNode;
typedef struct _MinHeap
{
    int size;
    int capacity;
    int *pos;
    MinHeapNode **arr;
} MinHeap;
MinHeap *initMinHeap(int vertexNum)
{
    MinHeap *newMinHeap = (MinHeap *)malloc(sizeof(MinHeap));
    newMinHeap->capacity = vertexNum;
    newMinHeap->size = 0;
    newMinHeap->pos = (int *)malloc(sizeof(int) * vertexNum);
    newMinHeap->arr = (MinHeapNode **)malloc(sizeof(MinHeapNode *) * vertexNum);
    return newMinHeap;
}
MinHeapNode *creatMinHeapNode(int v, int dist)
{
    MinHeapNode *newMinHeapNode = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    newMinHeapNode->v = v;
    newMinHeapNode->dist = dist;
    return newMinHeapNode;
}
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeapify(MinHeap *minHeap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->arr[left]->dist < minHeap->arr[smallest]->dist)
        smallest = left;
    if (right < minHeap->size && minHeap->arr[right]->dist < minHeap->arr[smallest]->dist)
        smallest = right;
    if (smallest != index)
    {
        minHeap->pos[minHeap->arr[index]->v] = smallest;
        minHeap->pos[minHeap->arr[smallest]->v] = index;

        swapMinHeapNode(&minHeap->arr[smallest], &minHeap->arr[index]);
        MinHeapify(minHeap, 0);
    }
}
MinHeapNode *extractMin(MinHeap *minHeap)
{
    MinHeapNode *temp = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];

    minHeap->pos[temp->v] = minHeap->size - 1;
    minHeap->pos[minHeap->arr[minHeap->size - 1]->v] = 0;

    minHeap->size--;
    MinHeapify(minHeap, 0);
    return temp;
}
void updateKey(MinHeap *minHeap, int v, int dist)
{
    int i = minHeap->pos[v];

    minHeap->arr[i]->dist = dist; // update v's dist

    while (i && minHeap->arr[i]->dist < minHeap->arr[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->arr[i]->v] = minHeap->pos[minHeap->arr[(i - 1) / 2]->v]; // set parent's pos to i's

        minHeap->pos[minHeap->arr[(i - 1) / 2]->v] = i;

        swapMinHeapNode(&minHeap->arr[(i - 1) / 2], &minHeap->arr[i]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(MinHeap *minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
        return 1;
    return 0;
}
void printSPT(int *dist, int n)
{
    printf("Vertex          Dist from src\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}
void DijkstraSPT(Graph *garph, int beginV)
{
    MinHeap *minHeap = initMinHeap(garph->vertexNum);

    // int *key = (int *)malloc(sizeof(int) * garph->vertexNum);

    int *dist = (int *)malloc(sizeof(int) * garph->vertexNum);

    for (int i = 0; i < garph->vertexNum; i++)
    {
        dist[i] = INT_MAX;
        minHeap->arr[i] = creatMinHeapNode(i, dist[i]);
        minHeap->pos[i] = i;
    }

    // begin's weight
    dist[beginV] = 0;
    minHeap->arr[0] = creatMinHeapNode(beginV, dist[beginV]);
    minHeap->pos[beginV] = 0;
    updateKey(minHeap, beginV, dist[beginV]);

    minHeap->size = garph->vertexNum;
    while (minHeap->size)
    {
        MinHeapNode *u = extractMin(minHeap);

        for (AdjListNode *v = garph->arr[u->v].head; v != NULL; v = v->next)
        {
            if (isInMinHeap(minHeap, v->v) && dist[u->v] != INT_MAX && dist[v->v] > dist[u->v] + v->weight)
            {
                dist[v->v] = v->weight + dist[u->v];
                updateKey(minHeap, v->v, dist[v->v]);
            }
        }
    }
    printSPT(dist, garph->vertexNum);
}
int main()
{
    Graph *graph = initGraph(9);
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

    DijkstraSPT(graph, 0);
    return 0;
}
/*
以上用例的邻接矩阵
0, 4, 0, 0, 0, 0, 0, 8, 0,
4, 0, 8, 0, 0, 0, 0, 11, 0,
0, 8, 0, 7, 0, 4, 0, 0, 2,
0, 0, 7, 0, 9, 14, 0, 0, 0,
0, 0, 0, 9, 0, 10, 0, 0, 0,
0, 0, 4, 14, 10, 0, 2, 0, 0,
0, 0, 0, 0, 0, 2, 0, 1, 6,
8, 11, 0, 0, 0, 0, 1, 0, 7,
0, 0, 2, 0, 0, 0, 6, 7, 0,
*/