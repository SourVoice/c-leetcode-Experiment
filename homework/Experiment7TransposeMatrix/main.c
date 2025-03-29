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
        printf("4.add\n");   //输入4:矩阵求和
        printf("0.exit\n");  //输入0：退出
        scanf("%d", &choose);
        if (choose == 1)
        {
            printf("input row and col in order: ");
            scanf("%d %d'\n'", &m, &n);
            matrix.MatrixNum[NO] = creatMaxtrix(m, n);
            printf("The Matrix's NO is %d\n", NO);
            displayMatrix(*matrix.MatrixNum[NO]);
            NO++;
        }
        if (choose == 2)
        {
            int toTrans;
            int transChoose = 1;
            printf("input the NO of the Matrix to Trans: ");
            scanf("%d", &toTrans);
            printf("please choose in which way you want to trans: \n");
            while (transChoose)
            {
                printf("input 1:  normal way trans\n");
                printf("input 2:  faster way trans\n");
                scanf("%d", &transChoose);

                if (transChoose == 1)
                {
                    TransposeSMatrixA(*matrix.MatrixNum[toTrans], matrix.MatrixNum[NO]); //the normal way to trans
                    break;
                }
                else if (transChoose == 2)
                {
                    FastTransposeSMatrix(*matrix.MatrixNum[toTrans], matrix.MatrixNum[NO]); //the faster way(not change the function's )
                    break;
                }
            }
            printf("The matrix have been tranposed, output Matrix's NO is %d\n", NO);
            displayMatrix(*matrix.MatrixNum[NO]);
            NO++;
        }
        if (choose == 3)
        {
            int toMulti1, toMulti2;
            printf("input the NO of two Matrix which you want to multi: ");
            scanf("%d %d", &toMulti1, &toMulti2);
            MultSMatrix(*matrix.MatrixNum[toMulti1], *matrix.MatrixNum[toMulti2], matrix.MatrixNum[NO]);
            printf("Matrix.NO %d and Matrix.NO %d have been multied     \ntheoutput Matrix's NO is %d\n", toMulti1, toMulti2, NO);
            displayMatrix(*matrix.MatrixNum[NO]);
            NO++;
        }
        if (choose == 4)
        {
            int toAdd1, toAdd2;
            printf("input the NO of two Matrix which you want to add: ");
            scanf("%d %d", &toAdd1, &toAdd2);
            AddMaxtrix(*matrix.MatrixNum[toAdd1], *matrix.MatrixNum[toAdd2], matrix.MatrixNum[NO]);
            printf("Matrix.NO %d and Matrix.NO %d have been added       \nthe output Matrix's NO is %d\n", toAdd1, toAdd2, NO);
            displayMatrix(*matrix.MatrixNum[NO]);
            NO++;
        }
        if (choose == 0)
        {
            printf("freeing the space...\n");
            for (int i = 1; i <= NO; i++)
            {
                free(matrix.MatrixNum[i]);
                printf("matrix.MatrixNum[%d] have been free..\n", i);
            }
            printf("exit");
            break;
        }
    }

    return 0;
}
