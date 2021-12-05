#include <stdio.h>
#include <string.h>
#include "HuffmanByMinHeap.h"
#include "BuildHuffmanTreeByHeap.h"
#include "decodeHuffman.h"
int main()
{
    struct MinHeapNode *root;
    printf("input the letter you want to Code,and input the frequence of the letters you have just input inorder:\n");
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    root = HuffmanCodes(arr, freq, size);

    printf("input numbers in the encode type above:\n");
    char *encode = (char *)malloc(sizeof(char) * 10000);
    scanf("%[^\n]%*c", encode);
    printf("what you just input has been decoded:\n");
    int len = strlen(encode) - 1;
    int index = -1;
    while (index < len)
    {
        index = decodeFunc(index, encode, root);
    }
    return 0;
}
