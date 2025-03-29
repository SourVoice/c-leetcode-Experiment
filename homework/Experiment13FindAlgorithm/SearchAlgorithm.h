#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "BST.h"

int compare_ints(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int binarySearch(int *nums, int numsSize, int target)
{
    int l = 0, r = numsSize - 1;
    qsort(nums, numsSize, sizeof(int), compare_ints);
    int *progress;
    int i = 0;
    int flag = 0;
    progress = (int *)malloc(numsSize * sizeof(int));
    while (l < r)
    {
        int mid = ((r - l) >> 1) + l;
        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    if (nums[l] != target)
    {
        printf("no\n");
        return -1;
    }
    for (int j = 0; j < i; j++)
        printf(",%d" + !j, progress[j]);
    if (flag)
        printf(",%d", progress[i]);

    printf("\nindex: %d", l); // return index
    return l;
}
int *hashWay(int *nums, int numsSize, int target)
{
    int *returnIndex = (int *)malloc(sizeof(int) * 2);
    MyHashMap *hashMap = creatHash();
    for (int i = 0; i < numsSize; i++)
    {
        int ID = hashIt(target); //散列到表中
        List *p = hashFind(&(hashMap->data[ID]), target);
        if (p)
        { //若被散射到
            returnIndex[0] = p->key;
            returnIndex[1] = p->val;
            return returnIndex;
        }
        else
        {
            ID = hashIt(nums[i]);
            hashInsert(&(hashMap->data[ID]), i, nums[i]); //没有查到的话,将角标散列到键,将值散列到值
        }
    }
    printf("error");
    return NULL;
}

void BST(int *data, int numsSize, int target) // Binary Search Tree
{
    struct TreeNode *root = creatBST(data, numsSize);
    root = searchTree(root, target);
}