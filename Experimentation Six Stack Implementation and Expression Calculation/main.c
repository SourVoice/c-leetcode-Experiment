#include "postfix_evaluator.h"
#include "prefix_evaluator.h"
#include "infix_evaluator.h"
int main()
{
    char *input = "12+(256*7-1)-10", *output;
    printf("input:%s\n", input);
    if (input)
    {
        printf("postfix evaluator's result:%d\n", postfixEvaluator(input));
        printf("prefix evaluator's result:%d\n", prefixEvaculator(input));
        printf("intix evaluator's result:%d", InfixEvaluation(input));
    }
}
