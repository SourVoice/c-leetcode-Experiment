/*队列实现(用于层序遍历)*/
#include <stdlib.h>
#include "tree.h"

typedef struct
{
    struct node **base;
    int front;
    int rear;
} SqQueue;

#define MAXSIZE 10000

SqQueue *initQueue()
{
    SqQueue *queue = (SqQueue *)malloc(sizeof(SqQueue));
    queue->base = (struct node **)malloc(sizeof(struct node *) * MAXSIZE);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

int queueLength(SqQueue *queue)
{
    return (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
}

void insertQueue(SqQueue *queue, struct node *obj)
{
    if ((queue->rear + 1) % MAXSIZE == queue->front) //queue is full!
        return;
    queue->base[queue->rear] = obj;
    queue->rear = (queue->rear + 1) % MAXSIZE;
}

void deQueue(SqQueue *queue)
{
    if (queue->front == queue->rear) //queue is empty
        return;
    queue->front = (queue->front + 1) % MAXSIZE;
}

struct node *frontQueue(SqQueue *queue)
{
    return queue->base[queue->front];
}

int isFull(SqQueue *queue)
{
    return (queue->rear + 1) % MAXSIZE == queue->front;
}

int isEmpty(SqQueue *queue)
{
    return queue->rear == queue->front;
}