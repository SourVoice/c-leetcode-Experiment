#include <malloc.h>
#include <stdio.h>
typedef struct LINK
{
    int value;
    struct LINK *next;
} Link;
#define TRUE 1
#define FALSE 0
struct LINK *creat_list(int total_elements)
{
    struct LINK *head;
    head = (struct LINK *)malloc(sizeof(struct LINK));
    struct LINK *current = head;
    struct LINK *newnode = NULL;
    for (int i = 0; i < total_elements; i++)
    {
        newnode = (struct LINK *)malloc(sizeof(struct LINK));
        if (newnode == NULL)
            return NULL;
        scanf("%d", &newnode->value);
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
    }
    return head->next;
}
int sll_insert(LINK *current, int new_value) //���µĽ����Ϣ���ݽ�����
{
    LINK *previous;
    LINK *new_node;
    while (current != NULL & current->value < new_value) //previousָ��С��current����һ�����,������ǰ�ƶ�
    {
        previous = current;
        current = current->next;
    }

    new_node = (LINK *)malloc(sizeof(LINK));
    if (new_node == NULL) //����ʧ��
        return FALSE;
    /*��û�иı�ṹ���ڴ�,�����Ǵ�����һ����ָ��,��previous�Ľ������ִ��new���,new���link��ָ����һ�������Ľ��*/
    new_node->value = new_value;
    new_node->next = current;
    previous->next = new_node;
    return TRUE;
}
LINK *insert(LINK **rootp, LINK *new_node, int pos)
{
    LINK *current = NULL;
    LINK *head = NULL;
    for (int i;;)
    {
    }
}
Link *delet(Link **rootp, int target_value)
{
    Link *current = NULL;
    Link *head = NULL;
    head = *rootp;
    current = *rootp;
    rootp = &current->next;
    if (*rootp == NULL)
        return;

    while (current != NULL)
    {

        if (current->value == target_value)
        {
            /*ɾ��ͷ�ڵ�*/
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
