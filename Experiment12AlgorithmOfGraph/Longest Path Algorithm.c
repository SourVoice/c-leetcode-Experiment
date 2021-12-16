//根据拓扑排序改编的最长路径算法（DAG, Directed Acyclic Graph）的所有顶点的线性序列
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
AdjListNode *creatAdjListNode(int v, int weight)
{
    AdjListNode *newAdjListNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newAdjListNode->v = v;
    newAdjListNode->weight = weight;
    newAdjListNode->next = NULL;
    return newAdjListNode;
}
// add edge with src to dest
void addAnEdge(Graph *graph, int src, int dest, int weight)
{
    AdjListNode *newAdjListNode = creatAdjListNode(dest, weight);
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
int *topologiclSort(Graph *graph, int *top)
{
    // AdjListNode **stack = (AdjListNode **)malloc(sizeof(AdjListNode *) * graph->vertexNum);
    int *stack = (int *)malloc(sizeof(int) * graph->vertexNum);
    for (int i = 0; i < graph->vertexNum; i++)
    {
        stack[i] = 0;
    }

    int *visited = (int *)malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);

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
    return stack;
}

void findLongestPath(Graph *graph, int beginV)
{
    int *dist = (int *)malloc(sizeof(int) * graph->vertexNum);
    for (int i = 0; i < graph->vertexNum; i++)
        dist[i] = INT_MIN;
    dist[beginV] = 0;

    // the stack
    int *top = (int *)malloc(sizeof(int));
    *top = 0;
    int *topoOrder = topologiclSort(graph, top);
    printf("\n");
    (*top)--;
    // Process vertices in topological order
    while (*top)
    {
        // Get the next vertex from topological order
        int u = topoOrder[(*top)--];

        // Update distances of all adjacent vertices
        if (dist[u] != INT_MIN)
        {
            for (AdjListNode *i = graph->arr[u].head; i != NULL; i = i->next)
            {

                if (dist[i->v] < dist[u] + i->weight)
                    dist[i->v] = dist[u] + i->weight;
            }
        }
    }

    // Print the calculated longest distances
    printf("Print the calculated longest distances:\n");
    for (int i = 0; i < graph->vertexNum; i++)
        (dist[i] == INT_MIN)
            ? printf("INF ")
            : printf("%d ", dist[i]);

    printf("the Longest Path:\n");
    for (int i = 0; i < graph->vertexNum; i++)
        (dist[i] == INT_MIN)
            ? printf("INF%d ", i)
            : printf("%d ", i);
}
int main()
{
    Graph *graph = initGraph(6);
    addAnEdge(graph, 0, 1, 5);
    addAnEdge(graph, 0, 2, 3);
    addAnEdge(graph, 1, 3, 6);
    addAnEdge(graph, 1, 2, 2);
    addAnEdge(graph, 2, 4, 4);
    addAnEdge(graph, 2, 5, 2);
    addAnEdge(graph, 2, 3, 7);
    addAnEdge(graph, 3, 5, 1);
    addAnEdge(graph, 3, 4, -1);
    addAnEdge(graph, 4, 5, -2);
    // AntopologiclSort(graph);
    findLongestPath(graph, 1);
    return 0;
}
/*
邻接矩阵型测试用例
0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 0, 0,
0, 1, 0, 0, 0, 0,
1, 1, 0, 0, 0, 0,
1, 0, 1, 0, 0, 0,
*/