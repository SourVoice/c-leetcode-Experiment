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
int sll_insert(LINK *current, int new_value) //将新的结点信息传递进函数
{
    LINK *previous;
    LINK *new;
    while (current != NULL & current->value < new_value) //previous指向小于current的上一个结点,不断向前移动
    {
        previous = current;
        current = current->link;
    }

    new = (LINK *)malloc(sizeof(LINK));
    if (new == NULL) //分配失败
        return FALSE;
    /*并没有改变结构体内存,仅仅是创建了一个新指针,从previous的结点跳出执行new结点,new里的link再指向下一个＞它的结点*/
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
