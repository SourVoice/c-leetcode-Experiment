/*Dijkstra's shortest path algorithm*/
// generate a SPT (shortest path tree)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define true 1
#define flase 0
#define V 9
int minDistance(int *dist, int *sptSet)
{
    int min = INT_MAX;
    int index = 0;
    for (int i = 0; i < V; i++)
    {
        if (sptSet[i] == flase && dist[i] < min) // not been visited and min
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}
void printDist(int *dist)
{
    for (int i = 0; i < V; i++)
    {
        printf("%d--%d\n", i, dist[i]);
    }
}
void dijkstraSPT(int graph[V][V], int str)
{

    int *sptSet = (int *)malloc(sizeof(int) * V);
    // set(sptSet, flase);
    memset(sptSet, flase, sizeof(int) * V);
    int *dist = (int *)malloc(sizeof(int) * V);

    // set(dist, INT_MAX);
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    // int *parent;
    dist[str] = 0;
    // parent[str] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && sptSet[v] == flase && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                // parent[u] = v;
            }
        }
    }
    printDist(dist);
}
int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstraSPT(graph, 0);
}