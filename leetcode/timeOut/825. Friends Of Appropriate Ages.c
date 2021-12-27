
int numFriendRequests(int *ages, int agesSize)
{
    int *nums = (int *)calloc(121, sizeof(int));
    int reqNum = 0;
    for (int i = 0; i < agesSize; i++)
        nums[ages[i]]++;
    int *visited = (int *)calloc(121, sizeof(int));

    for (int i = 0; i < agesSize; i++)
    {
        for (int j = 0; j < agesSize; j++)
        {
            if (i != j)
            {
                if (ages[i] <= ages[j] / 2 + 7)
                    continue;
                if (ages[i] > ages[j])
                    continue;
                if (ages[i] > 100 && ages[j] < 100)
                    continue;
                if (!visited[ages[j]])
                {
                    reqNum += ages[i] == ages[j] ? nums[ages[j]] - 1 : nums[ages[j]];
                    visited[ages[j]] = 1;
                }
            }
        }
        memset(visited, 0, sizeof(int) * 121);
    }
    int ans = 0;
    ans = reqNum;
    return ans;
}