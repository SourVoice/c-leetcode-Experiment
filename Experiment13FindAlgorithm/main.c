#include <stdio.h>
#include <string.h>
#include <time.h>
#include "SearchAlgorithm.h"

#define MAX_SIZE 100000;
int main()
{
    int choose = 1;

    // input elem
    int *arr = (int *)malloc(sizeof(int) * 100000);
    int arrSize = 0;
    printf("Spaning 100 random nums:\n");
    int lineNum = 1;
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand();
        printf(",%d" + (i % 10 == 0) ? 1 : 0, arr[i]);
        lineNum++;
        if (!(lineNum % 10))
            printf("\n");
    }

    int *temp = (int *)malloc(sizeof(int) * arrSize);
    int target = 0;
    while (choose)
    {
        printf("input what you want to search:");
        scanf("%d", &target);
        printf("input which way you want to use for search:");

        printf("input 1: Binary Search\n");
        printf("input 2: HashMap Search\n");
        printf("input 3: BST\n");
        printf("input 0: exit\n");
        if (choose == 1)
        {
            temp = strcpy(temp, arr);
            printf("%d", binarySearch(temp, 100, target));
        }
        else if (choose == 2)
        {
            temp = strcpy(temp, arr);
            printf("%d", hashWay(temp, 100, target));
        }
        else if (choose == 3)
        {
            temp = strcpy(temp, arr);
            BST(temp, 100, target);
        }
        else if (choose == 0)
        {
            printf("exit");
        }
    }
}