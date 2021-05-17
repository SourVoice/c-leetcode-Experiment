#ifndef SQSTACK_H_
#define SQSTACK_H_

#define MAXSIZE 32

typedef struct
{
    int data[MAXSIZE];
    int top_index;
} sqstack; //Õ»½á¹¹

sqstack *sqstack_creat();
int sqstack_push(sqstack *, int);  //ÈëÕ»
int sqstack_pop(sqstack *, int *); //³öÕ»
int sqstack_top(sqstack *, int *); //Õ»¶¥¼ÇÂ¼
int is_empty(sqstack *);           //¶ÏÑÔ¿ÕÕ»
int is_full(sqstack *);            //¶ÏÑÔÒç³ö
void sqstack_display(sqstack *);
#endif