#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define HashSize 100007

struct list
{
    int key;
    int val;
    struct list *next;
};
typedef struct MyHashMap
{
    struct list *date;
} MyHashMap;
//��ɢ�б��в���
//������
void HashInsert(struct list *head, int key, int val)
{
    struct list *tmp = (struct list *)malloc(sizeof(struct list));
    tmp->key = key;
    tmp->val = val;
    tmp->next = head->next;
    head->next = tmp;
}
struct list *HashFind(struct list *head, int val)
{
    for (struct list *this = head; this->next; this = this->next)
    {
        if (this->next->val == val)
        {
            return this->next;
        }
    }
    return NULL;
}
//����ɢ��(��ʼ��,����Ϊ��)
MyHashMap *CreatHash()
{
    MyHashMap *newhash = (MyHashMap *)malloc(sizeof(MyHashMap));
    newhash->date = malloc(sizeof(struct list) * HashSize);
    for (int i = 0; i < HashSize; i++)
    {
        newhash->date[i].val = 0;
        newhash->date[i].key = 0;
        newhash->date[i].next = NULL;
    }
    return newhash;
}
//ɢ�к���
int hashit(int val)
{
    return fabs(val % HashSize);
}
//�ͷű�
void freehash(struct list *head)
{
    while (head->next)
    {
        struct list *tmp = head->next;
        head->next = tmp->next;
        free(tmp);
    }
}
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *returnIndex = (int *)malloc(sizeof(int) * 2);
    struct MyHashMap *hashmap = CreatHash();
    for (int i = 0; i < numsSize; i++)
    {
        int ID = hashit(target - nums[i]); //ɢ�е�����
        struct list *p = HashFind(&(hashmap->date[ID]), target - nums[i]);
        if (p)
        { //����ɢ�䵽
            returnIndex[0] = p->key;
            returnIndex[1] = i;
            *returnSize = 2;
            return returnIndex;
        }
        else
        {
            ID = hashit(nums[i]);
            HashInsert(&(hashmap->date[ID]), i, nums[i]); //û�в鵽�Ļ�,���Ǳ�ɢ�е���,��ֵɢ�е�ֵ
        }
    }
    *returnSize = 0;
    return NULL;
}