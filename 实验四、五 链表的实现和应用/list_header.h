#include <malloc.h>
#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 500
typedef struct _node
{
    int value; //ϵ��
    int n;     //ָ��
    struct _node *next;
} List, Node;
typedef struct _polyTable
{
    List poly[MAXSIZE];
} Table;

List *
creat_list(int total_elements)
{
    List *head;
    head = (List *)malloc(sizeof(List));
    List *current = head;
    List *newNode = NULL;
    printf("��������Ԫ�أ�");
    for (int i = 0; i < total_elements; i++)
    {
        newNode = (List *)malloc(sizeof(List));
        if (newNode == NULL)
            return NULL;
        scanf("%d", &newNode->value);
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    return head->next;
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
    while (scanf("%d%d", &value, &n) != EOF)
    {

        //scanf("%d %d", &newNode->value, &newNode->n)
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL)
            return;
        newNode->value = value;
        newNode->n = n;
        newNode->next = NULL;
        current = L; //��ͷ��ʼ

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
            current = L; //��ͷ��ʼ
            continue;
        }
    }
}
void bubleSortPoly(List *L) //�����ڵ��ð������
{
    Node *p = (Node *)malloc(sizeof(Node));
    Node *head = (Node *)malloc(sizeof(Node));
    head = L;
    Node *tail = (Node *)malloc(sizeof(Node));
    Node *q = (Node *)malloc(sizeof(Node));
    for (tail = NULL; head->next != tail; tail = p)
    {
        p = head; //ÿ��ѭ����ͷ��ʼ(p����ָ���һ�����)
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

            p = p->next;
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

    //    p2 = poly2->next;//poly2��ͷ��ʼ�ж�
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
            printf("+");
            printf("%d", abs(L->next->value));
        }
        else
            continue;
        printf("X^%d", L->next->n);
        L = L->next;
    }
}
int insert_by_value(List *current, int new_value) //���µĽ����Ϣ���ݽ�����
{
    List *previous = (List *)malloc(sizeof(List));
    List *newNode;
    while (current != NULL && current->value < new_value) //previousָ��С��current����һ�����,������ǰ�ƶ�
    {
        previous = current;
        current = current->next;
    }

    newNode = (List *)malloc(sizeof(List));
    if (newNode == NULL) //����ʧ��
        return FALSE;
    /*��û�иı�ṹ���ڴ�,�����Ǵ�����һ����ָ��,��previous�Ľ������ִ��new���,new���Link��ָ����һ�������Ľ��*/
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
void bubleSortList(List *L) //�����ڵ��ð������
{
    Node *p = (Node *)malloc(sizeof(Node));
    Node *head = (Node *)malloc(sizeof(Node));
    head = L;
    Node *tail = (Node *)malloc(sizeof(Node));
    Node *q = (Node *)malloc(sizeof(Node));
    for (tail = NULL; head->next != tail; tail = p)
    {
        p = head; //ÿ��ѭ����ͷ��ʼ(p����ָ���һ�����)
        q = p->next;
        for (; p->next != tail;)
        {
            if (p->value > q->next->value)
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
                pre->next = current->next;
                free(current);
                current = pre->next;
                continue;
            }
            pre = current;
            current = current->next;
        }
        p = p->next;
    }
}

List *mergeTwoLists(List *l1, List *l2)
{
    bubleSortList(l1);
    bubleSortList(l2);
    Node *p = (Node *)malloc(sizeof(Node));
    Node *head = (Node *)malloc(sizeof(Node));
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
    return head->next;
}

void print_list(List *list)
{
    List *current = list;
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