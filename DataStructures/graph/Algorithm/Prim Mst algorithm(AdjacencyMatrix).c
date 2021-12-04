/*Prim的最小生成树算法*/
//使用邻接矩阵
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define vertexNum 5
#define false 0
#define true 1
#define bool int
// find the min key in the mstSet not included in the mst
int getMinKey(int *key, int *mstSet)
{
    int min = INT_MAX;
    int index;
    for (int i = 0; i < vertexNum; i++)
    {
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i];
            index = i;
        }
    }
    return index;
}

// Prim's Algorithm to build MinimumSpanningTree
void PrimMST(int graph[vertexNum][vertexNum])
{
    int *key = (int *)malloc(sizeof(int) * vertexNum); // an array to rec vertex's weight
    for (int i = 0; i < vertexNum; i++)                // fill the key array with INT_MAX
        key[i] = INT_MAX;
    // memset(key, INT_MAX - 1, sizeof(int) * vertexNum);//memset函数只能按照字节填充(INT_MAX转为(unsigned char))

    bool *mstSet = (bool *)malloc(sizeof(bool) * vertexNum); // an array to rec if the vertex has been add to the mst
    memset(mstSet, false, sizeof(int) * vertexNum);

    int *MST = (int *)malloc(sizeof(int) * vertexNum); // mst will have vertexNum V
    key[0] = 0;                                        // make 0 as the begin vertex
    MST[0] = -1;                                       // this idea is the same to the Kruskal's algorithm
    for (int i = 0; i < vertexNum - 1; i++)
    {
        int u = getMinKey(key, mstSet);
        mstSet[u] = true; // the vertex "u" has been added to the mst,we marked it true

        // update the key ralated to the u
        for (int v = 0; v < vertexNum; v++)
        {
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v])
            {
                MST[v] = u; // v's parent is u
                key[v] = graph[u][v];
            }
        }
    }
    for (int i = 1; i < vertexNum; i++)
    {
        printf("%d--%d:weight%d\n", MST[i], i, graph[i][MST[i]]);
    }
}
int main()
{
    int graph[vertexNum][vertexNum] = {{0, 2, 0, 6, 0},
                                       {2, 0, 3, 8, 5},
                                       {0, 3, 0, 0, 7},
                                       {6, 8, 0, 0, 9},
                                       {0, 5, 7, 9, 0}};
    PrimMST(graph);
    return 0;
}