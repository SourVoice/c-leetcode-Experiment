#include <stdlib.h>
#include <stdio.h>

int main()
{
    void *p;
    int cin;
    while ((p = malloc(100 * 1024 * 1024)))
    { //1kb*1kb*100(100MB)
        cin++;
    }
    printf("∑÷≈‰¡À%dMbø’º‰", cin);
    free(p);
    return 0;
}