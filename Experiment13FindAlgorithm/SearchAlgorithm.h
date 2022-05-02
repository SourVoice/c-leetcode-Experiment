#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "BST.h"

int binarySearch(int *nums, int numsSize, int target)
{
    int right = numsSize - 1, left = 0;
    int mid = numsSize / 2;
    int *progress;
    int i = 0;
    int flag = 0;
    progress = (int *)malloc(numsSize * sizeof(int));
    while (left <= right)
    {
        mid = left + (right - left) / 2; //��ֹ���(right+left/2��������)
        if (target < nums[mid])
        {
            right = mid - 1;
            progress[i] = nums[mid];
            i++;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
            progress[i] = nums[mid];
            i++;
        }
        else if (nums[mid] == target)
        {
            printf("%d\n", mid);
            progress[i] = nums[mid];
            flag = 1;
            break;
        }
    }
    if (nums[mid] != target)
        printf("no\n");
    for (int j = 0; j < i; j++)
    {
        printf(",%d" + !j, progress[j]);
    }
    if (flag)
        printf(",%d", progress[i]);

    printf("\n%d", mid); // return index
}
int hashWay(int *nums, int numsSize, int target)
{
    int *returnIndex = (int *)malloc(sizeof(int));
    MyHashMap *hashMap = creatHash();
    for (int i = 0; i < numsSize; i++)
    {
        int ID = hashIt(target); //ɢ�е�����
        List *p = hashFind(&(hashMap->data[ID]), target);
        if (p)
        { //����ɢ�䵽
            returnIndex[0] = p->key;
            returnIndex[1] = i;
            return returnIndex;
        }
        else
        {
            ID = hashIt(nums[i]);
            hashInsert(&(hashMap->data[ID]), i, nums[i]); //û�в鵽�Ļ�,���Ǳ�ɢ�е���,��ֵɢ�е�ֵ
        }
    }
    printf("error");
    return 0;
}

void BST(int *data, int numsSize, int target) // Binary Search Tree
{
    struct TreeNode *root = creatBST(data, numsSize);
    root = searchTree(root, target);
}