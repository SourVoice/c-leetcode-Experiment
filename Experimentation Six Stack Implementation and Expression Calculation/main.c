#include "postfix_evaluator.h"
int main()
{
    char *input = "12+(256*7-1)-10", *output;
    printf("input:%s\n", input);
    if (shunting_yard(input, output))
    {
        printf("output:%s\n", output);
        printf("result:%d", postfixEvaluator(output));
    }
}