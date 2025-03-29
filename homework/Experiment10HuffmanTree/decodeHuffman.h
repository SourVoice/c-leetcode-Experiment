#include <stdio.h>
#include "HuffmanByMinHeap.h"
#include "BuildHuffmanTreeByHeap.h"
int decodeFunc(int index, char *ch, struct MinHeapNode *root)
{
    if (!root)
    {
        return index;
    }
    if (isLeaf(root))
    {
        printf("%c", root->data);
        return index;
    }
    index++;

    root = (ch[index] == '0') ? root->left : root->right;
    decodeFunc(index, ch, root);
}