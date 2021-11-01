#include <stdio.h>
//超时
int distributeCandies(int *candyType, int candyTypeSize)
{
    int selectNum = candyTypeSize / 2;
    int type[100001] = {0};
    for (int i = 0; i < candyTypeSize; i++)
    { //统计频率
        type[candyType[i]]++;
    }
    int len = 100001;
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (type[j] < type[min])
            {
                min = j;
            }
        }
        int tmp = type[i];
        type[i] = type[min];
        type[min] = tmp;
    }
    int count = 0;
    int j = 0;
    for (; j < len; j++)
    {
        if (type[j + 1] != 0)
            break;
    }
    for (int i = j; i < len; i++)
    {
        count = i - j;
        if (count >= selectNum)
        {
            return i - j;
        }
        if (i + 1 == len && count < selectNum)
        {
            return i - j;
        }
    }
    return 1;
}
int main()
{
    int a[6] = {1, 1, 2, 2, 3, 3};
    int b[4] = {6, 6, 6, 6};
    int c[10] = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3};
    int len = 10;
    printf("%d", distributeCandies(c, len));
}