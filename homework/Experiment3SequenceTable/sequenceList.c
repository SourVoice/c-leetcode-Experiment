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
        printf("输入0: 创建顺序表\n");
        printf("输入1: 向顺序表插入中元素\n");
        printf("输入2: 在顺序表中删除元素\n");
        printf("输入3: 合并两个顺序表\n");
        printf("输入4: 清空顺序表\n");
        printf("输入5: 销毁顺序表\n");
        printf("输入6: 显示顺序表\n");
        printf("输入7: 推出\n");
        printf("输入操作方式: ");
        scanf("%d", &choose);
        if (choose == 0)
        {
            printf("顺序表编号: %d  输入长度: ", NumSqlist);
            scanf("%d", &length);
            printf("输入%d个元素: ", length);
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
            printf("输入待插入元素的顺序表的编号: ");
            scanf("%d", &insertNum);
            while (insertNum > NumSqlist)
                scanf("%d", &insertNum);
            printf("输入插入位置和元素: ");
            scanf("%d %d", &insertPos, &elem);
            ListInsert(&LPool.L[insertNum], insertPos, elem);
        }
        else if (choose == 2)
        {
            printf("输入待删除元素的顺序表的编号: ");
            scanf("%d", &deletNum);
            while (deletNum > NumSqlist)
                scanf("%d", &deletNum);
            printf("输入删除位置: ");
            scanf("%d", &deletPos);
            ListDelet(&LPool.L[deletNum], deletPos, &elem);
        }
        else if (choose == 3)
        {
            printf("输入待合并的两个链表的编号: ");
            scanf("%d %d", &mergeL1, &mergeL2);
            ListMerge(&LPool.L[mergeL1], &LPool.L[mergeL2], &LPool.L[NumSqlist]);
            printf("合并顺序表编号为: %d \n", NumSqlist);
            NumSqlist++;
        }
        else if (choose == 4)
        {
            printf("输入待清空的顺序表的编号: ");
            scanf("%d", &clearNum);
            ClearList(&LPool.L[clearNum]);
        }
        else if (choose == 5)
        {
            printf("输入待销毁的顺序表的编号: ");
            scanf("%d ", &destoryNum);
            DestoryList(&LPool.L[destoryNum]);
        }
        else if (choose == 6)
        {
            printf("输入要显示的链表的编号: ");
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