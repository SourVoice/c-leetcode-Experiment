#include <stdlib.h>
#define QUEUE_TYPE int /*队列元素类型*/

/*创建一个队列, 参数指定队列可存储的最大元素个数*/
void create_queue(size_t size);
/*销毁一个队列*/
void destory_queue(void);
/*插队*/
void insert(QUEUE_TYPE value);
/*删除一个元素*/
void delet(void);
/*队列为空*/
int is_empty(void);
/*队列已满*/
int is_full(void);