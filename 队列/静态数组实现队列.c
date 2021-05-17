/*��̬����ʵ�ֶ���*/
#include <stdio.h>
#include <assert.h>
#include "queue_api.h"

#define QUEUE_SIZE 100;           /*Ԫ������*/
#define ARRAY_SIZE QUEUE_SIZE + 1 /*���鳤*/
/*�洢����Ԫ�ص�����*/
static QUEUE_TYPE queue[ARRAY_SIZE];
/*����ָ���ͷ�Ͷ�λ��ָ��*/
static size_t front = 1;
static size_t rear = 0; /*rear n  β��,�β�*/

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