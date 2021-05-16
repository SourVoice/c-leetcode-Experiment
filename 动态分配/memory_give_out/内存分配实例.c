#include <stdlib.h>
#include <stdio.h>
int compare_integers(void const *a, void const *b)
{
    register int const *pa = a; //rigister表示将尽可能多将变量存在寄存器(速度快)
    register int const *pb = b;

    return *pa > *pb ? 1 : *pa < *pb ? -1
                                     : 0;
}
int main()
{
    int *array;
    int n_values;
    int i;

    printf("How many values are there?");
    if (scanf("%d", &n_values) != 1 || n_values <= 0)
    {
        printf("illegal number for that many values.\n");
        exit(EXIT_FAILURE);
    }
    /*分配内存储存这些值*/
    array = malloc(n_values * sizeof(int));
    if (array == NULL) //检验分配成功
    {
        printf("Can't get memory for that many values.\n");
        free(array);
        exit(EXIT_FAILURE);
    }
    /*读取这些值*/
    for (i = 0; i < n_values; i += 1)
    {
        print("? ");
        if (scanf("%d", array + i) != 1) //输入!=1表示没有输入
        {
            printf("Error reading value #%d\n", i);
            free(array);
            exit(EXIT_FAILURE);
        }
    }
    /*排序*/
    for (i = 0; i < n_values; i += 1)
        printf("%d\n", array[i]);
    /*释放内存*/
    free(array);
    return EXIT_FAILURE;
}