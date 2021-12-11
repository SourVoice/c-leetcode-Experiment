// Flody-Warshell algorithm
// The Floyd¨CWarshall algorithm typically only
// provides the lengths of the paths between all pairs of vertices.
// With some modifications, create a method reconstruct the actual
// path between any two endpoint vertices
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4
#define INF INT_MAX
void printPath(int **next, int u, int v)
{
    if (next[u][v] == -1)
    {
        return;
    }
    int *path = (int *)malloc(sizeof(int) * V);
    int count = 0;
    path[count++] = u;

    // simply start looping through the vertex u
    // while updating its value to next[u][v]
    // till we reach vertex v
    printf("Shortest path from %d to %d: ", u, v);
    while (u != v)
    {
        u = next[u][v];
        path[count++] = u;
    }
    for (int i = 0; i < count; i++)
    {
        printf("->%d" + (!i ? 2 : 0), path[i]);
    }
}

void FlodyWarshell(int graph[][V])
{
    int **next = (int **)malloc(sizeof(int *) * V); // matrix to store direction of the graph
    int **dist = (int **)malloc(sizeof(int *) * V); // matrix to store each pair of {i,j}'s dist
    // initialize the dist matrix
    for (int i = 0; i < V; i++)
    {
        dist[i] = (int *)malloc(sizeof(int) * V);
    }
    for (int i = 0; i < V; i++)
    {
        next[i] = (int *)malloc(sizeof(int) * V);
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = INT_MAX;
            next[i][j] = -1;
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j])
            {
                dist[i][j] = graph[i][j];
                next[i][j] = j; // if the path exites between two vertex then next[u][v] = v            }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        dist[i][i] = 0;
        next[i][i] = i;
    }
    // for each vertex v do
    //  dist[v][v] ¡û 0

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // dist from i to k and dist from j to k is the min
                // then update dist from i to j
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    int u, v; // u rep for the begin vertex and v rep for the end vertex
    printPath(next, 1, 3);
}

int main()
{ /* Let us create the following weighted graph
         10
 (0)------->(3)
   |		/|\
 5 |		 |
   |		 | 1
  \|/		 |
 (1)------->(2)
        3		 */
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};
    FlodyWarshell(graph);
    return 0;
}