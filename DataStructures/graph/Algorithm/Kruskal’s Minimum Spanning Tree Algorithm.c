/*Kruskal's最小生成树算法*/
//最下生成树 Minimum Spanning Tree
#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 10000

typedef struct _edge
{
    int src;
    int dest;
    int weight; // the weight of the edge
} Edge;

typedef struct _edgeHead
{
    Edge *head;
} edgeHead;

typedef struct _Graph
{
    edgeHead *edge;
    int edgeNO;
    int vertexNum;
} Graph;

typedef struct _DSU
{
    int *parent;
    int *rank;
} DSU;

// init the Graph with vertexNum's vertexs
Graph *initGraph(int vertexNum)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertexNum = vertexNum;
    newGraph->edgeNO = 0;
    newGraph->edge = (edgeHead *)malloc(sizeof(edgeHead) * vertexNum);

    for (int i = 0; i < vertexNum; i++)
    {
        newGraph->edge[i].head = NULL;
    }
    return newGraph;
}
DSU *initDSU(Graph *graph)
{
    DSU *newDSU = (DSU *)malloc(sizeof(DSU));
    newDSU->parent = (int *)malloc(sizeof(int) * graph->edgeNO);
    for (;;)
    {
    }
}
Edge *creatNewEdge(int weight, int src, int dest)
{
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->weight = weight;
    newEdge->src = src;
    newEdge->dest = dest;
    return newEdge;
}
// void BFT(Graph *graph, int begin) {}
void addEdge(Graph *graph, int weight, int src, int dest)
{
    Edge *newEdge = creatNewEdge(weight, src, dest);
    graph->edge[graph->edgeNO++].head = newEdge;
}
