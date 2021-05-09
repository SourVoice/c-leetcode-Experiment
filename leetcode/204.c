#include <stdio.h>
int countPrimes(int n)
{
    if (n == 0 || n == 1)
        return 0;
    if (n == 2)
        return 0;
    int counter = 1;

    for (int i = 3; i < n; i = i + 2)
    {
        int flag = 1;
        for (int j = 3; j * j < i + 1; j = j + 2)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            counter++;
    }
    return counter;
}
int main()
{
    printf("%d ", countPrimes(10));
}