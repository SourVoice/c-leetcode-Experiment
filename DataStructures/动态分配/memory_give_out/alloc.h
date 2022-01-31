/*定义一个更安全的内存分配器*/
#include <stdio.h>
#define MALLOC(num, type) (type *)alloc((num) * sizeof(type));
extern void *alloc(size_t size); //size_t代表一个无符号型的字节//这里相当于声明了一个函数,但没有定义!!