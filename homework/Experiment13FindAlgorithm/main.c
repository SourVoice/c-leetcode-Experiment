#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "SearchAlgorithm.h"

#define MAX_SIZE 100000
int main()
{
    // input elem
    int *arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    printf("Spaning 100 random nums:\n");
    int lineNum = 1;
    srand(time(NULL));

    int arrSize = 100;
    for (int i = 1; i <= 100; i++)
    {
        arr[i - 1] = rand();
        printf(", %d" + ((!(i == 1) && (i % 10)) ? 0 : 2), arr[i - 1]);
        lineNum++;
        if (!(lineNum % 10))
            printf("\n");
    }

    int *temp = (int *)malloc(sizeof(int) * MAX_SIZE);
    int target = 0;
    int choose = 1;
    while (choose)
    {
        printf("\n");
        printf("input what you want to search:");
        scanf("%d", &target);
        printf("input 1: Binary Search\n");
        printf("input 2: HashMap Search\n");
        printf("input 3: BST\n");
        printf("input 0: exit\n");
        printf("input which way you want to use for search:");
        scanf("%d", &choose);

        if (isalpha(choose))
            choose = 0;
        if (choose == 1)
        {
            memcpy(temp, arr, sizeof(int) * arrSize);
            printf("%d", binarySearch(temp, arrSize, target));
        }
        else if (choose == 2)
        {
            memcpy(temp, arr, sizeof(int) * arrSize);
            int *returnArr = NULL;
            returnArr = hashWay(temp, arrSize, target);
            if (!returnArr)
                continue;
            printf("index = %d, val = %d ", returnArr[0], returnArr[1]);
        }
        else if (choose == 3)
        {
            memcpy(temp, arr, sizeof(int) * arrSize);
            BST(temp, 100, target);
        }
        else if (choose == 0)
        {
            printf("exit");
        }
    }
}