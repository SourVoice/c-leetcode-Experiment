#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int numberVertex = 6;     // number  of vertex
    int numberActivities = 9; // number of edges
    int i, j;

    /*vertices are of the form (v, u) */
    // indegree of each vertex (that is, count the number of edges entering them)
    int indegree[6] = {0, 0, 0, 0, 0, 0};

    int v[9] = {0, 0, 1, 1, 2, 2, 4, 3, 3};   // array v represent the starting vertex of de edge
    int u[9] = {1, 2, 2, 3, 4, 5, 5, 4, 5};   // array u represent the coming vertex of de edge
    int d[9] = {5, 6, 3, 8, 2, 11, 12, 0, 1}; // array d represent the time of de activity (v,u)
    int project_duration = 0;                 // project duration

    /*# Compute the indegree for each vertex v from the graph:
    for each neighbor u of v: indegree[u] += 1*/
    for (j = 0; j < numberActivities; j++)
    {
        indegree[u[j]]++;
    }

    for (j = 0; j < numberVertex; j++)
        printf("indegree %d= %d\n", j, indegree[j]);

    queue<int> Q; // queue Q = empty queue
    int *distance = new int(numberVertex);
    memset(distance, 0, sizeof(int) * numberVertex); // distance = array filled with zeroes

    // for each vertex v:
    // if indegree[v] = 0:
    // insert v on Q
    for (j = 0; j < numberVertex; j++)
    {
        if (indegree[j] == 0)
            Q.push(v[j]);
    }

    int cur_vertex;

    // printf ("first in the queue=%d\n", Q.front());

    /*for each neighbor u of v:
    d istance[u] = max(distance[u], distance[v] + time(v, u))
    indegree[u] -= 1
    if indegree[u] = 0:
    insert u on Q
    */
    static int varr_NO = 0;
    while (!Q.empty())
    {                           // while Q is not empty:
        cur_vertex = Q.front(); // v = get front element from Q
        Q.pop();                // delete de first from queue
        int k = 0;
        for (int i = varr_NO; v[i] == cur_vertex && i < numberVertex; i++)
        {
            k++;
        }
        for (int m = varr_NO; m < k + varr_NO; m++)
        {
            distance[u[m]] = std::max(distance[u[m]],
                                      distance[cur_vertex] + d[cur_vertex]);

            indegree[u[m]] -= 1;

            if (indegree[u[m]] == 0)
            {
                Q.push(u[m]);
            }
        }
        varr_NO += k;
    }

    for (j = 0; j < numberVertex; j++)
    {
        printf("dist [%d]= %d\n", j, distance[j]);
    }
    /*Now, select the vertex x with the largest distance.
    This is the minimum total project_duration.*/
    printf("Total Project Duration %d\n", project_duration);

    return (0);
}