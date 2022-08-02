// 622. 设计循环队列
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    {
        queue_size = k;
        array_size = k + 1;
        queue = vector<int>(array_size);
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        rear = (rear + 1) % array_size;
        queue[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % array_size;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return queue[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return queue[rear];
    }

    bool isEmpty()
    {
        return (rear + 1) % array_size == front;
    }

    bool isFull()
    {
        return (rear + 2) % array_size == front;
    }

private:
    vector<int> queue;
    int array_size = 0;
    int queue_size = 0;
    int front = 1;
    int rear = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */