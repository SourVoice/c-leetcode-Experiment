// flody
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4
#define INF INT_MAX
void printSPT(int **dist)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void FlodyWarshell(int graph[][V])
{
    int **dist = (int **)malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = (int *)malloc(sizeof(int) * V);
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j])
                dist[i][j] = graph[i][j];
        }
    }
    for (int i = 0; i < V; i++)
    {
        dist[i][i] = 0;
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

                    // printSPT(dist);
                    // printf("\n");
                }
            }
        }
    }
    printSPT(dist);
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