// Detect Cycle in an Undirected Graph
// Disjoint Set,or Union-Find data structure(不相交集数据结构)
// Disjoint Set:https://en.wikipedia.org/wiki/Disjoint-set_data_structure
// The application is to check whether a given graph contains a cycle or not.
// refer from geeksforgeeks
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Edge
{

    int src;
    int dest;
} Edge;

typedef struct _Graph
{
    int vertexNum;
    int edgeNum;
    int edgeNO; // rec which of the edge has been added
    Edge *edge;
} Graph; // use edge to represent the graph

typedef struct _DSU
{
    int *parent; // keep track of the subset using 1-D array
    int *rank;   //
} DSU;

Graph *initGraph(int V, int E)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertexNum = V;
    newGraph->edgeNum = E;
    newGraph->edgeNO = 0;
    newGraph->edge = (Edge *)malloc(sizeof(Edge) * E);
    return newGraph;
}
void addEdge(Graph *graph, int src, int dest)
{
    graph->edge[graph->edgeNO].src = src;
    graph->edge[graph->edgeNO].dest = dest;
    graph->edgeNO++;
}
// init the Disjoint Set by filling parent with -1 and rank with 1
DSU *initDSU(int vertexNUM)
{
    DSU *newDSU = (DSU *)malloc(sizeof(DSU));
    newDSU->parent = (int *)malloc(sizeof(int) * vertexNUM);
    memset(newDSU->parent, -1, sizeof(int) * vertexNUM); // means there is only one item in every subset985
    return newDSU;
}
int find(int *parent, int x)
{
    if (parent[x] == -1)
        return x;
    return find(parent, parent[x]);
}
// merge two subsets
void getUnion(int *parent, int x, int y)
{
    parent[x] = y; // use y as x's parent "node"
}
// check whether there's a cycle in the graph
int isCycle(Graph *graph)
{
    DSU *disjointSet = initDSU(graph->vertexNum);

    // Iterate through all edges of graph, find subset of both
    // vertices of every edge, if both subsets are same, then
    // there is cycle in graph.
    for (int i = 0; i < graph->vertexNum; i++)
    {
        int x = find(disjointSet->parent, graph->edge[i].src);
        int y = find(disjointSet->parent, graph->edge[i].dest);
        if (x == y)   // check wherthe the root of the src and the dest are the same
            return 1; // find that there is a cycle(both subsets are same)

        getUnion(disjointSet->parent, x, y);
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
    if (isCycle(graph))
        printf("graph contains cycle");
    else
        printf("graph doesn't contain cycle");

    return 0;
}