#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 4;
    int Matrix1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int Matrix2[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    int *result = (int *)malloc(sizeof(int) * n * n);

    for (int i = 0; i < n; i++) //i for row
    {
        for (int j = 0; j < n; j++) //j for col
        {
            int sum = 0;
            int k = 0;
            for (; k < n; k++) //k for row
            {
                sum += (*(Matrix1 + i * n + k)) * (*(Matrix2 + k * n + j));
            }
            *(result + i * n + j) = sum;
        }
    }
    for (int i = 0; i < n * n; i++)
    {
        printf("%d ", *(result + i));
    }
    return 0;
}
