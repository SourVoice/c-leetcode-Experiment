#include <stdio.h>
#include <math.h>
#define bool int

bool isPerfectSquare(int num)
{
    return (int)sqrt(num) * (int)sqrt(num) == num ? 1 : 0;
}
int main()
{
    printf("%d", isPerfectSquare(14));
    return 0;
}