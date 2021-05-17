#ifndef SQSTACK_H_
#define SQSTACK_H_

#define MAXSIZE 32

typedef struct
{
    int data[MAXSIZE];
    int top_index;
} sqstack; //ջ�ṹ

sqstack *sqstack_creat();
int sqstack_push(sqstack *, int);  //��ջ
int sqstack_pop(sqstack *, int *); //��ջ
int sqstack_top(sqstack *, int *); //ջ����¼
int is_empty(sqstack *);           //���Կ�ջ
int is_full(sqstack *);            //�������
void sqstack_display(sqstack *);
#endif