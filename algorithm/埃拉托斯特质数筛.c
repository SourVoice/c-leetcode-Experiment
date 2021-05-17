#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int n = 499939;
    int counter = 0;

    if (n < 2)
        return 0;
    int *Primer;
    Primer = (int *)malloc(sizeof(int) * n);
    for (int index = 0; index < n; index++)
    {
        Primer[index] = 1;
    }
    //
    for (int i = 2; i < n; i++)
    {
        if (Primer[i - 1] == 0)
            continue; //已经判断为非质数则不在判断
        for (long long j = (long long)i * i; j < n; j += i)
        {
            Primer[j - 1] = 0;
        }

        if (Primer[i - 1])
            counter++;
    }
    printf("%d", counter);

    return counter;
}