#include <stdio.h>
#include <stdlib.h>

//#include "sll_node.h"

#define FALSE 0
#define TRUE 1

typedef struct NODE
{
	struct NODE *link;
	int value;
} Node;

int sll_insert(Node *current, int new_value) //将新的结点信息传递进函数
{
	Node *previous;
	Node *new;
	while (current != NULL & current->value < new_value) //previous指向小于current的上一个结点,不断向前移动
	{
		previous = current;
		current = current->link;
	}

	new = (Node *)malloc(sizeof(Node));
	if (new == NULL) //没有找到合适的结点
		return FALSE;
	/*并没有改变结构体内存,仅仅是创建了一个新指针,从previous的结点跳出执行new结点,new里的link再指向下一个＞它的结点*/
	new->value = new_value;
	new->link = current;
	previous->link = new;
	return TRUE;
}
int main()
{
	Node *next = NULL;
	Node *p = NULL;
	for (int i = 0; i < 3; i++)
	{
		next = (Node *)malloc(sizeof(Node));
		scanf("%d", &next->value);
		next->link = NULL;
		p->link = next;
		p = next;
	}
	Node *head = NULL;
	head = p;
	return 0;
}