/*动态分配来拷贝一份字符串*/
#include <stdlib.h>
#include <string.h>
char *startup(char const *string)
{
    char *new_string;
    new_string = malloc(strlen(string) + 1); //+1代表存储结尾的NUL字节

    /*检验分配*/
    if (new_string == NULL)
    {
        prinf("Fault:Can't find that many memory!");
        free(new_string);
        exit(EXIT_FAILURE);
    }
    /*分配成功:*/
    else
    {
        strcpy(new_string, string);
        return new_string;
    }
}