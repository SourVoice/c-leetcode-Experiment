#include "sequenceTable.h"
int main()
{
    SqListPool LPool;
    int NumSqlist = 0;
    int choose;
    int length;
    ElemType elem;
    int insertPos;
    int insertNum;
    int deletPos;
    int deletNum;
    int clearNum;
    int destoryNum;

    int mergeL1;
    int mergeL2;

    int displayNum;
    for (int i = 0; i < 255; i++)
    {
        InitList(&LPool.L[i]);
    }
    SqList L1;
    InitList(&L1);
    while (TRUE)
    {
        printf("����0: ����˳���\n");
        printf("����1: ��˳��������Ԫ��\n");
        printf("����2: ��˳�����ɾ��Ԫ��\n");
        printf("����3: �ϲ�����˳���\n");
        printf("����4: ���˳���\n");
        printf("����5: ����˳���\n");
        printf("����6: ��ʾ˳���\n");
        printf("����7: �Ƴ�\n");
        printf("���������ʽ: ");
        scanf("%d", &choose);
        if (choose == 0)
        {
            printf("˳�����: %d  ���볤��: ", NumSqlist);
            scanf("%d", &length);
            printf("����%d��Ԫ��: ", length);
            for (int i = 0; i < length; i++)
            {
                scanf("%d", &elem);
                if (!ListInsert(&LPool.L[NumSqlist], i, elem))
                    return FALSE;
            }
            NumSqlist++;
        }
        else if (choose == 1)
        {
            printf("���������Ԫ�ص�˳���ı��: ");
            scanf("%d", &insertNum);
            while (insertNum > NumSqlist)
                scanf("%d", &insertNum);
            printf("�������λ�ú�Ԫ��: ");
            scanf("%d %d", &insertPos, &elem);
            ListInsert(&LPool.L[insertNum], insertPos, elem);
        }
        else if (choose == 2)
        {
            printf("�����ɾ��Ԫ�ص�˳���ı��: ");
            scanf("%d", &deletNum);
            while (deletNum > NumSqlist)
                scanf("%d", &deletNum);
            printf("����ɾ��λ��: ");
            scanf("%d", &deletPos);
            ListDelet(&LPool.L[deletNum], deletPos, &elem);
        }
        else if (choose == 3)
        {
            printf("������ϲ�����������ı��: ");
            scanf("%d %d", &mergeL1, &mergeL2);
            ListMerge(&LPool.L[mergeL1], &LPool.L[mergeL2], &LPool.L[NumSqlist]);
            printf("�ϲ�˳�����Ϊ: %d \n", NumSqlist);
            NumSqlist++;
        }
        else if (choose == 4)
        {
            printf("�������յ�˳���ı��: ");
            scanf("%d", &clearNum);
            ClearList(&LPool.L[clearNum]);
        }
        else if (choose == 5)
        {
            printf("��������ٵ�˳���ı��: ");
            scanf("%d ", &destoryNum);
            DestoryList(&LPool.L[destoryNum]);
        }
        else if (choose == 6)
        {
            printf("����Ҫ��ʾ������ı��: ");
            scanf("%d", &displayNum);
            ListDisplay(&LPool.L[displayNum]);
            printf("\n");
        }
        else if (choose == 7)
        {
            for (int i = 0; i < 255; i++)
            {
                DestoryList(&LPool.L[i]);
            }
            printf("\n  exit!   \n");
            break;
        }
    }
}