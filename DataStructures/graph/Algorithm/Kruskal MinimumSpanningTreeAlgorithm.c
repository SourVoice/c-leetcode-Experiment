/*Kruskal's最小生成树算法*/
//最下生成树 Minimum Spanning Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int edgeNum;
} Graph;

typedef struct _DSU // disjoint-set data structure,(不相交集合)
{
    int *parent;
    int *rank;
} DSU;

// init the Graph with vertexNum's vertexs
Graph *initGraph(int vertexNum, int edgeNum)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertexNum = vertexNum;
    newGraph->edgeNum = edgeNum;
    newGraph->edgeNO = 0;
    newGraph->edge = (edgeHead *)malloc(sizeof(edgeHead) * edgeNum);

    for (int i = 0; i < edgeNum; i++)
    {
        newGraph->edge[i].head = NULL;
    }
    return newGraph;
}
// set memory for Disjoint Set Data Structure
DSU *initDSU(Graph *graph)
{
    DSU *newDSU = (DSU *)malloc(sizeof(DSU));
    newDSU->parent = (int *)malloc(sizeof(int) * graph->vertexNum);
    memset(newDSU->parent, -1, sizeof(int) * graph->vertexNum);
    return newDSU;
}
// find x's root node in the subset
// return x's root or x if the x is a single vertex
int find(int *parent, int x)
{
    if (parent[x] == -1)
        return x;
    return find(parent, parent[x]);
}
// union func: to add a new elem to the subsets
// and put y as x's parent node
void getUnion(int *parent, int x, int y)
{
    parent[x] = y;
}
// put the w,src,dest to a newEdge and return it
Edge *creatNewEdge(int weight, int src, int dest)
{
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->weight = weight;
    newEdge->src = src;
    newEdge->dest = dest;
    return newEdge;
}
// add a new edge
void addEdge(Graph *graph, int weight, int src, int dest)
{
    Edge *newEdge = creatNewEdge(weight, src, dest);
    graph->edge[graph->edgeNO].head = newEdge;
    graph->edgeNO++;
}
// sort the edgs by weight
void sortTheEdgeWithWeight(Graph *graph)
{
    for (int i = 0; i < graph->edgeNum; i++)
    {
        int min = i;
        for (int j = i + 1; j < graph->edgeNum; j++)
        {
            if (graph->edge[j].head->weight < graph->edge[min].head->weight)
            {
                min = j;
            }
        }
        edgeHead tmp = graph->edge[i];
        graph->edge[i] = graph->edge[min];
        graph->edge[min] = tmp;
    }
}
// kruskal's algorithm to build Minimum Spanning Tree
int kruskalMST(Graph *graph)
{
    DSU *disjointSet = initDSU(graph);

    sortTheEdgeWithWeight(graph);
    int ans = 0;
    for (int i = 0; i < graph->edgeNum; i++)
    {
        int x = find(disjointSet->parent, graph->edge[i].head->src);
        int y = find(disjointSet->parent, graph->edge[i].head->dest);
        if (x != y) // not a circle
        {
            printf("%d--%d:weight==%d\n", graph->edge[i].head->src, graph->edge[i].head->dest, graph->edge[i].head->weight);
            getUnion(disjointSet->parent, x, y);
            ans += graph->edge[i].head->weight;
        }
    }
    return ans;
}
// drive the func above
int main()
{

    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4
    */
    Graph *graph = initGraph(4, 5);
    addEdge(graph, 10, 0, 1);
    // add edge 0-2
    addEdge(graph, 6, 0, 2);

    // add edge 0-3
    addEdge(graph, 5, 0, 3);

    // add edge 1-3
    addEdge(graph, 15, 1, 3);

    // add edge 2-3
    addEdge(graph, 4, 2, 3);

    printf("%d", kruskalMST(graph));
    return 0;
}