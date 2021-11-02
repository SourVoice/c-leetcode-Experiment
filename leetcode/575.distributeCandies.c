#include <stdio.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int distributeCandies(int *candyType, int candyTypeSize)
{
    int sum = candyTypeSize, type = 1;
    qsort(candyType, candyTypeSize, sizeof(int), cmp);
    for (int i = 1; i < candyTypeSize; i++) //排序后两两相邻比较,找到所有不同的糖
    {
        if (candyType[i] != candyType[i - 1])
        {
            type++;
        }
    }
    if (type >= candyTypeSize / 2) //种类大于总糖数一半,最多为n/2种
    {
        return candyTypeSize / 2;
    }
    else //种类小于总糖数一半,所有种类都能吃到
    {
        return type;
    }
}
int main()
{
    int a[6] = {1, 1, 2, 2, 3, 3};
    int b[4] = {6, 6, 6, 6};
    int c[10] = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3};
    int len = 6;
    printf("%d", distributeCandies(a, len));
}