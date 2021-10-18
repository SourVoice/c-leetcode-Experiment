#include <malloc.h>
#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 500
typedef struct _node
{
    int value; //系数
    int n;     //指数
    struct _node *next;
} List, Node;
typedef struct _polyTable
{
    List poly[MAXSIZE];
} Table;
typedef struct _Ltable
{
    List list[MAXSIZE];
} LTable;
List *creat_list(int total_elements)
{
    List *head;
    head = (List *)malloc(sizeof(List));
    List *current = head;
    List *newNode = NULL;
    printf("依次输入元素：");
    for (int i = 0; i < total_elements; i++)
    {
        newNode = (List *)malloc(sizeof(List));
        if (newNode == NULL)
            return NULL;
        scanf_s("%d", &newNode->value);
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    return head;
}
void creatPoly(List *L)
{
    Node *current = (Node *)malloc(sizeof(Node));
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        return;
    current = L;
    current->next = NULL;
    int value, n;
    while (scanf_s("%d%d", &value, &n) != EOF)
    {

        //scanf_s("%d %d", &newNode->value, &newNode->n)
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL)
            return;
        newNode->value = value;
        newNode->n = n;
        newNode->next = NULL;
        current = L; //从头开始

        while (current->next)
        {
            if (current->next->n == newNode->n)
            {
                current->next->value += newNode->value;
                break;
            }
            if (current->next->n > newNode->n)
            {
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
        }
        if (!current->next)
        {
            current->next = newNode;
            current = L; //从头开始
            continue;
        }
    }
}
void bubleSortPoly(List *L) //交换节点的冒泡排序
{
    Node *p = (Node *)malloc(sizeof(Node));
    Node *head = (Node *)malloc(sizeof(Node));
    head = L;
    Node *tail = (Node *)malloc(sizeof(Node));
    Node *q = (Node *)malloc(sizeof(Node));
    for (tail = NULL; head->next != tail; tail = q)
    {
        p = head; //每次循环从头开始(p代表指向第一个结点)
        q = p->next;
        for (; q->next != tail;)
        {
            if (q->n > q->next->n)
            {
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = q;
            }
            else
                q = q->next;
        }
    }
}
List *mergeTwoPoly(List *l1, List *l2)
{
    bubleSortPoly(l1);
    bubleSortPoly(l2);
    Node *p = (Node *)malloc(sizeof(Node));
    Node *head = (Node *)malloc(sizeof(Node));
    head = p;
    head = l1;

    if (!p)
    {
        return NULL;
    }
    while (l1 && l2)
    {
        if (l1->n <= l2->n)
        {
            p = l1;
            l1 = l1->next;
        }
        else
        {
            Node *tmp = l2->next;
            p->next = l2;
            p = l2;
            l2->next = l1;
            l2 = tmp;
        }
    }
    if (l1)
        p->next = l1;
    else
        p->next = l2;

    return head->next;
}

List *addPoly(List *poly1, List *poly2)
{
    List *resultP = (List *)malloc(sizeof(List));
    resultP = mergeTwoPoly(poly1, poly2);

    Node *current = (Node *)malloc(sizeof(Node));
    Node *p = (Node *)malloc(sizeof(Node));
    Node *pre = (Node *)malloc(sizeof(Node));

    current = resultP->next;
    //p = current;
    while (current)
    {
        p = current;
        pre = current;
        while (p && p->next)
        {
            if (p->next->n == current->n)
            {
                current->value += p->next->value;
                pre->next = p->next->next;
            }
            p = p->next;
            pre = pre->next;
        }
        current = current->next;
    }
    printf("");
    return resultP;
    //Node* p1 = (Node*)malloc(sizeof(Node));
    //Node* p2 = (Node*)malloc(sizeof(Node));
    //List* resultL3 = (List*)malloc(sizeof(List));
    //Node* newNode = (Node*)malloc(sizeof(Node));
    //Node* current = (Node*)malloc(sizeof(Node));
    //current = resultL3;
    //p1 = poly1->next;
    //while (p1)
    //{
    //    Node* newNode = (Node*)malloc(sizeof(Node));
    //    if (p1->n==current->n) {
    //        current->value += p1->value;
    //    }
    //    newNode->value = p1->value;
    //    newNode->n = p1->n;
    //    newNode->next = NULL;

    //    current->next = newNode;
    //    current = newNode;

    //    p2 = poly2->next;//poly2从头开始判断
    //    while (p2)
    //    {
    //        if (current->n == p2->n)
    //            current->value += p2->value;
    //        else
    //        {
    //            newNode->value = p2->value;
    //            newNode->n = p2->n;
    //            newNode->next = NULL;

    //            current->next = newNode;
    //            current = newNode;
    //        }

    //        p2 = p2->next;
    //    }
    //    p1 = p1->next;
    //}
    //return resultL3;
}
List *subPoly(List *poly1, List *poly2)
{

    List *resultP = (List *)malloc(sizeof(List));
    resultP = mergeTwoPoly(poly1, poly2);

    Node *current = (Node *)malloc(sizeof(Node));
    Node *p = (Node *)malloc(sizeof(Node));
    Node *pre = (Node *)malloc(sizeof(Node));

    current = resultP->next;
    //p = current;
    while (current)
    {
        p = current;
        pre = current;
        while (p && p->next)
        {
            if (p->next->n == current->n)
            {
                current->value -= p->next->value;
                pre->next = p->next->next;
            }
            p = p->next;
            pre = pre->next;
        }
        current = current->next;
    }
    printf("");
    return resultP;
}
void displayPoly(List *L)
{
    Node *Pre = (Node *)malloc(sizeof(Node));
    Pre = L->next;
    if (L->next->n != 0)
    {
        if (L->next->value > 0)
        {
            printf("%d", L->next->value);
        }
        else
        {
            printf("-");
            printf("%d", abs(L->next->value));
        }
        printf("X^%d", L->next->n);
    }
    L = L->next;
    while (L->next)
    {
        if (L->next->value < 0)
        {
            printf("-");
            printf("%d", abs(L->next->value));
        }
        else if (L->next->value > 0)
        {
            if (Pre->n == 0)
                printf("%d", abs(L->next->value));
            else
            {
                printf("+");
                printf("%d", abs(L->next->value));
            }
        }
        else
            continue;
        printf("X^%d", L->next->n);
        Pre = L;
        L = L->next;
    }
}
int insert_by_value(List *current, int new_value) //将新的结点信息传递进函数
{
    List *previous = (List *)malloc(sizeof(List));
    List *newNode;
    while (current != NULL && current->value < new_value) //previous指向小于current的上一个结点,不断向前移动
    {
        previous = current;
        current = current->next;
    }

    newNode = (List *)malloc(sizeof(List));
    if (newNode == NULL) //分配失败
        return FALSE;
    /*并没有改变结构体内存,仅仅是创建了一个新指针,从previous的结点跳出执行new结点,new里的Link再指向下一个＞它的结点*/
    newNode->value = new_value;
    newNode->next = current;
    previous->next = newNode;
    return TRUE;
}
int insert_by_pos(List **rootp, int pos, int val)
{
    List *current = *rootp;
    List *newNode = NULL;
    current = *rootp;

    for (int i = 1; current != NULL && i < pos; i++)
    {
        rootp = &current->next;
        current = *rootp;
    }
    newNode = (List *)malloc(sizeof(List));
    if (newNode == NULL)
        return 0;
    newNode->value = val;
    newNode->next = current;
    *rootp = newNode;
    return 1;
}
List *delet_by_value(List **rootp, int target_value)
{
    List *current = NULL;
    List *head = NULL;
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
List *delet_by_pos(List **rootp, int pos)
{
    if (*rootp == NULL)
        return NULL;

    List *current = *rootp;
    List *head = *rootp;

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
void bubleSortList(List *L) //交换节点的冒泡排序
{
    Node *p = (Node *)malloc(sizeof(Node));
    Node *head = (Node *)malloc(sizeof(Node));
    head = L;
    Node *tail = (Node *)malloc(sizeof(Node));
    Node *q = (Node *)malloc(sizeof(Node));
    for (tail = NULL; head->next != tail; tail = q)
    {
        p = head; //每次循环从头开始(p代表指向第一个结点)
        q = p->next;
        for (; q->next != tail;)
        {
            if (q->value > q->next->value)
            {
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = q;
            }
            else
                q = q->next;
        }
    }
}
void remove_duplicates(List *list)
{
    Node *current = NULL;
    Node *pre = NULL;
    Node *p = list->next;
    int val;
    while (p)
    {
        pre = p;
        current = p->next;
        val = p->value;
        while (current)
        {
            if (current->value == val)
            {
                Node *tmp = (Node *)malloc(sizeof(Node));
                tmp = current->next;
                pre->next = current->next;
                free(current);
                current = tmp;
                continue;
            }
            pre = current;
            current = current->next;
        }
        p = p->next;
    }
}

List *mergeTwoListsInOrder(List *l1, List *l2)
{
    bubleSortList(l1);
    bubleSortList(l2);
    Node *p = (Node *)malloc(sizeof(Node));
    Node *head = (Node *)malloc(sizeof(Node));
    l1 = l1->next;
    l2 = l2->next;
    head = p;
    head->next = l1;

    if (!p)
    {
        return NULL;
    }
    while (l1 && l2)
    {
        if (l1->value <= l2->value)
        {
            p = l1;
            l1 = l1->next;
        }
        else
        {
            Node *tmp = l2->next;
            p->next = l2;
            p = l2;
            l2->next = l1;
            l2 = tmp;
        }
    }
    if (l1)
        p->next = l1;
    else
        p->next = l2;

    remove_duplicates(head);
    return head;
}
List *mergeListDisorder(List *l1, List *l2)
{
    Node *p1 = (Node *)malloc(sizeof(Node));
    Node *p2 = (Node *)malloc(sizeof(Node));
    p1 = l1->next;
    p2 = l2->next;
    Node *Pre = (Node *)malloc(sizeof(Node));
    List *result = (List *)malloc(sizeof(List));
    Node *cur = (Node *)malloc(sizeof(Node));
    Node *newNode = (Node *)malloc(sizeof(Node));

    cur = result;
    while (p1)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->value = p1->value;
        newNode->next = NULL;
        cur->next = newNode;
        cur = newNode;
        p1 = p1->next;
    }
    while (p2)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->value = p2->value;
        newNode->next = NULL;
        cur->next = newNode;
        cur = newNode;
        p2 = p2->next;
    }
    cur = result->next;
    Node *q = (Node *)malloc(sizeof(Node));
    while (cur)
    {
        q = cur->next;
        Pre = cur;
        while (q)
        {
            if (q->value == cur->value)
            {
                Node *tmp = (Node *)malloc(sizeof(Node));
                tmp = q->next;
                Pre->next = q->next;
                q = tmp;
                continue;
            }
            q = q->next;
            Pre = Pre->next;
        }
        cur = cur->next;
    }
    return result;
}
void print_list(List *list)
{
    List *current = list->next;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
void freeList(List **rootp)
{
    List *current = *rootp;

    while (current != NULL)
    {
        rootp = &current->next;
        free(current);
        current = *rootp;
    }
}