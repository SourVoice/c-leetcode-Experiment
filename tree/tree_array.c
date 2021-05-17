/*静态数组实现的二叉搜索树*/
#include <assert.h>
#include <stdio.h>
#include "tree_api.h"

#define TREE_SIZE 100 //定义树的元素个数
#define ARRAY_SIZE (TREE_SIZE + 1)

/*储存所有结点的数组*/
static TREE_TYPE tree[ARRAY_SIZE];
/*计算一个结点左孩子的下标*/
static int
left_child(int current)
{
    return current * 2;
}
static int
right_child(int current)
{
    return current * 2 + 1; //右节点大于左
}
/*insert 结点*/
void insert(TREE_TYPE value)
{
    int current;
    assert(value != 0);
    current = 1;
    while (tree[current] != 0)
    {
        if (value < tree[current])
            current = left_child(current);
        else
        {
            assert[value != tree[current]]; //检查重复值
            current = right_child(current);
        }
        assert(current < ARRAY_SIZE);
    }
    tree[current] = value;
}
/*find*/
void find(TREE_TYPE value)
{
    int current;
    current = 1; //从根节点开始、
    while (current < ARRAY_SIZE && tree[current] != value)
    {
        if (value < tree[current])
            current = left_child(current);
        else
            current = right_child(current);
    }
    if (current < ARRAY_SIZE)
        return tree + current;
    else
        return 0;
}
/*执行前序遍历，用于保存当前处理节点的信息，非接口函数*/
static void
do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value))
{
    if (current < ARRAY_SIZE && tree[current] != 0)
    {
        callback(tree[current]);
        do_pre_order_traverse(left_child(current, callback));
        do_pre_order_traverse(right_child(current), callback);
    }
}
/*api函数*/
void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
    do_pre_order_traverse(1, callback);
}