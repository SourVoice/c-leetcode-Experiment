#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define bool int
#define false 0
#define true 1;

#define MAXSIZE 100001
typedef struct stack
{
    char Parentheses[MAXSIZE];
    int top_index;
} STACK;
STACK *creat_stack();
void push(STACK *, char);
void pop(STACK *, char *);
char top(STACK *);
int is_empty(STACK *);
int is_full(STACK *);
void delete (STACK *);

bool isValid(char *s)
{
    int length_s = strlen(s);
    if (length_s == 1)
    {
        return false;
    }
    STACK *Parenthes_match = creat_stack();
    for (int index_s = 0; s[index_s] != '\0'; index_s++)
    {

        push(Parenthes_match, s[index_s]);
        if (Parenthes_match->top_index == 0) //全部出栈时每次只填一个
            continue;

        char top_one = top(Parenthes_match);
        char beyond_top_one = Parenthes_match->Parentheses[Parenthes_match->top_index - 1];
        if (top_one - beyond_top_one == 2 ||
            top_one - beyond_top_one == 1) //根据ASCII值判断是否匹配
        {
            pop(Parenthes_match, &Parenthes_match->Parentheses[Parenthes_match->top_index]);
            pop(Parenthes_match, &Parenthes_match->Parentheses[Parenthes_match->top_index]); //一次出栈后index自减1,
        }
        if (is_empty(Parenthes_match) && index_s == length_s - 1)
            return true;
    }
    return false;
}

int main(void)
{
    char *s = "(){}";
    isValid(s);
}

/*{[({[]})]}*/
STACK *creat_stack()
{
    STACK *stack;
    stack = (STACK *)malloc(sizeof(STACK));
    stack->top_index = -1;
    return stack;
}

void push(STACK *stack, char element)
{
    assert(!is_full(stack));
    stack->Parentheses[++stack->top_index] = element;
}
void pop(STACK *stack, char *element)
{
    assert(!is_empty(stack));
    *element = stack->Parentheses[stack->top_index--];
}
char top(STACK *stack)
{
    assert(!is_empty(stack));
    return stack->Parentheses[stack->top_index];
}
int is_full(STACK *stack)
{
    return stack->top_index == MAXSIZE - 1;
}
int is_empty(STACK *stack)
{
    return stack->top_index == -1;
}
void delete (STACK *stack)
{
    free(stack);
}