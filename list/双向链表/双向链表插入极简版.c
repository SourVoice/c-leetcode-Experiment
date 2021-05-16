#include <stdlib.h>

typedef struct LINK
{
    struct LINK *forward;
    struct LINK *backward;
    int value;
} Link;

int insert(Link *head, int new_value)
{
    register Link *preview = NULL;
    register Link *current = NULL;
    register Link *new = NULL;
    for (preview = head; current = preview->forward; preview = current)
    {
        if (current->value == new_value)
            return -1;
        else if (current->value > new_value)
            break;
    }
    new = (Link *)malloc(sizeof(Link));
    if (new == NULL)
        return -1;

    new->value = new_value;
    new->forward = current;
    preview->forward = new;

    new->backward = preview != head ? preview : NULL;
    (current != NULL ? current : head)->backward = new;
}