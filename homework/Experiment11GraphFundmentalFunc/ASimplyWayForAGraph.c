#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Node
{
    int val;
    struct Node *next;
};

void printList(struct Node *first);

void main()
{
    int m, n, i, j, k, head_nodes, prev, x, p, q, r, count, from, to, visited[20] = {0}, queue[20] = {0}, front = 0, rear = 0, new_val, num, next_node;
    int bfs[20] = {-1};
    int counter = 0, element = 0, current = 0;

    count = 0;
    struct Node *head[20], *temp, *dest, *new_[20], *bidirect[20], *start;

    temp = (struct Node *)malloc(sizeof(struct Node));
    dest = (struct Node *)malloc(sizeof(struct Node));
    start = (struct Node *)malloc(sizeof(struct Node));

    // Input the number of vertices and edges
    printf("Enter number of vertices and edges");
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
    {
        head[i] = (struct Node *)malloc(sizeof(struct Node));
        head[i]->val = i;
        head[i]->next = NULL;
    }

    // Input the edges
    printf(" -------- Enter edge data ---------\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter data for edge %d:", i);
        scanf("%d%d", &from, &to);
        // Creating the adjacency list for source node
        new_[i] = (struct Node *)malloc(sizeof(struct Node));
        new_[i]->val = to;
        new_[i]->next = NULL;
        // Enter edge from source to destination
        if (head[from]->next == NULL)
        {
            head[from]->next = new_[i];
        }
        else
        {
            temp = head[from];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_[i];
        }
        // Creating adjacency list from destination to source
        bidirect[i] = (struct Node *)malloc(sizeof(struct Node));
        bidirect[i]->val = from;
        bidirect[i]->next = NULL;
        // Enter edge for destination to source
        if (head[to]->next == NULL)
        {
            head[to]->next = bidirect[i];
        }
        else
        {
            temp = head[to];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = bidirect[i];
        }
    }

    // Test adjacency list
    for (i = 0; i < m; i++)
    {
        printList(head[i]);
    }

    front = 0;
    rear = 0;

    // Input start node, enqueue it and mark it as visited
    printf("\nEnter starting node");
    scanf("%d", &num);
    visited[num] = 1;
    queue[rear] = num;
    rear++;

    // Traverse the graph
    while (front != rear)
    {
        printf("\nQueue is not empty");
        // Step 1 : Dequeue
        element = queue[front];
        front++;
        // Step 2 : Add popped element to the traversal result
        printf("\nPushing current node %d into result", element);
        bfs[counter] = element;
        counter++;
        printf("\n%d elements traversed", counter);
        // Step 3 : Enqueue neighbours of element
        // 3.1 --> if node has an empty adjacency list, exit program because node is isolated
        if (head[element]->next == NULL)
        {
            printf("\n%d is an isolated node\n", element);
            exit(0);
        }
        // 3.2 --> if node has a non-empty adjacency list, add its neighbours into the queue
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

    // Print result of BFS
    printf("\n------------------BFS-------------------------\n");
    i = 0;
    while (i < counter)
    {
        printf("%d\t", bfs[i]);
        i++;
    }
}

/* Function to traverse a given Circular linked list and print nodes */
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d --> ", head->val);
        head = head->next;
    }
    printf("\n");
}