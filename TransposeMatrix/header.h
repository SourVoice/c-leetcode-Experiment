#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1250000
#define MAXRC 250
typedef struct
{
    int i, j; //�����з���ԭλ��
    int data;
} triple;
typedef struct
{
    triple data[MAXSIZE + 1]; //data[0]��ʹ��
    int rpos[MAXRC + 1];      //������е�һ������Ԫ������Ԫ���λ��
    int nu, mu, tu;           //�����У������ͷ���Ԫ����
} TsMatrix;
typedef struct
{
    triple data[MAXSIZE + 1];
    int rpos[MAXRC + 1]; //������е�һ������Ԫ������Ԫ���λ��
    int mu, nu, tu;
} RLSMatrix;
typedef struct
{
    TsMatrix MatrixNum[100];
} MatrixTable;
int TransposeSMatrixA(TsMatrix M, TsMatrix &T)
//Mת��ΪT(һ��ת��)
{
    int p, q, col;
    T.mu = M.nu;
    T.nu = M.mu; //�����໥����
    T.tu = M.tu;
    if (T.tu)
    {
        q = 1;
        for (col = 1; col <= M.nu; col++)
        {
            for (p = 1; q <= M.mu; ++p)
            {
                T.data[q].j = M.data[p].i;
                T.data[q].i = M.data[p].j;
                T.data[q].data = M.data[p].data;
                ++q;
            }
        }
    }
    return 1;
}
int FastTransposeSMatrix(TsMatrix M, TsMatrix &T)
//fast transpos
{
    int col, p, q, t;
    int num[20], cpot[20];

    T.mu = M.nu;
    T.nu = M.mu; //�����໥����
    T.tu = M.tu;
    if (T.tu)
    {
        for (t = 1; t <= M.tu; ++t)
        {
            ++num[M.data[t].j]; //���еķ���Ԫ��+1
        }
        cpot[1] = 1;
        for (col = 2; col <= M.tu; ++col)
        {
            cpot[col] = cpot[col - 1] + num[col - 1];
        }
        for (p = 1; p < M.tu; ++p)
        {
            col = M.data[q].j;
            q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].data = M.data[p].data;
            ++cpot[col];
        }
    }
    return 1;
}
int MultSMatrix(TsMatrix M, TsMatrix N, TsMatrix &Q)
{
    int arow, brow, p, q, t, ctemp[30], l, ccol, tp;
    if (M.nu != N.mu)
        return 0;
    Q.mu = M.mu;
    Q.nu = N.nu;
    Q.tu = 0;
    if (M.mu * N.nu != 0)
    {
        for (arow = 1; arow <= M.mu; ++arow)
        {
            for (l = 1; l <= M.nu; l++)
            {
                ctemp[l] = 0; //�ۼ���
            }
            Q.rpos[arow] = Q.tu + 1;
            if (arow < M.mu)
                tp = M.rpos[arow + 1];
            else
                tp = M.tu + 1;
            for (p = M.rpos[arow]; p < tp; p++)
            {
                brow = M.data[p].j;
                if (brow < N.mu) //�ҵ���M��Ԫ�����j��Ӧ��N.data
                {
                    t = N.rpos[brow + 1];
                }
                else
                {
                    t = N.tu + 1;
                }
                for (q = N.rpos[brow]; q < t; q++) //t-qΪN����ÿһ�еķ���Ԫ����
                {
                    ccol = N.data[q].j;
                    ctemp[ccol] += M.data[p].data * N.data[q].data;
                }
            }
            for (ccol = 1; ccol <= Q.nu; ccol++) //ѹ����
            {
                if (ctemp[ccol])
                {
                    if (++Q.tu > MAXSIZE)
                        return 0;
                    Q.data[Q.tu] = {arow, ccol, ctemp[ccol]};
                }
            }
        }
    }
    return 1;
}
int AddMaxtrix(TsMatrix M, TsMatrix N, TsMatrix &Q)
{
    return 1;
}
TsMatrix creatMaxtrix(int m, int n)
{
    int elem = 0;
    TsMatrix M;
    M.mu = m;
    M.tu = n;
    M.tu = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &elem);
            if (elem)
            {
                M.tu++;
                M.data[M.tu] = {m, n, elem};
            }
        }
    }
    return M;
}