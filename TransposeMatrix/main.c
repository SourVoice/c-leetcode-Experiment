#include "header.h"
#include <stdio.h>
int main()
{
    int m, n;
    int choose = 1;
    MatrixTable matrix;
    for (int i = 1; i <= 100; i++)
    {
        matrix.MatrixNum[i] = (TsMatrix *)malloc(sizeof(TsMatrix));
    }
    int NO = 1;
    while (choose)
    {

        printf("1.input\n"); //输入1：创建矩阵
        printf("2.trans\n"); //输入2：转置矩阵
        printf("3.multi\n"); //输入3：矩阵求积
        printf("0.exit\n");  //输入0：退出
        scanf("%d", &choose);
        if (choose == 1)
        {
            printf("input row and col in order: ");
            scanf("%d %d'\n'", &m, &n);
            matrix.MatrixNum[NO] = creatMaxtrix(m, n);
            displayMatrix(*matrix.MatrixNum[NO]);
            NO++;
        }
        if (choose == 2)
        {
            int toTrans;
            printf("input the NO of the Matrix to Trans: ");
            scanf("%d", &toTrans);
            TransposeSMatrixA(*matrix.MatrixNum[toTrans], matrix.MatrixNum[NO]);
            displayMatrix(*matrix.MatrixNum[NO]);
            NO++;
        }
        if (choose == 3)
        {
            int toMulti1, toMulti2;
            printf("input the NO of two Matrix which you want to multi: ");
            scanf("%d %d", &toMulti1, &toMulti2);
            MultSMatrix(*matrix.MatrixNum[toMulti1], *matrix.MatrixNum[toMulti2], matrix.MatrixNum[NO]);
            displayMatrix(*matrix.MatrixNum[NO]);
            NO++;
        }
        if (choose == 0)
        {
        }
    }

    return 0;
}