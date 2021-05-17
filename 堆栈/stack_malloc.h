#define STACK_TYPE int

/*push进堆栈*/
void push(STACK_TYPE value);

/*pop值出堆栈,并丢弃*/
void pop(void);

/*返回堆栈顶部元素*/
STACK_TYPE top(void);

int is_empty(void); //空的不能pop,空返回TRUE,否则返回FALSE

int is_full(void); //满的不能push,满返回TRUE,否则返回FALSE

/*创建堆栈,指定堆栈长度*/
void creat_stack(size_t size);

/*释放堆栈*/
void destory_stack(void);