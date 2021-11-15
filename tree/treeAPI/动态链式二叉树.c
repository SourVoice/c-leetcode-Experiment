#include "tree_api.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

typedef struct TREE_NODE
{
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} TreeNode;
/*����ָ�������ڵ��*/
static TreeNode *tree;
void insert(TREE_TYPE value)
{
    TreeNode *current;
    TreeNode **link;
    link = &tree;
    while ((current = *link) != NULL)
    {
        /*ѡ������*/
        if (value < current->value)
            link = &current->left; //������ڵ�
        else
        {
            assert(value != current->value);
            link = &current->right;
        }
    }
    /*ʹlinkָ�������*/
    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}
TREE_TYPE *
find(TREE_TYPE value)
{
    TreeNode *current;
    current = tree;
    while (current != NULL && current->value != value)
    {
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }
    if (current != NULL)
        return &current->value;
    else
        return NULL;
}