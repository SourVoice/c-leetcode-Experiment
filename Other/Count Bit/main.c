
/*    ������ʹ��lccwin32���룬���Ҫ��vc�����long long �����滻��int64 , �ѡ�%lld���滻��"%l64d" ��*/ #include <stdio.h> #include <stdlib.h> #include <errno.h> //��������ֵtypedef enum bool{    OK,ERR}BOOL;//���������ļ���ͳ������typedef struct _a_file{    FILE* fd;    long long zero;    long long one;}AF;//ɨ��һ���ֽڣ�����1�ĸ���int scanChar( char ch ){    int i;    int count = 0;    for( i = 0 ; i < 8 ; i ++ ){        if( ch & 1 ){            count ++;        }        ch = ch >> 1;    }    return count;}//��һ���ļ�BOOL openFile( AF* af , char* filename ){    af->fd = fopen( filename  , "rb" );    if( af->fd == NULL ) {        perror( "open file");        return ERR;    }    af->zero = 0 ;    af->one = 0;    return OK;} //�ر�һ���ļ����������void closeFile( AF* af ){    if( af->fd ){        fclose( af->fd ) ;    }    af->zero = 0;    af->one = 0;}//ɨ��һ���ļ�����ͳ��0��1������void scanFile( AF* af ) {    char temp;    int count ;    while( !feof( af->fd ) ){        fread( &temp , sizeof( temp ) , 1 , af->fd ) ;        count = scanChar( temp ) ;        af->zero += 8 - count ;        af->one += count ;    }}//������int main( int argc , char** argv ){    char* filename;    AF af;        if( argc != 2 ) {        printf( "�����������\n" ) ;        return 1;    }        filename = argv[1];    if( openFile( &af , filename ) == ERR ){        return 1;    }        scanFile( &af ) ;    printf( "zero = %lld , one = %lld \n " , af.zero , af.one ) ;        closeFile( &af );        return 0;}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
    typedef enum bool { OK,
                        ERR } BOOL;
//���������ļ���ͳ������
typedef struct _a_file
{
    FILE *fd;
    long long zero;
    long long one;
} AF; //ɨ��һ���ֽڣ�����1�ĸ���
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
//��һ���ļ�
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
//�ر�һ���ļ����������
void closeFile(AF *af)
{
    if (af->fd)
    {
        fclose(af->fd);
    }
    af->zero = 0;
    af->one = 0;
}
//ɨ��һ���ļ�����ͳ��0��1������
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
//������
int main(int argc, char **argv)
{
    char *filename;
    AF af;
    if (argc != 2)
    {
        printf("�����������\n");
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