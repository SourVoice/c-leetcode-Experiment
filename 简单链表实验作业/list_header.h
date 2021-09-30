#include <malloc.h>
#include <stdio.h>
typedef struct LINK
{
    int value;
    struct LINK *next;
} Link;
#define TRUE 1
#define FALSE 0
Link *creat_list(int total_elements)
{
    Link *head;
    head = (Link *)malloc(sizeof(Link));
    Link *current = head;
    Link *newNode = NULL;
    printf("依次输入元素：");
    for (int i = 0; i < total_elements; i++)
    {
        newNode = (Link *)malloc(sizeof(Link));
        if (newNode == NULL)
            return NULL;
        scanf("%d", &newNode->value);
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    return head->next;
}
int insert_by_value(Link *current, int new_value) //将新的结点信息传递进函数
{
    Link *previous;
    Link *newNode;
    while (current != NULL & current->value < new_value) //previous指向小于current的上一个结点,不断向前移动
    {
        previous = current;
        current = current->next;
    }

    newNode = (Link *)malloc(sizeof(Link));
    if (newNode == NULL) //分配失败
        return FALSE;
    /*并没有改变结构体内存,仅仅是创建了一个新指针,从previous的结点跳出执行new结点,new里的Link再指向下一个＞它的结点*/
    newNode->value = new_value;
    newNode->next = current;
    previous->next = newNode;
    return TRUE;
}
int insert_by_pos(Link **rootp, int pos, int val)
{
    Link *current = *rootp;
    Link *newNode = NULL;
    current = *rootp;

    for (int i = 1; current != NULL && i < pos; i++)
    {
        rootp = &current->next;
        current = *rootp;
    }
    newNode = (Link *)malloc(sizeof(Link));
    if (newNode == NULL)
        return 0;
    newNode->value = val;
    newNode->next = current;
    *rootp = newNode;
    return 1;
}
Link *delet_by_value(Link **rootp, int target_value)
{
    Link *current = NULL;
    Link *head = NULL;
    head = *rootp;
    current = *rootp;
    rootp = &current->next;
    if (*rootp == NULL)
        return NULL;

    while (current != NULL)
    {

        if (current->value == target_value)
        {
            /*删除头节点*/
            if (current == head)
            {
                head = head->next;
                free(current);
                current = head;
                continue;
            }

            else
            {
                *rootp = current->next;
                free(current);
                current = *rootp;
            }
        }
        rootp = &current->next;
        current = *rootp;
    }
    return head;
}
Link *delet_by_pos(Link **rootp, int pos)
{
    if (*rootp == NULL)
        return NULL;

    Link *current = *rootp;
    Link *head = *rootp;

    int i = 1;
    if (pos == 1)
    {
        head = current->next;
        free(current);
        return head;
    }
    while (current != NULL)
    {
        if (i == pos)
        {
            break;
        }
        rootp = &current->next;
        current = *rootp;
        i++;
    }
    *rootp = current->next;
    free(current);
    current = *rootp;

    return head;
}
void print_list(Link *list)
{
    Link *current = list;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
void freeList(Link **rootp)
{
    Link *current = *rootp;

    while (current != NULL)
    {
        rootp = &current->next;
        free(current);
        current = *rootp;
    }
}