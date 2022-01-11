/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char table[11][5] = {"\0", "\0", "abc\0", "def\0", "ghi\0", "jkl\0", "mno\0", "pqrs\0", "tuv\0", "wxyz\0"};
char **letterCombinations(char *digits, int *returnSize)
{
    int digitsLen = strlen(digits);
    *returnSize = 0;
    char **ans = (char **)malloc(sizeof(char *) * 1000);
    for (int i = 0; i < 1000; i++)
        ans[i] = (char *)calloc(1000, sizeof(char));
    if (digitsLen == 0)
        return ans;
    char *temp = (char *)calloc(1000, sizeof(char));
    dfs(digits, 0, ans, returnSize, 0, temp);
    return ans;
}

void dfs(char *digits, int cur, char **ans, int *returnSize, int tempPos, char *temp)
{
    int size = strlen(digits);
    if (cur == size)
    {
        strcpy(ans[(*returnSize)++], temp);
        return;
    }
    int tableSize = strlen(table[digits[cur] - '0']);
    for (int i = 0; i < tableSize; i++)
    {
        temp[tempPos] = table[digits[cur] - '0'][i];
        dfs(digits, cur + 1, ans, returnSize, tempPos + 1, temp);
    }
}