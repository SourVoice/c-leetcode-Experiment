#include <malloc.h>
typedef struct LINK
{
    int value;
    struct LINK *next;
} Link;

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
        scanf("%d", &newnode->val);
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
    }
    return head->next;
}
int sll_insert(LINK *current, int new_value) //���µĽ����Ϣ���ݽ�����
{
    LINK *previous;
    LINK *new;
    while (current != NULL & current->value < new_value) //previousָ��С��current����һ�����,������ǰ�ƶ�
    {
        previous = current;
        current = current->link;
    }

    new = (LINK *)malloc(sizeof(LINK));
    if (new == NULL) //����ʧ��
        return FALSE;
    /*��û�иı�ṹ���ڴ�,�����Ǵ�����һ����ָ��,��previous�Ľ������ִ��new���,new���link��ָ����һ�������Ľ��*/
    new->value = new_value;
    new->link = current;
    previous->link = new;
    return TRUE;
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
