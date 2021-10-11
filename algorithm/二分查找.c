#include <stdio.h>
#include <stdlib.h>
void find(int x[], int num, int target)
{
    int end = num - 1, start = 0;
    int mid = num / 2;
    int *progress;
    int i = 0;
    int flag = 0;
    progress = (int *)malloc(num * sizeof(int));
    while (start <= end)
    {
        mid = start + (end - start) / 2; //防止溢出(end+start/2会可能溢出)
        if (target < x[mid])
        {
            end = mid - 1;
            progress[i] = x[mid];
            i++;
        }
        else if (target > x[mid])
        {
            start = mid + 1;
            progress[i] = x[mid];
            i++;
        }
        else if (x[mid] == target)
        {
            printf("%d\n", mid);
            progress[i] = x[mid];
            flag = 1;
            break;
        }
    }
    if (x[mid] != target)
        printf("no\n");
    for (int j = 0; j < i; j++)
    {
        printf(",%d" + !j, progress[j]);
    }
    if (flag)
        printf(",%d", progress[i]);
}
int main()
{
    int num;
    int *x;
    int target;
    scanf("%d", &num);
    x = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        scanf(",%d" + !i, x + i);
    }
    scanf("%d", &target);
    find(x, num, target);
    return 0;
}