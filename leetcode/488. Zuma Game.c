struct Queue
{
    char *val;
    int colorOnHand[5];
    struct Queue *next;
};
struct Queue *nodePool;
int poolsize;
int poolAlllocated;
struct Queue *getNode(char *val, struct Queue *next, int *colorOnHand)
{
    int i = 0;
    struct Queue *ret;
    if (!nodePool || poolAlllocated >= poolSize)
    {
        if (poolAlllocated)
            poolsize <<= 1;
        else
            poolSize = 1000;
        poolAlllocated = 0;
        nodePool = (struct Queue *)malloc(sizeof(struct Queue *) * poolsize);
    }
    ret = nodePool + (poolAlllocated++);
    ret->val = val;
    ret->next = next;
    for (i = 0; i < 5; i++)
    {
        ret->colorOnHand[i] = colorOnHand[i];
    }
}