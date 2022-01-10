#include <stdio.h>
#include <stdlib.h>

typedef struct _edge
{
    int src;
    int dest;
} Edge;
typedef struct _graph
{
    int vertexNum;
    int edgeNum;
    int edgeNO;
    Edge *edge;
} Graph;
typedef struct _DSU
{
    int parent;
    int rank;
} DSU;
Graph *initGraph(int vertexNum, int edgeNum)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertexNum = vertexNum;
    newGraph->edgeNum = edgeNum;
    newGraph->edgeNO = 0;
    newGraph->edge = (Edge *)malloc(sizeof(Edge) * edgeNum);
    return newGraph;
}
DSU *initDSU(int vertexNum)
{
    DSU *subset = (DSU *)malloc(sizeof(DSU) * vertexNum);
    for (int i = 0; i < vertexNum; i++)
    {
        subset[i].parent = 0;
        subset[i].rank = 0;
    }
    return subset;
}
void addEdge(Graph *graph, int src, int dest)
{
    graph->edge[graph->edgeNO++].src = src;
    graph->edge[graph->edgeNO++].dest = dest;
}

int find(DSU subsets[], int i)
{
    // find root and make root as parent of i (path
    // compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}
void getUnion(DSU *subsets, int xroot, int yroot)
{ // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // If ranks are same, then make one as root and
    // increment its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int findCycle(Graph *graph)
{
    DSU *subsets = initDSU(graph->vertexNum);

    for (int i = 0; i < graph->edgeNum; i++)
    {
        int x = find(subsets, graph->edge[i].src);
        int y = find(subsets, graph->edge[i].dest);
        if (x == y)
            return 1;
        getUnion(subsets, x, y);
    }
    return 0;
}
// drive the func above
int main()
{
    Graph *graph = initGraph(3, 3);
    // add edgs to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    // judge
    if (findCycle(graph))
        printf("graph contains cycle");
    else
        printf("graph doesn't contain cycle");

    return 0;
}