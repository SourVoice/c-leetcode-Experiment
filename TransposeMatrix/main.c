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
    int NO = 0;
    while (choose)
    {

        printf("input\n"); //����1����������
        printf("trans\n"); //����2��ת�þ���
        printf("multi\n"); //����3���������
        printf("exit\n");  //����0���˳�
        scanf("%d", &choose);
        if (choose == 1)
        {
            scanf("%d %d'\n'", &m, &n);
            // getchar();
            *matrix.MatrixNum[NO] = creatMaxtrix(m, n);
            NO++;
        }
        if (choose == 2)
        {
            int toTrans;
            scanf("%d", &toTrans);
            TransposeSMatrixA(*matrix.MatrixNum[toTrans], *matrix.MatrixNum[NO]);
            NO++;
        }
        if (choose == 3)
        {
        }
        if (choose == 0)
        {
        }
    }

    return 0;
}