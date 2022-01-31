#include <stdio.h>
#include "alloc.h" //一个新的内存分配器
#undef malloc      //undef消除了stdio.h中的宏定义
void *alloc(size_t size)
{
    void *new_mem;
    /*检查内存分配是否成功*/
    new_mem = malloc(size); //为new_mem分配内存
    if (new_mem == NULL)    //检查是否为空
    {
        printf("Out of memory!\n");
        exit(1);
    }
    return new_mem;
}
/*内存分配实现*/