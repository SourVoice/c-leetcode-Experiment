/*ǰ׺*/

#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "judgeFunction.h"
void reverse(const char *input, char *output)
{
	const char *strstart = input, *strpos = input + (strlen(input) - 1);
	char *outpos = output;
	int k = 0;
	char c;
	while (strstart <= strpos)
	{
		c = *strpos;
		if (c != ' ')
		{
			if (is_ident(c))
			{
				if ((strstart != strpos) && is_ident(*(strpos - 1)))
				{
					k++;
					strpos--;
					continue;
				}
				else
				{
					for (int index = 0; index <= k; index++)
					{
						c = *(strpos + index);
						*outpos = c;
						++outpos;
					}
					k = 0;
				}
				*outpos = ' ';
				++outpos;
			}
			else
			{
				*outpos = c;
				++outpos;

				*outpos = ' ';
				++outpos;
			}
		}
		strpos--;
	}
	*outpos = '\0';
}
int infix_to_prefix(const char *infix, char *output)
{
	int i = 0, j = 0;
	char *input = (char *)malloc(sizeof(infix)), c;
	strcpy(input, infix);
	/*reverse*/
	char *reinfix = (char *)malloc(2 * sizeof(infix));
	reverse(input, reinfix);
	// Reverse the infix expression
	strcpy(input, reinfix);
	char *strpos = input;
	char stack[32], *prefix = (char *)malloc(sizeof(reinfix)); //stack for operator
	while (*strpos != '\0')
	{
		c = *strpos;
		if (c != ' ')
		{
			// if an alphabet is found then copy it to the output string
			if (is_ident(c))
			{
				if (is_ident(*(strpos + 1)))
				{
					prefix[j] = c;
					j++;
					++strpos;
					continue;
				}
				prefix[j] = c;
				j++;

				prefix[j] = ' ';
				j++;
			}
			// In the reversed string, closing bracket will be found first so put it in the stack
			else if (c == ')')
			{
				push(stack, c);
			}
			// if an opening bracket is found, then
			else if (c == '(') /* when closing bracket is                             found */
			{
				if (c == '(')
				{
					while (Top(stack) != ')') /* pop till opening bracket is found */
					{
						prefix[j] = pop(stack);
						j++;

						prefix[j] = ' ';
						j++;
					}
					pop(stack);
				}
			}
			else
			{
				// if the stack if empty, then we simply put the operator in stack
				if (top == -1)
				{
					push(stack, c);
				}
				// if the precedence of operator is less than the stack top then
				else if (op_preced(c) < op_preced(stack[top]))
				{
					prefix[j] = pop(stack); // pop the stack top and add it to the prefix string
					j++;

					prefix[j] = ' ';
					j++;
					// if you have an operator that has precedence greater than operator
					while (op_preced(stack[top]) > op_preced(c))
					{
						prefix[j] = pop(stack); // Pop the operator
						j++;

						prefix[j] = ' ';
						j++;
						if (top < 0)
						{
							break;
						}
					}
					push(stack, c);
				}
				// if the precedence of operator is greater than or equal to the stack top
				else if (op_preced(c) >= op_preced(stack[top]))
				{
					push(stack, c); // Push it onto the stack
				}
			}
		}
		++strpos;
	}
	// At the end remove all the operators from the stack
	while (top != -1)
	{
		prefix[j] = pop(stack);
		j++;

		prefix[j] = ' ';
		j++;
	}
	prefix[j] = '\0';
	// Reverse the final string before output
	reverse(prefix, output);
	printf("EQUIVALENT PREFIX NOTATION : %s \n", output);
}

int prefixEvaluator(const char *prefix)
{
	char *output = (char *)malloc(sizeof(prefix));
	reverse(prefix, output);
	const char *strpos = output, *strend = output + strlen(output);
	int numstack[128];
	int sl; /*stack length*/
	char c;
	int num = 0;
	while (*strpos != '\0')
	{
		c = *strpos;
		if (c != ' ')
		{
			if (is_ident(c))
			{
				num = num + (c - '0');
				if (is_ident(*(strpos + 1)))
				{
					num *= 10;
				}
				else
				{
					numstack[sl] = num;
					++sl;
					num = 0;
				}
			}
			else if (is_operator(c))
			{
				int leftop = numstack[--sl];
				int rightop = numstack[--sl];
				switch (c)
				{
				case '+':
					numstack[sl++] = leftop + rightop;
					break;
				case '-':
					numstack[sl++] = leftop - rightop;
					break;
				case '*':
					numstack[sl++] = leftop * rightop;
					break;
				case '/':
					numstack[sl++] = leftop / rightop;
					break;
				default:
					printf("wrong operator");
					break;
				}
			}
		}
		++strpos;
	}
	return numstack[0];
}
int main()
{
	char *input = "12+(256*7-1)-10", *output;
	printf("input:%s\n", input);
	if (infix_to_prefix(input, output))
	{
		printf("output:%s\n", output);
		printf("result:%d", prefixEvaluator(output));
	}
	return 0;
}
