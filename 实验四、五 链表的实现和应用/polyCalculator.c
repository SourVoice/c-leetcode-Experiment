#include "list_header.h"

int main()
{
    int totalElements = 0;
    int deletPos = 0;
    int deletVal = 0;
    int insterPos = 0;
    int insertVal;
    int choose = 1;

    int polyChoose = 1;
    List *list = NULL;
    while (choose != 0)
    {
        printf("����0���˳�\n");
        printf("����1����������\n");
        printf("����2��ɾ��Ԫ��\n");
        printf("����3������Ԫ��\n");
        printf("����4��ɾ������\n");
        printf("����5: ����ʽ������ģʽ\n\n");
        scanf("%d", &choose);

        if (choose == 1)
        {
            printf("��������Ԫ�ظ�����");
            scanf("%d", &totalElements);
            list = creat_list(totalElements);
            print_list(list);
        }
        else if (choose == 2)
        {
            int deletWay = 0;
            printf("ɾ����ʽ��\n");
            printf("    ����0����λ��ɾ��\n");
            printf("    ����1��������ɾ��\n");
            scanf("%d", &deletWay);
            if (deletWay == 0)
            {
                printf("    ����ɾ��λ�ã�");
                scanf("%d", &deletPos);
                list = delet_by_pos(&list, deletPos);
            }
            else if (deletWay == 1)
            {
                printf("    ����ɾ�����ݣ�");
                scanf("%d", &deletVal);
                list = delet_by_value(&list, deletVal);
            }
            else
            {
                printf("��������");
            }
            print_list(list);
        }
        else if (choose == 3)
        {
            printf("�����������λ�ú����ݣ�");
            scanf("%d %d", &insterPos, &insertVal);
            insert_by_pos(&list, insterPos, insertVal);
            print_list(list);
        }
        else if (choose == 4)
        {
            free(list);
            list = NULL;
            printf("�ѱ��ͷ�\n");
        }
        else if (choose == 0)
        {
            if (list != NULL)
                free(list);
            printf("�ѱ��ͷ�\n");
            break;
        }
        else if (choose == 5)
        {
            Table polyTable;
            int toAdd1, toAdd2;
            int toSub1, toSub2;
            int toDisplayNum;
            static int i = 0;
            while (polyChoose)
            {
                printf("����ʽ������ģʽ\n");
                printf("����0: �˳�������ģʽ\n");
                printf("����1: �������ʽ1\n");
                printf("����2: ����ʽ���\n");
                printf("����4: ��ʾ����ʽ\n");
                scanf("%d", &polyChoose);
                if (polyChoose == 1)
                {
                    printf("\t�������ʽ (��ʽ: cX^n) : ");
                    polyTable.poly[i] = *(List *)malloc(sizeof(List));

                    creatPoly(&polyTable.poly[i]);
                    i++;
                }
                if (polyChoose == 2)
                {
                    printf("\t����Ҫ��ӵĶ���ʽ�ı��: ");
                    scanf("%d %d", &toAdd1, &toAdd2);
                    polyTable.poly[i] = *addPoly(&polyTable.poly[toAdd1], &polyTable.poly[toAdd2]);
                    i++;
                }
                if (polyChoose == 3)
                {
                    printf("\t����Ҫ����Ķ���ʽ���: ");
                    scanf("%d %d", &toSub1, &toSub2);
                    polyTable.poly[i] = *subPoly(&polyTable.poly[toSub1], &polyTable.poly[toSub2]);
                }
                if (polyChoose == 4)
                {
                    printf("\t����Ҫ��ʾ�Ķ���ʽ�ı��: ");
                    scanf("%d", &toDisplayNum);
                    displayPoly(&polyTable.poly[toDisplayNum]);
                    printf("\n");
                }
            }
        }
    }
    printf("exit");
    return 0;
}