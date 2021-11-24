#include <stdlib.h>
typedef struct
{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
} HTcode, *HuffmanTree;
typedef char **HuffmanCode;

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
    int i, j, m, s1, s2, start;
    char *cd;
    unsigned int c, f;
    if (n <= 1)
        return;
    m = 2 * n - 1;
    HT = (HuffmanCode)malloc((m + 1) * sizeof(HTNode));
    for (;;)
    {
    }
}