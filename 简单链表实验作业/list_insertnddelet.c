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
        printf("输入0：退出\n");
        printf("输入1：创建链表\n");
        printf("输入2：删除元素\n");
        printf("输入3：插入元素\n");
        printf("输入4：删除链表\n");
        scanf("%d", &choose);

        if (choose == 1)
        {
            printf("输入链表元素个数：");
            scanf("%d", &totalElements);
            list = creat_list(totalElements);
            print_list(list);
        }
        else if (choose == 2)
        {
            int deletWay = 0;
            printf("删除方式：\n");
            printf("    输入0：按位置删除\n");
            printf("    输入1：按数据删除\n");
            scanf("%d", &deletWay);
            if (deletWay == 0)
            {
                printf("    输入删除位置：");
                scanf("%d", &deletPos);
                list = delet_by_pos(&list, deletPos);
            }
            else if (deletWay == 1)
            {
                printf("    输入删除数据：");
                scanf("%d", &deletVal);
                list = delet_by_value(&list, deletVal);
            }
            else
            {
                printf("重新输入");
            }
            print_list(list);
        }
        else if (choose == 3)
        {
            printf("依次输入插入位置和数据：");
            scanf("%d %d", &insterPos, &insertVal);
            insert_by_pos(&list, insterPos, insertVal);
            print_list(list);
        }
        else if (choose == 4)
        {
            free(list);
            list = NULL;
            printf("已被释放\n");
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