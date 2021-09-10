#include <stdio.h>
int main()
{
    int i;
    for (i = 0; i++ < 4;)
    {
        printf("%d\n", i);
    }
    return i;
}

/*
i = 3 ==> i < 4 ==> i++ ==> i = 4
           true              continue

i = 4 ==> i < 4 ==> i++ ==> i = 5
          flase             break
*/
