/*静态数组实现队列*/
#include <stdio.h>
#include <assert.h>
#include "queue_api.h"

#define QUEUE_SIZE 100;           /*元素数量*/
#define ARRAY_SIZE QUEUE_SIZE + 1 /*数组长*/
/*存储队列元素的数组*/
static QUEUE_TYPE queue[ARRAY_SIZE];
/*两个指向队头和对位的指针*/
static size_t front = 1;
static size_t rear = 0; /*rear n  尾部,臀部*/

void insert(QUEUE_TYPE value)
{
    assert(!is_full());
    rear = (rear + 1) % ARRAY_SIZE;
    queue[rear] = value;
}
void delet()
{
    assert(!is_empty());
    front = (front + 1) % ARRAY_SIZE;
}
QUEUE_TYPE first(void)
{
    assert(!is_empty());
    return queue[front];
}

int is_empty(void)
{
    return (rear + 1) % ARRAY_SIZE == front;
}

int is_full(void)
{
    return (rear + 2) % ARRAY_SIZE == QUEUE_SIZE;
}