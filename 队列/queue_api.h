#include <stdlib.h>
#define QUEUE_TYPE int /*����Ԫ������*/

/*����һ������, ����ָ�����пɴ洢�����Ԫ�ظ���*/
void create_queue(size_t size);
/*����һ������*/
void destory_queue(void);
/*���*/
void insert(QUEUE_TYPE value);
/*ɾ��һ��Ԫ��*/
void delet(void);
/*����Ϊ��*/
int is_empty(void);
/*��������*/
int is_full(void);