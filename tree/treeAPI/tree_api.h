#define TREE_TYPE int
/*�������ڵ�*/
void insert(TREE_TYPE value);
/*�����ض�ֵ�����ؽ��*/
TREE_TYPE *find(TREE_TYPE value);
/*ִ�б���������Ϊ�ص�����ָ�룬��ÿ�������ã����ֵ��Ϊ�������ݸ�����*/
void pre_order_traverse(void (*callback)(TREE_TYPE value))
