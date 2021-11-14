typedef struct
{
    int *value; //¼üÏÂ±ê
    char **key;
    int n;
} MapSum;

MapSum *mapSumCreat()
{
    MapSum *obj = (MapSum *)malloc(sizeof(MapSum));
    obj->key = (char **)malloc(sizeof(char *) * 50);
    obj->value = (int *)malloc(sizeof(int) * 50);
    obj->n = 0;
    return obj;
}
void mapSumInsert(MapSum *obj, char *key, int val)
{
    for (int i = 0; i < obj->n; i++)
    {
        if (strcmp(obj->key[i], key) == 0)
        {
            obj->value[i] = val;
            return;
        }
    }
    //×·¼Ó  key-val
    int l = strlen(key);
    obj->key[obj->n] = (char *)malloc(sizeof(char) * (l + 1));
    strcpy(obj->key[obj->n], key);
    obj->value[obj->n] = val;
    obj->n++;
}
int mapSumSum(MapSum *obj, char *prefix)
{
    int l = strlen(prefix), sum = 0;
    for (int i = 0; i < obj->n; i++)
    {
        int flag = 1;
        for (int j = 0; j < l; j++)
        {
            if (obj->key[i][j] != prefix[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            sum += obj->value[i];
    }
    return sum;
}

void mapSumFree(MapSum *obj)
{
    for (int i = 0; i < obj->n; i++)
    {
        free(obj->key[i]);
    }
    free(obj->key);
    free(obj->value);
    free(obj);
}