#define STACK_TYPE int

/*push����ջ*/
void push(STACK_TYPE value);

/*popֵ����ջ,������*/
void pop(void);

/*���ض�ջ����Ԫ��*/
STACK_TYPE top(void);

int is_empty(void); //�յĲ���pop,�շ���TRUE,���򷵻�FALSE

int is_full(void); //���Ĳ���push,������TRUE,���򷵻�FALSE

/*������ջ,ָ����ջ����*/
void creat_stack(size_t size);

/*�ͷŶ�ջ*/
void destory_stack(void);