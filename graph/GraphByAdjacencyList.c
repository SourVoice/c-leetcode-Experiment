//use adjacency list to
//repensitive a graph
#include <stdio.h>
#include <stdlib.h>

typedef struct _AdjacencyListNode //rep the adjacency list's node
{
    int v;                           //rep the vertex
    struct _AdjacencyListNode *next; //
} AdjacencyListNode;

typedef struct _AdjacencyList //a struct record the head of each AdjacencyList
{
    struct _AdjacencyListNode *head;
} AdjacencyList;

typedef struct _Graph //the struct of the Graph
{
    int vertexNum;              //total num of the vertes
    struct _AdjacencyList *arr; //record each head of the adjacencyList
} Graph;

//add new node to the one of the AdjacnecyList
AdjacencyListNode *newAdjacencyListNode(int v)
{
    AdjacencyListNode *newNode = (AdjacencyListNode *)malloc(sizeof(AdjacencyListNode));
    newNode->v = v;
    newNode->next = NULL;
    return newNode;
}
//creat a GRAPH with V vertexs
Graph *createGraph(int V)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertexNum = V;

    //malloc V size of space for the arr
    newGraph->arr = (AdjacencyList *)malloc(sizeof(AdjacencyList) * V);

    //initial each head of the adjacency
    for (int i = 0; i < V; i++)
    {
        newGraph->arr[i].head = NULL;
    }
    return newGraph;
}
//add an edge to a undirected graph
//src rep the begin of the edge and the
//dest rep the end of the eage
void addAnEdge(Graph *graph, int src, int dest)
{
    AdjacencyListNode *newNode = newAdjacencyListNode(dest);
    newNode->next = graph->arr[src].head;
    graph->arr[src].head = newNode; //let the src point to the dest

    //for the graph is a undirected,
    //we need add dest vertex too
    newNode = newAdjacencyListNode(src);
    newNode->next = graph->arr[dest].head;
    graph->arr[dest].head = newNode;
}
//remove the edge from src to dest
void removeAnEdge(Graph *graph, int src, int dest)
{
    //remove in the src vertex
    AdjacencyListNode **rootp = &graph->arr[src].head;
    AdjacencyListNode *curr = (AdjacencyListNode *)malloc(sizeof(AdjacencyListNode));
    curr = *rootp;
    while (curr)
    {
        if (curr->v == dest)
        {
            if (*rootp == curr)
            {
                *rootp = curr->next;
                free(curr);
                break;
            }
        }
        rootp = &curr->next;
        curr = curr->next;
    }
    //remove in the dest vertex
    rootp = &graph->arr[dest].head;
    curr = *rootp;
    while (curr)
    {
        if (curr->v == src)
        {
            if (curr == *rootp)
            {
                *rootp = curr->next;
                free(curr);
                break;
            }
        }
        rootp = &curr->next;
        curr = curr->next;
    }
}
//add an vertex to the graph (without add the edge)
void addAVertex(Graph *graph, int v)
{
    graph->vertexNum++;

    graph->arr = (AdjacencyList *)realloc(graph->arr, sizeof(AdjacencyList) * (graph->vertexNum));
    graph->arr[graph->vertexNum - 1].head = NULL;
    AdjacencyListNode *newNode = newAdjacencyListNode(v);

    graph->arr[graph->vertexNum].head = newNode;
}
//remove a vertex in graph
//v is the target vertex
void removeAVertex(Graph *graph, int targetV)
{
    for (int i = 1; i < graph->vertexNum; i++)
    {
        AdjacencyListNode **rootp = &graph->arr[i].head;
        AdjacencyListNode *curr = (AdjacencyListNode *)malloc(sizeof(AdjacencyListNode));
        curr = *rootp;
        while (curr)
        {
            if (curr->v == targetV)
            {
                if (*rootp == curr)
                {
                    *rootp = curr->next;
                    free(curr);
                    break;
                }
            }
            rootp = &curr->next;
            curr = curr->next;
        }
    }
    free(graph->arr[targetV].head);
    graph->arr[targetV].head = NULL;
}
//print the graph's AdjacencyList
void printAdjacencyList(Graph *graph)
{
    for (int v = 0; v < graph->vertexNum; v++)
    {
        AdjacencyListNode *head = graph->arr[v].head;
        if (head)
            printf("\nThe adjacency list of the vertex %d :", v);
        while (head)
        {
            printf("-> %d", head->v);
            head = head->next;
        }
        printf("\n");
    }
}
//bfs of the graph
void bfsTheGraph()
{
    int front = 0;
    int rear = 0;

    //Input start node, enqueue it and mark it as visited
    printf("\nEnter starting node");
    scanf("%d", &num);
    visited[num] = 1;
    queue[rear] = num;
    rear++;

    //Traverse the graph
    while (front != rear)
    {
        printf("\nQueue is not empty");
        //Step 1 : Dequeue
        element = queue[front];
        front++;
        //Step 2 : Add popped element to the traversal result
        printf("\nPushing current node %d into result", element);
        bfs[counter] = element;
        counter++;
        printf("\n%d elements traversed", counter);
        //Step 3 : Enqueue neighbours of element
        //3.1 --> if node has an empty adjacency list, exit program because node is isolated
        if (head[element]->next == NULL)
        {
            printf("\n%d is an isolated node\n", element);
            exit(0);
        }
        //3.2 --> if node has a non-empty adjacency list, add its neighbours into the queue
        else
        {
            temp = head[element]->next;
            printf("\n\nTrying to add neighbours of %d node", element);
            while (temp != NULL)
            {
                current = temp->val;
                if (visited[current] == 0)
                {
                    printf("\n%d node has NOT BEEN VISITED, inserting into queue", current);
                    queue[rear] = current;
                    rear++;
                    visited[current] = 1;
                    printf("\nFRONT --> %d; REAR --> %d", front, rear);
                }
                else
                {
                    printf("\n%d node has ALREADY BEEN VISITED", current);
                }
                temp = temp->next;
            }
        }
    }
    printf("\nQueue is empty");

    //Print result of BFS
    printf("\n------------------BFS-------------------------\n");
    i = 0;
    while (i < counter)
    {
        printf("%d\t", bfs[i]);
        i++;
    }
}
// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 5;
    Graph *graph = createGraph(V);
    addAnEdge(graph, 0, 1);
    addAnEdge(graph, 0, 4);
    addAnEdge(graph, 1, 2);
    addAnEdge(graph, 1, 3);
    addAnEdge(graph, 1, 4);
    addAnEdge(graph, 2, 3);
    addAnEdge(graph, 3, 4);

    addAVertex(graph, 5);
    addAnEdge(graph, 5, 1);
    addAnEdge(graph, 5, 4);

    // print the adjacency list representation of the above graph
    printAdjacencyList(graph);
    printf("\nAnd we remove the vertex you have just added:\n");

    removeAnEdge(graph, 2, 3);
    printAdjacencyList(graph);

    return 0;
}