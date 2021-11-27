/*Ëæ»ú·´×ª¾ØÕó*/
typedef struct
{
    long *rec;
} Hash_table;
int first = 1;
typedef struct
{
    int row;
    int col;
    int **matrix;
    Hash_table hashTable;
} Solution;

Solution *solutionCreate(int m, int n)
{
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->row = m;
    obj->col = n;
    obj->hashTable.rec = (long *)malloc(sizeof(long) * m * n);
    for (int i = 0; i < obj->row * obj->col; i++)
    {
        obj->hashTable.rec[i] = 0;
    }
    return obj;
}

int *solutionFlip(Solution *obj, int *retSize)
{
    *retSize = 2;
    int *ans = (int *)malloc(sizeof(int) * 2);
    int i, j;
    if (first == 1)
    {
        i = rand() % obj->row;
        j = rand() % obj->col;
        obj->hashTable.rec[i * obj->col + j] = 1;
    }
    else
    {
        do
        {
            i = rand() % obj->row;
            j = rand() % obj->col;
            // printf("i = %d,j = %d %d\n",i,j,obj->hashTable.rec[i * obj->col + j]);
        } while (obj->hashTable.rec[i * obj->col + j]);
        obj->hashTable.rec[i * obj->col + j] = 1;
    }
    ans[0] = i;
    first++;
    ans[1] = j;
    return ans;
}

void solutionReset(Solution *obj)
{
    first = 0;
    for (int i = 0; i < obj->row * obj->col; i++)
    {
        obj->hashTable.rec[i] = 0;
    }
}

void solutionFree(Solution *obj)
{
    free(obj);
}
//         testcase: 17/20
/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(m, n);
 * int* param_1 = solutionFlip(obj, retSize);
 
 * solutionReset(obj);
 
 * solutionFree(obj);
*/