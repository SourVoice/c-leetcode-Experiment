/*ʹ�þ�̬����ʵ�ַ��͵Ķ�ջ�����鳤����Ϊʵ����ʱ�Ĳ���*/
#include <assert.h>

#define GENERIC_STACK(STACK_TYPE, SUFFIX, STACK_SIZE)
static STACK_TYPE stack##SUFFIX[STACK_SIZE];
stacic int top_ekement##SUFFIX = -1;
int
    is_empty##SUFFIX(void)
{
    return top_element##SUFFIX == STACK_ + SIZE - 1;
}
