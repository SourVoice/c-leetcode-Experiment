/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int *decode(int *encoded, int encodedSize, int *returnSize)
{
    int *perm = (int *)malloc(sizeof(int) * (encodedSize + 1));
    // int *after_xor = (int*)malloc(sizeof(int)*encodedSize);
    int all_xor = 0;
    for (int i = 1; i <= encodedSize; i++)
    {
        all_xor = all_xor ^ (i + 1);
    }
    for (int i = 1; i < encodedSize; i += 2)
    {
        all_xor = all_xor ^ encoded[i];
    }
    int first_perm = all_xor;
    perm[0] = first_perm;
    int next_perm = 0;
    for (int i = 1; i <= encodedSize; i++)
    {
        perm[i] = perm[i - 1] ^ encoded[i - 1];
    }
    return perm;
}
void printdecode();
int main(void)
{
    int encode[4] = {1, 2, 3, 4};

    decode(encode, 4, 0);
}