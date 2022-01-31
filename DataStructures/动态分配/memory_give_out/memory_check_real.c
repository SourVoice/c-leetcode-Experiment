/*尝试使用自己定义的更安全的内存分配*/
#include "alloc.h"

void function()
{
    int *new_memory;
    /*得到一串整数空间(25*int长度)*/
    new_memory = MALLOC(25, int);
}
int main()
{
    int *pi;
    pi = MALLOC(10, int);
    free(pi + 5); //只释放了一部分内存

    
    return 0;
}