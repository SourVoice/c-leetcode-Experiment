
/*    本程序使用lccwin32编译，如果要用vc，请把long long 类型替换成int64 , 把“%lld”替换成"%l64d" 。*/ #include <stdio.h> #include <stdlib.h> #include <errno.h> //函数返回值typedef enum bool{    OK,ERR}BOOL;//用来保存文件的统计数据typedef struct _a_file{    FILE* fd;    long long zero;    long long one;}AF;//扫描一个字节，返回1的个数int scanChar( char ch ){    int i;    int count = 0;    for( i = 0 ; i < 8 ; i ++ ){        if( ch & 1 ){            count ++;        }        ch = ch >> 1;    }    return count;}//打开一个文件BOOL openFile( AF* af , char* filename ){    af->fd = fopen( filename  , "rb" );    if( af->fd == NULL ) {        perror( "open file");        return ERR;    }    af->zero = 0 ;    af->one = 0;    return OK;} //关闭一个文件，清空数据void closeFile( AF* af ){    if( af->fd ){        fclose( af->fd ) ;    }    af->zero = 0;    af->one = 0;}//扫描一个文件，并统计0和1的数量void scanFile( AF* af ) {    char temp;    int count ;    while( !feof( af->fd ) ){        fread( &temp , sizeof( temp ) , 1 , af->fd ) ;        count = scanChar( temp ) ;        af->zero += 8 - count ;        af->one += count ;    }}//主函数int main( int argc , char** argv ){    char* filename;    AF af;        if( argc != 2 ) {        printf( "输入参数错误\n" ) ;        return 1;    }        filename = argv[1];    if( openFile( &af , filename ) == ERR ){        return 1;    }        scanFile( &af ) ;    printf( "zero = %lld , one = %lld \n " , af.zero , af.one ) ;        closeFile( &af );        return 0;}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
    typedef enum bool { OK,
                        ERR } BOOL;
//用来保存文件的统计数据
typedef struct _a_file
{
    FILE *fd;
    long long zero;
    long long one;
} AF; //扫描一个字节，返回1的个数
int scanChar(char ch)
{
    int i;
    int count = 0;
    for (i = 0; i < 8; i++)
    {
        if (ch & 1)
        {
            count++;
        }
        ch = ch >> 1;
    }
    return count;
}
//打开一个文件
BOOL openFile(AF *af, char *filename)
{
    af->fd = fopen(filename, "rb");
    if (af->fd == NULL)
    {
        perror("open file");
        return ERR;
    }
    af->zero = 0;
    af->one = 0;
    return OK;
}
//关闭一个文件，清空数据
void closeFile(AF *af)
{
    if (af->fd)
    {
        fclose(af->fd);
    }
    af->zero = 0;
    af->one = 0;
}
//扫描一个文件，并统计0和1的数量
void scanFile(AF *af)
{
    char temp;
    int count;
    while (!feof(af->fd))
    {
        fread(&temp, sizeof(temp), 1, af->fd);
        count = scanChar(temp);
        af->zero += 8 - count;
        af->one += count;
    }
}
//主函数
int main(int argc, char **argv)
{
    char *filename;
    AF af;
    if (argc != 2)
    {
        printf("输入参数错误\n");
        return 1;
    }
    filename = argv[1];
    if (openFile(&af, filename) == ERR)
    {
        return 1;
    }
    scanFile(&af);
    printf("zero = %lld , one = %lld \n ", af.zero, af.one);
    closeFile(&af);
    return 0;
}