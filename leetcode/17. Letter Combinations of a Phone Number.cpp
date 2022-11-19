// 17. 电话号码的字母组合
//哈希+回溯
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    string table[10] = {"", "", "abc",
                        "def", "ghi", "jkl",
                        "mno", "pqrs", "tuv",
                        "wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return ans;
        dfs(digits, 0, string());
        return ans;
    }
    void dfs(string dig, int cur, string temp)
    {
        int digSize = (int)dig.size();
        if (cur == digSize)
        {
            ans.push_back(temp);
            return;
        }
        for (auto ch : table[dig[cur] - '0'])
            dfs(dig, cur + 1, temp + string{ch});
    }
};
// 二刷
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        string gen = "";
        if (digits.empty())
            return ans;
        dfs(digits, gen, 0);
        return ans;
    }
    void dfs(string digits, string &gen, int index)
    {
        if (gen.size() == digits.size())
        {
            ans.push_back(gen);
            return;
        }
        for (int i = 0; i < table[digits[index] - '0'].size(); i++)
        {
            gen.push_back(table[digits[index] - '0'][i]);
            dfs(digits, gen, index + 1);
            gen.pop_back();
        }
    }

private:
    vector<string> ans;
    string table[10] = {"", "", "abc",
                        "def", "ghi", "jkl",
                        "mno", "pqrs", "tuv",
                        "wxyz"};
};
// c语言解法
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char table[11][7] = {"\0", "\0", "abc\0", "def\0", "ghi\0", "jkl\0", "mno\0", "pqrs\0", "tuv\0", "wxyz\0"};
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