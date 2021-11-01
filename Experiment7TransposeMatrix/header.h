#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 12500
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
    TsMatrix *MatrixNum[100];
} MatrixTable;
int TransposeSMatrixA(TsMatrix M, TsMatrix *T)
//Mת��ΪT(һ��ת��)
{
    int p, q, col;
    T->mu = M.nu;
    T->nu = M.mu; //�����໥����
    T->tu = M.tu;
    if (T->tu)
    {
        q = 1;
        for (col = 1; col <= M.nu; col++)
        {
            int first = 0; //record weather the elem is the first appear in T
            for (p = 1; p <= M.tu; ++p)
            {
                if (M.data[p].j == col)
                {
                    T->data[q].j = M.data[p].i;
                    T->data[q].i = M.data[p].j;
                    T->data[q].data = M.data[p].data;
                    //set the rpos of the T
                    if (!first)
                    {
                        T->rpos[T->data[q].i] = q;
                        first = 1;
                    }
                    //set the rpos of the T
                    ++q;
                }
            }
        }
    }
    return 1;
}
int FastTransposeSMatrix(TsMatrix M, TsMatrix *T)
//fast transpos
{
    int col, p, q, t;
    int num[20], cpot[20];

    T->mu = M.nu;
    T->nu = M.mu; //�����໥����
    T->tu = M.tu;
    int row[MAXSIZE] = {0}; //to record the row's nums
    if (T->tu)
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
            T->data[q].i = M.data[p].j;
            T->data[q].j = M.data[p].i;
            T->data[q].data = M.data[p].data;
            //
            row[T->data[q].i]++;
            if (row[T->data[q].i] == 1)
            {
                T->rpos[T->data[q].i] = q;
            }
            //
            ++cpot[col];
        }
    }
    return 1;
}
int MultSMatrix(TsMatrix M, TsMatrix N, TsMatrix *Q)
{
    int arow, brow, p, q, t, ctemp[30], l, ccol, tp;
    if (M.nu != N.mu)
        return 0;
    Q->mu = M.mu;
    Q->nu = N.nu;
    Q->tu = 0;
    if (M.mu * N.nu != 0)
    {
        for (arow = 1; arow <= M.mu; ++arow)
        {
            for (l = 1; l <= M.nu; l++)
            {
                ctemp[l] = 0; //�ۼ���
            }
            Q->rpos[arow] = Q->tu + 1;
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
            for (ccol = 1; ccol <= Q->nu; ccol++) //ѹ����
            {
                if (ctemp[ccol])
                {
                    if (++Q->tu > MAXSIZE)
                        return 0;
                    Q->data[Q->tu].i = arow;
                    Q->data[Q->tu].j = ccol;
                    Q->data[Q->tu].data = ctemp[ccol];
                }
            }
        }
    }
    return 1;
}
int AddMaxtrix(TsMatrix M, TsMatrix N, TsMatrix *Q)
{
    if (M.mu != N.mu || M.nu != N.nu)
        return 0;
    Q->mu = M.mu;
    Q->nu = M.nu;
    int p = 1, q = 1;
    int k = 1;
    int row[MAXSIZE] = {0}; //to record the row's nums
    while (p <= M.tu && q <= N.tu)
    {
        if (M.data[p].i == N.data[q].i)
        {
            if (M.data[p].j < N.data[q].j)
            {
                Q->data[k].i = M.data[p].i;
                Q->data[k].j = M.data[p].j;
                Q->data[k].data = M.data[p].data;
                //update the Q's total elems in row
                row[Q->data[k].i]++;
                if (row[Q->data[k].i] == 1) //the elem is the first of the row
                {
                    Q->rpos[Q->data[k].i] = k;
                }
                //update the Q's total elems in row
                p++;
                k++;
            }
            else if (M.data[p].j > N.data[q].j)
            {
                Q->data[k].i = N.data[q].i;
                Q->data[k].j = N.data[q].j;
                Q->data[k].data = N.data[q].data;
                //update the Q's total elems in row
                row[Q->data[k].i]++;
                if (row[Q->data[k].i] == 1) //the elem is the first of the row
                {
                    Q->rpos[Q->data[k].i] = k;
                }
                //update the Q's total elems in row
                q++;
                k++;
            }
            else if (M.data[p].j == N.data[q].j)
            {
                int v = N.data[q].data + M.data[p].data;
                if (v)
                {
                    Q->data[k].i = N.data[q].i;
                    Q->data[k].j = N.data[q].j;
                    Q->data[k].data = v;
                    //update the Q's total elems in row
                    row[Q->data[k].i]++;
                    if (row[Q->data[k].i] == 1) //the elem is the first of the row
                    {
                        Q->rpos[Q->data[k].i] = k;
                    }
                    //update the Q's total elems in row
                    k++;
                }
                p++;
                q++;
            }
        }
        else if (M.data[p].i < N.data[q].i)
        {
            Q->data[k].i = M.data[p].i;
            Q->data[k].j = M.data[p].j;
            Q->data[k].data = M.data[p].data;
            //update the Q's total elems in row
            row[Q->data[k].i]++;
            if (row[Q->data[k].i] == 1) //the elem is the first of the row
            {
                Q->rpos[Q->data[k].i] = k;
            }
            //update the Q's total elems in row
            p++;
            k++;
        }
        else if (M.data[p].i > N.data[q].i)
        {
            Q->data[k].i = N.data[q].i;
            Q->data[k].j = N.data[q].j;
            Q->data[k].data = N.data[q].data;
            //update the Q's total elems in row
            row[Q->data[k].i]++;
            if (row[Q->data[k].i] == 1) //the elem is the first of the row
            {
                Q->rpos[Q->data[k].i] = k;
            }
            //update the Q's total elems in row
            q++;
            k++;
        }
    }
    while (q < N.tu)
    {
        Q->data[k].i = N.data[q].i;
        Q->data[k].j = N.data[q].j;
        Q->data[k].data = N.data[q].data;
        //update the Q's total elems in row
        row[Q->data[k].i]++;
        if (row[Q->data[k].i] == 1) //the elem is the first of the row
        {
            Q->rpos[Q->data[k].i] = k;
        }
        //update the Q's total elems in row
        k++;
        q++;
    }
    while (p < N.tu)
    {
        Q->data[k].i = N.data[p].i;
        Q->data[k].j = N.data[p].j;
        Q->data[k].data = N.data[p].data;
        //update the Q's total elems in row
        row[Q->data[k].i]++;
        if (row[Q->data[k].i] == 1) //the elem is the first of the row
        {
            Q->rpos[Q->data[k].i] = k;
        }
        //update the Q's total elems in row
        k++;
        p++;
    }
    Q->tu = k;
    return 1;
}
TsMatrix *creatMaxtrix(int m, int n)
{
    int elem = 0;
    TsMatrix *M;
    M = (TsMatrix *)malloc(sizeof(TsMatrix));
    M->mu = m;
    M->nu = n;
    M->tu = 0;
    for (int i = 1; i <= m; i++)
    {
        int first = 0;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &elem);
            if (elem)
            {
                M->tu++;
                M->data[M->tu].i = i;
                M->data[M->tu].j = j;
                M->data[M->tu].data = elem;
                if (!first)
                {
                    M->rpos[i] = M->tu;
                    first = 1;
                }
            }
        }
    }
    return M;
}
void displayMatrix(TsMatrix m) //���������ϡ�����
{
    int i, j, k = 1;
    for (i = 1; i <= m.mu; i++)
    {
        for (j = 1; j <= m.nu; j++)
        {
            if (m.data[k].i == i && m.data[k].j == j)
            {
                printf("%d ", m.data[k].data);
                k++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void displayTriple(TsMatrix m) //���ѹ�����ϡ�����
{
    int i;
    for (i = 1; i <= m.tu; i++)
    {
        printf("%d %d %d\n", m.data[i].i, m.data[i].j, m.data[i].data);
    }
    printf("\n");
}
