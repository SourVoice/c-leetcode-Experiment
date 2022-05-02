#define HashSize 100007

typedef struct list
{
    int key;
    int val;
    struct list *next;
} List;
typedef struct MyHashMap
{
    List *data;
} MyHashMap;
//��ɢ�б��в���
//������
void hashInsert(List *head, int key, int val)
{
    List *tmpList = (List *)malloc(sizeof(List));
    tmpList->key = key;
    tmpList->val = val;
    tmpList->next = head->next;
    head->next = tmpList;
}
List *hashFind(List *head, int val)
{
    for (List *this = head; this->next; this = this->next)
    {
        if (this->next->val == val)
        {
            return this->next;
        }
    }
    return NULL;
}
//����ɢ��(��ʼ��,����Ϊ��)
MyHashMap *creatHash()
{
    MyHashMap *newhash = (MyHashMap *)malloc(sizeof(MyHashMap));
    newhash->data = malloc(sizeof(List) * HashSize);
    for (int i = 0; i < HashSize; i++)
    {
        newhash->data[i].val = 0;
        newhash->data[i].key = 0;
        newhash->data[i].next = NULL;
    }
    return newhash;
}
//ɢ�к���
int hashIt(int val)
{
    return fabs(val % HashSize);
}
//�ͷű�
void freeHash(List *head)
{
    while (head->next)
    {
        struct list *tmp = head->next;
        head->next = tmp->next;
        free(tmp);
    }
}
