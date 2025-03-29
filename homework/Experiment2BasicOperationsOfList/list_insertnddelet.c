#include "list_header.h"

int main()
{
    int totalElements = 0;
    int deletPos = 0;
    int deletVal = 0;
    int insterPos = 0;
    int insertVal;
    int choose = 1;

    Link *list = NULL;
    while (choose != 0)
    {
        printf("����0���˳�\n");
        printf("����1����������\n");
        printf("����2��ɾ��Ԫ��\n");
        printf("����3������Ԫ��\n");
        printf("����4��ɾ������\n");
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
    }
    printf("exit");
    return 0;
}