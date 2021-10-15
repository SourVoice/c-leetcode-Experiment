#include "list_header.h"

int main()
{
    int totalElements = 0;
    int deletPos = 0;
    int deletVal = 0;
    int insterPos = 0;
    int insertVal;
    int choose = 1;
    int toMerge1, toMerge2;
    int polyChoose = 1;
    List *list = NULL;
    LTable ListTable;
    int ListNO = 0;
    while (choose != 0)
    {
        printf("输入0：退出\n");
        printf("输入1：创建链表\n");
        printf("输入2：删除元素\n");
        printf("输入3：插入元素\n");
        printf("输入4：删除链表\n");
        printf("输入5: 合并链表\n");
        printf("输入6: 显示链表\n");
        printf("输入7: 多项式计算器模式\n\n");
        scanf("%d", &choose);

        if (choose == 1)
        {
            printf("输入链表元素个数：");
            scanf("%d", &totalElements);
            ListTable.list[ListNO] = *creat_list(totalElements);
            print_list(&ListTable.list[ListNO]);
            printf("新的到的多项式的编号为: %d\n", ListNO);
            ListNO++;
        }
        else if (choose == 2)
        {
            int deletWay = 0;
            int deletNO;
            printf("输入要删除表的编号: ");
            scanf("%d", &deletNO);
            printf("    删除方式：\n");
            printf("    输入0：按位置删除\n");
            printf("    输入1：按数据删除\n");
            scanf("%d", &deletWay);
            if (deletWay == 0)
            {
                printf("    输入删除位置：");
                scanf("%d", &deletPos);
                List *p = &ListTable.list[deletNO];
                ListTable.list[deletNO] = *delet_by_pos(&p, deletPos);
            }
            else if (deletWay == 1)
            {
                printf("    输入删除数据：");
                scanf("%d", &deletVal);
                List *p = &ListTable.list[deletNO];
                ListTable.list[deletNO] = *delet_by_value(&p, deletVal);
            }
            else
            {
                printf("重新输入");
            }
            print_list(&ListTable.list[deletNO]);
        }
        else if (choose == 3)
        {
            int instertNO;
            printf("输入要插入的链表编号: ");
            scanf("%d", &instertNO);
            printf("依次输入插入位置和数据：");
            scanf("%d %d", &insterPos, &insertVal);
            List *p = &ListTable.list[instertNO];
            insert_by_pos(&p, insterPos, insertVal);
            print_list(&ListTable.list[instertNO]);
        }
        else if (choose == 4)
        {
            free(list);
            list = NULL;
            printf("已被释放\n");
            ListNO--;
        }
        else if (choose == 5)
        {
            printf("输入要合并链表的编号");
            scanf("%d %d", &toMerge1, &toMerge2);
            printf("新的到的多项式的编号为: %d\n", ListNO);
            ListNO++;
        }
        else if (choose == 6)
        {
            int displayNO;
            printf("输入要显示的链表编号:");
            scanf("%d", &displayPoly);
            print_list(&ListTable.list[displayNO]);
        }
        else if (choose == 7)
        {
            Table polyTable;
            int toAdd1, toAdd2;
            int toSub1, toSub2;
            int toDisplayNum;
            static int i = 0;
            while (polyChoose)
            {
                printf("多项式计算器模式\n");
                printf("输入0: 退出计算器模式\n");
                printf("输入1: 输入多项式\n");
                printf("输入2: 多项式相加\n");
                printf("输入4: 显示多项式\n");
                scanf("%d", &polyChoose);
                if (polyChoose == 1)
                {
                    printf("\t输入多项式 (格式: cX^n) : ");
                    polyTable.poly[i] = *(List *)malloc(sizeof(List));
                    creatPoly(&polyTable.poly[i]);
                    printf("新的到的多项式的编号为: %d\n", i);
                    i++;
                }
                if (polyChoose == 2)
                {
                    printf("\t输入要相加的多项式的编号: ");
                    scanf("%d %d", &toAdd1, &toAdd2);
                    polyTable.poly[i] = *addPoly(&polyTable.poly[toAdd1], &polyTable.poly[toAdd2]);
                    printf("新的到的多项式的编号为: %d\n", i);
                    i++;
                }
                if (polyChoose == 3)
                {
                    printf("\t输入要相减的多项式编号: ");
                    scanf("%d %d", &toSub1, &toSub2);
                    polyTable.poly[i] = *subPoly(&polyTable.poly[toSub1], &polyTable.poly[toSub2]);
                }
                if (polyChoose == 4)
                {
                    printf("\t输入要显示的多项式的编号: ");
                    scanf("%d", &toDisplayNum);
                    displayPoly(&polyTable.poly[toDisplayNum]);
                    printf("\n");
                }
                if (polyChoose == 0)
                {
                    break;
                }
            }
        }
        else if (choose == 0)
        {
            if (list != NULL)
                free(list);
            printf("已被释放\n");
            break;
        }
    }
    printf("exit");
    return 0;
}