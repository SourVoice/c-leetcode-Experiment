#include <stdlib.h>

typedef struct LINK
{
    struct LINK *forward;
    struct LINK *backward;
    int value;
} Link;

void insert(Link *head, int new_value)
{
    Link *current = NULL; //指向待插入位置后一个结点
    Link *preview = NULL; //指向插入位置前一个结点
    Link *new = NULL;
    for (preview = head; current = preview->forward != NULL; preview = current)
    {
        if (current->value == new_value)
            return -1;
        else if (current->value > new_value)
            break;
    }
    /*构建新节点*/
    new = (Link *)malloc(sizeof(Link));
    if (new == NULL)
        return -1;
    new->value = new_value;
    new->forward = current;
    /*非尾部*/
    if (current != NULL)
    {
        if (preview != head) //插中间
            new->backward = preview;
        else //插头部
            new->backward = NULL;

        current->backward = new;
        preview->forward = new;
    }
    /*尾部*/
    else
    {
        if (preview != head)
        {
            new->forward = NULL;
            new->backward = preview;
            preview->forward = new;
            head->forward = new;
        }
        else
        {
            head->backward = new;
            new->backward = NULL;
            head->forward = new;
            new->forward = NULL;
        }
    }
}