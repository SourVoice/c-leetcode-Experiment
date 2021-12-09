//拓扑排序（Topological Sorting）是一个有向无环图（DAG, Directed Acyclic Graph）的所有顶点的线性序列
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _AdjListNode
{
    int v;
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
AdjListNode *creatAdjListNode(int v)
{
    AdjListNode *newAdjListNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newAdjListNode->v = v;
    newAdjListNode->next = NULL;
    return newAdjListNode;
}
// add edge with src to dest
void addAnEdge(Graph *graph, int src, int dest)
{
    AdjListNode *newAdjListNode = creatAdjListNode(dest);
    newAdjListNode->next = graph->arr[src].head;
    graph->arr[src].head = newAdjListNode;
}
// this func to sort one elem in adjList
void topologicalSortTil(Graph *graph, int u, int *visited, int *top, int *stack)
{

    visited[u] = 1; // mark the current not visited
    for (AdjListNode *v = graph->arr[u].head; v != NULL; v = v->next)
    {
        if (!visited[v->v])
        {
            topologicalSortTil(graph, v->v, visited, top, stack);
        }
    }
    stack[(*top)++] = u;
}
// print the stack of the vertes
void printStack(int *stack, int top)
{
    for (int i = top - 1; i >= 0; i--)
    {
        printf("->%d" + (i == top - 1 ? 2 : 0), stack[i]);
    }
}
// this func use topologiclSortTill
void topologiclSort(Graph *graph)
{
    // AdjListNode **stack = (AdjListNode **)malloc(sizeof(AdjListNode *) * graph->vertexNum);
    int *stack = (int *)malloc(sizeof(int) * graph->vertexNum);
    for (int i = 0; i < graph->vertexNum; i++)
    {
        stack[i] = 0;
    }

    int *visited = (int *)malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);

    int *top = (int *)malloc(sizeof(int));
    *top = 0;
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < graph->vertexNum; i++)
    {
        if (visited[i] == 0)
            topologicalSortTil(graph, i, visited, top, stack);
    }
    printStack(stack, *top);
}

int main()
{
    Graph *graph = initGraph(6);
    addAnEdge(graph, 5, 2);
    addAnEdge(graph, 5, 0);
    addAnEdge(graph, 4, 0);
    addAnEdge(graph, 4, 1);
    addAnEdge(graph, 2, 3);
    addAnEdge(graph, 3, 1);
    topologiclSort(graph);
    return 0;
}
