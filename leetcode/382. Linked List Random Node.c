// 382. 链表随机节点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//链中元素存入solution arr再进行arr_index抽取
struct ListNode
{
    int val;
    struct ListNode *next;
};
typedef struct
{
    int *arr;
    int capacity;
} Solution;

Solution *solutionCreate(struct ListNode *head)
{
    Solution *newSolution = (Solution *)malloc(sizeof(Solution));
    newSolution->capacity = 0;
    struct ListNode *node = head;
    while (head)
    {
        newSolution->capacity++;
        head = head->next;
    }
    newSolution->arr = (int *)calloc(newSolution->capacity, sizeof(int));
    for (int i = 0; i < newSolution->capacity; i++)
    {
        newSolution->arr[i] = node->val;
        node = node->next;
    }
    return newSolution;
}

int solutionGetRandom(Solution *obj)
{
    return obj->arr[rand() % obj->capacity];
}

void solutionFree(Solution *obj)
{
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);

 * solutionFree(obj);
*/

// solution2:水塘抽样
typedef struct
{
    struct ListNode *head;
} Solution;
Solution *solutionCreate(struct ListNode *head)
{
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->head = head;
    return obj;
}
int solutionGetRandom(Solution *obj)
{

    int i = 1, ans = 0;
    for (struct ListNode *node = obj->head; node; node = node->next)
    {
        if (rand() % i == 0)
        {
            ans = node->val;
        }
        i++;
    }
    return ans;
}
void solutionFree(Solution *obj)
{
    free(obj);
}