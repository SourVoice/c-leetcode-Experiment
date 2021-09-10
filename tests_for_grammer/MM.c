#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int *Matrix1 = malloc(sizeof(int) * n * n);
    int *Matrix2 = malloc(sizeof(int) * n * n);
    for (int i = 0; i < n * n; i++)
    {
        scanf("%d", Matrix1 + i);
    }
    int *result = malloc(sizeof(int) * n * n);

    for (int i = 0; i < n; i++) //i for row
    {
        for (int j = 0; j < n; j++) //j for col
        {
            int sum = 0;
            for (int k = 0; k < n; k++) //k for row
            {
                sum += (*(Matrix1 + i * n + k)) * (*(Matrix2 + k * n + j));
            }
            *(result + i * n + j) = sum;
        }
    }
    return 0;
}
