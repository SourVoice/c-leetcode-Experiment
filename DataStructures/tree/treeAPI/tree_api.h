#define TREE_TYPE int
/*新添树节点*/
void insert(TREE_TYPE value);
/*查找特定值，返回结点*/
TREE_TYPE *find(TREE_TYPE value);
/*执行遍历，参数为回调函数指针，被每个结点调用，结点值作为参数传递给函数*/
void pre_order_traverse(void (*callback)(TREE_TYPE value))
